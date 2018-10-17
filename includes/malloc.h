/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:10:04 by jaylor            #+#    #+#             */
/*   Updated: 2018/10/17 17:56:55 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include "../libft/includes/libft.h"
# include "stdio.h"

# define TINY 64
# define SMALL 1064
# define MALLOC_PER_PAGE 100


typedef struct  		s_base_node{
    size_t              size;
	char        		is_free;
	struct s_base_node	*next;
}               		t_base_node;

typedef struct			s_pages{
	struct s_base_node 	*head;
	size_t 				aval_mem;
	int					free_count;
	struct s_pages 	    *next;
}						t_pages;

typedef struct  		s_holder{
	struct s_pages  *tiny;
	struct s_pages  *small;
	struct s_pages  *large;
	int				j;
}               		t_holder;

t_holder *holder_head;
//malloc.c
void    *init_holder();
void    *init_pages(size_t size, t_pages **head);
void    *new_mmap(size_t size, char letter);
size_t		get_optimal_size(size_t chunk_size, char letter);
void    *do_malloc(t_pages *curr_p, t_base_node *node, int size);
void 	*find_spot(t_pages *current_page, int size);
char    check_between_nodes(t_pages *curr_p, size_t size);
void    *add_node_pages(t_pages *current_page, int size);
void    *large_malloc(size_t size, t_pages *head);
void    *check_space(size_t size, t_pages *head);
void    *check_size(size_t size);
void    *init_large_page(size_t size, t_pages **head);
// void    *malloc(size_t size);


// void    trav_ll(t_base_node *head);
// void    print_ll(int what);
// void    free(void *free_it);

// void	show_alloc_mem();
///////////SHOW ALLOC MEM.c
void print_hex(int value);
void ft_print_addr(void *addr);
void            show_alloc_mem();
void            print_address_mem(void *mem1, void* mem2, size_t nb);
void	print_page(t_pages *head, int *i);
void    print_large(t_pages *head, int *i);


////////FREEE.c
void    ft_free(void *ptr);
void    *search_not_large(void *ptr, t_pages *head);
void    find_node(void *ptr, t_pages *curr_p, int size_of_page, t_pages *prev_p);
#endif

