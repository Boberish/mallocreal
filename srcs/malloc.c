/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:16:57 by jaylor            #+#    #+#             */
/*   Updated: 2018/10/17 19:46:23 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_holder *holder_head = NULL;

void    *ft_malloc(size_t size)
{
    if (size == 0)
        return (NULL);
    if (holder_head == NULL)
    {
        if (init_holder() == NULL)
            return (NULL);
    }
    return (check_size(size));
}

void    *init_holder()
{
    holder_head = new_mmap(sizeof(holder_head), 'l');
    if (holder_head == NULL)
        return (NULL);
    holder_head->tiny = NULL;
    holder_head->small = NULL;
    holder_head->large = NULL;
    holder_head->j = 0;
    return ((void*)1);
}

void    *new_mmap(size_t size, char letter)
{
    void    *mmap_hold;

    mmap_hold = mmap(NULL, get_optimal_size(size, letter), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0);
    if (mmap_hold == MAP_FAILED)
        return (NULL);
    return (mmap_hold);

}

void    *check_size(size_t size)
{
    if (size <= TINY)
    {
        if (holder_head->tiny == NULL)
            init_pages(size, &(holder_head->tiny));
        return ((holder_head->tiny == NULL) ? NULL : check_space(size, holder_head->tiny));
    }
    else if (size <= SMALL)
    {
        if (holder_head->small == NULL)
            init_pages(size, &(holder_head->small));
        return ((holder_head->small == NULL) ? NULL : check_space(size, holder_head->small));
    }
    else
    {
        if (holder_head->large == NULL)
            init_large_page(size, &(holder_head->large));
        return ((holder_head->large == NULL) ? NULL : large_malloc(size, holder_head->large));
    }
    return (NULL);//check, just added to remove warning
}

void    *init_large_page(size_t size, t_pages **head)
{
    t_pages *real;
   
    *head = new_mmap(size + sizeof(t_pages), 'l');
    if (*head == NULL)
        return (NULL);
    real = *head;
    real->head = (t_base_node *)((void *)real + sizeof(t_pages));
    real->head->is_free = 1;
    real->head->size = size;
    real->next = NULL;
    return ((void*)1);
}

void    *large_malloc(size_t size, t_pages *head)
{
    t_pages *curr_p;

    curr_p = head;
    while (curr_p)
    {
        if (curr_p->head->is_free == 1 && curr_p->head->size >= size)
            {
                curr_p->head->is_free = 0;
                return (curr_p->head); // make sure head is set when make new large page.
            }
        if (curr_p->next == NULL)
            break;    
        curr_p = curr_p->next;     
    }
    curr_p->next = new_mmap(size + sizeof(t_pages), 'l');
    if (curr_p->next == NULL)
        return (NULL);
    curr_p = curr_p->next;
    curr_p->head = (t_base_node *)((void *)curr_p + sizeof(t_pages));
    curr_p->head->is_free = 0;
    curr_p->head->size = size;
    curr_p->next = NULL;
    return (curr_p->head);
}

void    *init_pages(size_t size, t_pages **head)
{
    t_pages *real;
   
    *head = new_mmap(size, 's');
    if (*head == NULL)
        return (NULL);
    real = *head;
    real->head = (t_base_node *)((void *)real + sizeof(t_pages));
    real->head->next = NULL;
    real->head->is_free = 1;
    real->head->size = (size <= TINY) ? TINY : SMALL;
    real->aval_mem = get_optimal_size(size, 's') - sizeof(t_pages);
    real->free_count = 0;
    real->next = NULL;
    return ((void*)1);
}

void    *check_space(size_t size, t_pages *head)
{
    t_pages *current_page;
    
    current_page = head;
    while (current_page)
    {
        if (current_page->free_count > 0 && check_between_nodes(current_page, size) == 1)
            return (find_spot(current_page, size));
        else if (current_page->aval_mem >= (size + sizeof(t_base_node)))
            return (find_spot(current_page, size));
        if (current_page->next == NULL)
            break;
        current_page = current_page->next;
    }
    return (add_node_pages(current_page, size));
}

void    *add_node_pages(t_pages *current_page, int size)
{
        current_page->next = new_mmap(size, 's');
        if (current_page->next == NULL)
            return (NULL);
        current_page = current_page->next;
        current_page->aval_mem = get_optimal_size(size, 's') - sizeof(t_pages);
        current_page->head = (t_base_node *)((void *)current_page + sizeof(t_pages));
        // current_page->head = (t_pages *)current_page + 1;
        current_page->free_count = 0;
        current_page->head->is_free = 1;
        current_page->head->size = (size <= TINY) ? TINY : SMALL;
        current_page->head->next = NULL;
        current_page->next = NULL;
        return (find_spot(current_page, size));
}

void *find_spot(t_pages *current_page, int size)
{
    t_base_node *malloc_node;

    malloc_node = current_page->head;
    while (malloc_node)
    {
        if (malloc_node->is_free == 1 && size <= malloc_node->size)
            return (do_malloc(current_page,malloc_node, size));
        malloc_node = malloc_node->next;
    }
    return (NULL);
}

void *do_malloc(t_pages *curr_p, t_base_node *node, int size)
{
    void        *final;

    node->is_free = 0;
    node->size = size;
    curr_p->aval_mem -= size + sizeof(t_base_node);
    // malloc_node->mem = malloc_node + 1;
    final = (void *)node + sizeof(t_base_node);
    node->next = final + size;
    node = node->next;
    node->is_free = 1;
    node->size = (size <= TINY) ? TINY : SMALL;
    node->next = NULL;
    
    return (final);
}

char    check_between_nodes(t_pages *curr_p, size_t size)
{
    t_base_node *node;

    node = curr_p->head;
    while (node)
    {
        if (node->is_free == 1 && size <= node->size)
            return (1);
        node = node->next;
    }
    return (0);
}

size_t		get_optimal_size(size_t chunk_size, char letter)
{
	size_t initial;
    size_t shit;

    if (letter == 's')
    {
        initial = chunk_size * MALLOC_PER_PAGE;
        initial += sizeof(t_base_node) * MALLOC_PER_PAGE + sizeof(t_pages);
        shit = ((size_t)(initial / getpagesize()) + 1) * getpagesize();
        return (shit);
    }
    else
        return ((size_t)((chunk_size + sizeof(t_pages)) / getpagesize()) + 1) * getpagesize();
}


int main()
{
    // printf("base node: %d, t_pages: %d", sizeof(t_base_node), sizeof(t_pages));
    // printf("%d",getpagesize());
    int i = 0;
    void **hold;
    int nb_malloc = 4;

    hold = malloc(sizeof(*hold) * nb_malloc);
    // while (i < 150)
    // {
    //     hold[i] = ft_malloc(1000);
    //     i++;
    //     // printf("%d ",i);
    // }
    // while (i < 210)
    // {
    //     hold[i] = ft_malloc(60);
    //     i++;
    // }
    while (i < nb_malloc)
    {
        hold[i] = ft_malloc(10000);
        ft_free(hold[0]);
        ft_malloc(10000);
        return (1);
        i++;
    }
    // ft_free(hold[140]);
   
    // // print_ll(0);
    show_alloc_mem();
    // printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    // i = 0;
    // while (i < nb_malloc)
    // {
    //     ft_free(hold[i]);
    //     i++;
    // }
    ft_free(hold[0]);
    ft_free(hold[1]);
    ft_free(hold[2]);
    show_alloc_mem();
    // printf("--------\n");
    return (0);
    
}




