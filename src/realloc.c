/*
** realloc.c for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PSU_2015_malloc/src
** 
** Made by soto adam
** Login   <kaso@epitech.net>
** 
** Started on  Fri Jan 29 15:58:45 2016 soto adam
** Last update Sat Feb 13 21:35:52 2016 
*/

#include "libmy_malloc.h"

static void	*realloc_act(void *ptr, size_t size)
{
  t_mblock	*tmp;
  void		*new_b;

  new_b = NULL;
  tmp = ptr - (HEAD_SIZE - 4);
  size = ALIGN_SIZE_MEM(size);
  if (size < tmp->_size)
    {
      split_mblock(tmp, size);
      return (ptr);
    }
  else if (size > tmp->_size)
    {
      if ((new_b = malloc(size)) == NULL)
	return (NULL);
      memcpy(new_b, ptr, tmp->_size);
      memset(ptr, 0, tmp->_size);
      free(ptr);
      return (new_b);
    }
  return (ptr);
}

inline void	*realloc(void *ptr, size_t size)
{
  alloc_stat(FUNC_REALLOC);
  if (ptr == NULL || ptr < (void *)g_mem_list->_data || ptr > sbrk(0))
    {
      if ((ptr = malloc(size)) == NULL)
	return (NULL);
      return (ptr);
    }
  else if ((int)size <= 0)
    {
      free(ptr);
      return (ptr);
    }
  return (realloc_act(ptr, size));
}
