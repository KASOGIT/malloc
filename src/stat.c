/*
** stat.c for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Feb  1 19:34:38 2016 benjamin rascol
** Last update Sat Feb 13 00:42:35 2016 
*/

#include "stat.h"
#include "libmy_malloc.h"

t_malloc_stat	g_malloc_stat;

void	init_fixed_stat()
{
  g_malloc_stat.nb_segment = 0;
  g_malloc_stat.segment_size_average = 0;
}

void		update_fixed_stat()
{
  int		check;
  t_mblock	*tmp;

  init_fixed_stat();
  tmp = g_mem_list;
  check = 1;
  g_malloc_stat.nb_segment = 0;
  g_malloc_stat.nb_bytes_allocated = 0;
  while ((check || tmp != g_mem_list) && tmp != NULL)
    {
      check = 0;
      tmp = tmp->_next;
      g_malloc_stat.nb_segment++;
      g_malloc_stat.nb_bytes_allocated += (int)tmp->_size;
    }
  if (g_malloc_stat.nb_segment > 0)
    g_malloc_stat.segment_size_average = g_malloc_stat.nb_bytes_allocated
  / g_malloc_stat.nb_segment;
}

void	init_stat()
{
  g_malloc_stat.nb_allocation = 0;
  g_malloc_stat.nb_segment_fusioned = 0;
  g_malloc_stat.nb_segment_splited = 0;
  g_malloc_stat.nb_free = 0;
  g_malloc_stat.nb_malloc = 0;
  g_malloc_stat.nb_realloc = 0;
  g_malloc_stat.nb_calloc = 0;
  g_malloc_stat.nb_segment = 0;
  g_malloc_stat.nb_bytes_allocated = 0;
  g_malloc_stat.segment_size_average = 0;
}
