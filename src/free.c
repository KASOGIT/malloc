/*
** free.c for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PSU_2015_malloc/src
** 
** Made by soto adam
** Login   <kaso@epitech.net>
** 
** Started on  Fri Jan 29 15:58:32 2016 soto adam
** Last update Sun Oct 16 22:34:33 2016 
*/

#include "libmy_malloc.h"

void		fusion_mblock(t_mblock *current_mblock)
{
  current_mblock->_available = 1;
  if (current_mblock->_prev->_available && current_mblock != g_mem_list)
    {
      fusion_stat();
      current_mblock = current_mblock->_prev;
      current_mblock->_size += current_mblock->_next->_size + HEAD_SIZE;
      current_mblock->_next->_next->_prev = current_mblock;
      current_mblock->_next = current_mblock->_next->_next;
    }
  if (current_mblock->_next->_available && current_mblock->_next != g_mem_list)
    {
      fusion_stat();
      current_mblock->_size += current_mblock->_next->_size + HEAD_SIZE;
      current_mblock->_next->_next->_prev = current_mblock;
      current_mblock->_next = current_mblock->_next->_next;
    }
  if (current_mblock->_next == g_mem_list
      && current_mblock->_size > (size_t)PAGE_SIZE)
    {
      current_mblock->_size -= current_mblock->_size / PAGE_SIZE * PAGE_SIZE;
      if (brk(current_mblock->_data + current_mblock->_size + 4) == -1)
	printf("Error brk\n");
    }
}

inline void	free(void *ptr)
{
  t_mblock	*tmp;

  pthread_mutex_lock(&g_mutex);
  if (g_mem_list == NULL || ptr == NULL
      || ptr < (void *)g_mem_list->_data || ptr > sbrk(0))
    {
      pthread_mutex_unlock(&g_mutex);
      return ;
    }
  else if (g_mem_list->_data == ptr)
    fusion_mblock(g_mem_list);
  else
    {
      tmp = g_mem_list->_prev;
      while (tmp->_data != ptr && tmp != g_mem_list)
	tmp = tmp->_prev;
      if (tmp != g_mem_list)
	fusion_mblock(tmp);
    }
  free_stat();
  pthread_mutex_unlock(&g_mutex);
}
