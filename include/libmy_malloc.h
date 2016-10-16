/*
** libmy_malloc.h for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PSU_2015_malloc/include
** 
** Made by soto adam
** Login   <kaso@epitech.net>
** 
** Started on  Fri Jan 29 15:59:54 2016 soto adam
** Last update Sun Feb 14 17:20:13 2016 
*/

#ifndef LIBMYMALLOC_H_
#define LIBMYMALLOC_H_

/*
** unistd : brk/sbrk
** stddef : size_t
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "config.h"
#include "stat.h"

void	show_mem_list();

/*
** Find the neartest multiple of 4 for the argument given size
*/

#define	ALIGN_SIZE_MEM(x)	(((((x) - 1) >> 2) << 2) + 4)
#define HEAD_SIZE		sizeof(struct s_memblock)
#define PAGE_SIZE		getpagesize()

/*
** Define a header for a heap memory block
** who define its size, availability, next, prev and the start of its memory
*/

typedef struct	s_memblock
{
  size_t		_size;
  struct s_memblock	*_next;
  struct s_memblock	*_prev;
  int			_available;
  char			_data[1];
}		t_mblock;

/*
** Shared global variable
*/

extern t_mblock	*g_mem_list;
extern pthread_mutex_t g_mutex;

/*
** Prototypes main funcs
*/

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t nmemb, size_t size);
void	free(void *ptr);

/*
** Prototypes sub funcs
*/

void		show_alloc_mem();
t_mblock	*expand_heap(size_t size);
t_mblock	*find_available_mblock(size_t size);
void		split_mblock(void *current_mblock, size_t size);
void		fusion_mblock(t_mblock *current_mblock);
void		copy_mblock(t_mblock **dest, t_mblock *src);

/*
** Algorithm
*/

t_mblock	*first_fit(size_t size);
t_mblock	*best_fit(size_t size);
t_mblock	*next_fit(size_t size);
t_mblock	*worst_fit(size_t size);

#endif /* !LIBMYMALLOC_H_ */
