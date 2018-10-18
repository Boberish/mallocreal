/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:16:57 by jaylor            #+#    #+#             */
/*   Updated: 2018/10/18 18:35:57 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

// void    free(void *ptr)
void    ft_free(void *ptr)
{
    if (!holder_head || ptr == NULL)
        return ;
    if (holder_head->tiny)
    {
        if (search_not_large(ptr, holder_head->tiny) == NULL)
            return ;
    }
    if (holder_head->small)
    {
        if (search_not_large(ptr, holder_head->small) == NULL)
            return ;
    }
    if (holder_head->large)
    {
        if (search_large(ptr, holder_head->large) == NULL)
            return ;
    }
    // printf("didnt find %p", ptr);

}

void    *search_large(void *ptr, t_pages *head)
{
    t_pages *curr_p;
    t_pages *prev_p;
    int     mun_ret;

    curr_p = head;
    prev_p = head;
    while (curr_p)
    {
        if (ptr == curr_p->head)
        {
            curr_p->head->is_free = 1;
            if (curr_p == prev_p)
                return (NULL);
            else
            {
                prev_p->next = curr_p->next;
                mun_ret = munmap(curr_p, curr_p->head->size);
                return (NULL);
            }       
        }
        prev_p = curr_p;
        curr_p = curr_p->next;
    }
    return ((void*)1);
}

void    *search_not_large(void *ptr, t_pages *head)
{
    t_pages *curr_p;
    t_pages *prev_p;
    int     size_of_page;
    
    curr_p = head;
    prev_p = head;
    size_of_page = (curr_p == holder_head->tiny) ? get_optimal_size(TINY, 's') : get_optimal_size(SMALL, 's');    
    while (curr_p)
    {
        if ((long)ptr >= (long)curr_p && (long)ptr < size_of_page + (long)curr_p)
        {
                find_node(ptr, curr_p, size_of_page, prev_p);
                return (NULL);
        }
        prev_p = curr_p;
        curr_p = curr_p->next;
    }
    return ((void*)1);
}

void    find_node(void *ptr, t_pages *curr_p, int size_of_page, t_pages *prev_p)
{
    t_base_node *curr_n;
    int    bool_free;
    int     mun_ret;

    bool_free = 1;
    curr_n = curr_p->head;
    while (curr_n)
    {
        if ((void*)curr_n + sizeof(t_base_node) == ptr)
           { 
            //    printf("%d ", holder_head->j);
                holder_head->j += 1;
               curr_n->is_free = 1;
               curr_p->free_count += 1;
           }
        if(curr_n->is_free == 0)
             bool_free = 0;
        curr_n = curr_n->next;
    }
    if(bool_free == 1)
    {
        if (curr_p != prev_p)
        {//if ((void*)curr_p - sizeof(t_pages) != holder_head->tiny && (void*)curr_p - sizeof(t_pages) != holder_head->small)
            prev_p->next = curr_p->next;
            mun_ret = munmap((void*)curr_p ,size_of_page);
        }
    }
}


