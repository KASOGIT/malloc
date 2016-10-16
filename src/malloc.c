/*
** malloc.c for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PSU_2015_malloc/src
** 
** Made by soto adam
** Login   <kaso@epitech.net>
** 
** Started on  Fri Jan 29 15:58:10 2016 soto adam
** Last update Sun Feb 14 17:40:13 2016 
*/

#include "libmy_malloc.h"

t_mblock	*g_mem_list = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static int	find_expand(t_mblock **mblock, size_t size)
{
  if ((*mblock = find_available_mblock(size)) == NULL)
    {
      if ((*mblock = expand_heap(size)) == NULL)
	{
	  pthread_mutex_unlock(&g_mutex);
	  return (0);
	}
    }
  else
    split_mblock(*mblock, size);
  return (1);
}

inline void		*malloc(size_t size)
{
  t_mblock		*new_mblock;

  pthread_mutex_lock(&g_mutex);
  size = ALIGN_SIZE_MEM(size);
  alloc_stat(FUNC_MALLOC);
  if ((int)size <= 0)
    {
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  if (g_mem_list != NULL)
    {
      if (find_expand(&new_mblock, size) == 0)
	return (NULL);
    }
  else
    {
      if ((new_mblock = expand_heap(size)) == NULL)
	{
	  pthread_mutex_unlock(&g_mutex);
	  return (NULL);
	}
    }
  pthread_mutex_unlock(&g_mutex);
  return (new_mblock->_data);
}

inline t_mblock	*expand_heap(size_t size)
{
  t_mblock	*new_mblock;
  size_t	new_size;

  alloc_stat(FUNC_ALLOC);
  new_size = ((size - (size % PAGE_SIZE)) + PAGE_SIZE) - HEAD_SIZE;
  new_mblock = sbrk(0);
  if (sbrk(HEAD_SIZE + new_size) == (void *)-1)
    return (NULL);
  new_mblock->_size = new_size;
  new_mblock->_available = 0;
  if (g_mem_list)
    {
      new_mblock->_prev = g_mem_list->_prev;
      g_mem_list->_prev->_next = new_mblock;
      new_mblock->_next = g_mem_list;
      g_mem_list->_prev = new_mblock;
    }
  else
    {
      g_mem_list = new_mblock;
      new_mblock->_next = g_mem_list;
      new_mblock->_prev = g_mem_list;
    }
  split_mblock(new_mblock, size);
  return (new_mblock);
}

t_mblock	*find_available_mblock(size_t size)
{
  if (g_malloc_conf.algo == ALGO_FIRST_FIT)
    {
      return (first_fit(size));
    }
  else if (g_malloc_conf.algo == ALGO_NEXT_FIT)
    {
      return (next_fit(size));
    }
  else if (g_malloc_conf.algo == ALGO_WORST_FIT)
    {
      return (worst_fit(size));
    }
  else
    {
      return (best_fit(size));
    }
  return (NULL);
}

inline void	split_mblock(void *current_mblock, size_t size)
{
  void		*void_mblock;
  t_mblock	*new_mblock;
  t_mblock	*cast_mblock;

  cast_mblock = (t_mblock *)current_mblock;
  if (cast_mblock->_size > (size + HEAD_SIZE + 4))
    {
      split_stat();
      void_mblock = current_mblock + HEAD_SIZE + size;
      new_mblock = void_mblock;
      new_mblock->_size = cast_mblock->_size - size - HEAD_SIZE;
      cast_mblock->_size -= new_mblock->_size + HEAD_SIZE;
      cast_mblock->_available = 0;
      new_mblock->_available = 1;
      new_mblock->_prev = cast_mblock;
      new_mblock->_next = cast_mblock->_next;
      cast_mblock->_next = new_mblock;
      new_mblock->_next->_prev = new_mblock;
    }
}
