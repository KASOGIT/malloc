/*
** algorithm.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_malloc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Feb 12 19:11:03 2016 
** Last update Sat Feb 13 21:33:22 2016 
*/

#include "libmy_malloc.h"

inline t_mblock	*first_fit(size_t size)
{
  int		check;
  t_mblock	*tmp;

  tmp = g_mem_list;
  check = 1;
  while (tmp && (check || tmp != g_mem_list))
    {
      check = 0;
      if (tmp->_available && tmp->_size >= size)
	{
	  tmp->_available = 0;
	  return (tmp);
	}
      tmp = tmp->_prev;
    }
  return (NULL);
}

inline t_mblock	*best_fit(size_t size)
{
  int		check;
  t_mblock	*tmp;
  t_mblock	*best;

  check = 1;
  tmp = g_mem_list;
  best = NULL;
  while (tmp && (check || tmp != g_mem_list))
    {
      check = 0;
      if (tmp->_available && tmp->_size >= size)
	{
	  if (best == NULL)
	    best = tmp;
	  else
	    {
	      if (tmp->_size <= best->_size)
		best = tmp;
	    }
	}
      tmp = tmp->_prev;
    }
  if (best)
    best->_available = 0;
  return (best);
}

inline t_mblock		*next_fit(size_t size)
{
  static t_mblock	*last = NULL;
  t_mblock		*tmp;
  int			check;

  check = 1;
  if (last == NULL || last < g_mem_list || (void *)last->_data > sbrk(0))
    {
      tmp = first_fit(size);
      last = tmp;
      return (tmp);
    }
  else
    tmp = last->_next;
  while (tmp && (check || tmp != last))
    {
      check = 0;
      if (tmp->_available && tmp->_size >= size)
	{
	  tmp->_available = 0;
	  last = tmp;
	  return (tmp);
	}
      tmp = tmp->_prev;
    }
  return (NULL);
}

inline t_mblock	*worst_fit(size_t size)
{
  int		check;
  t_mblock	*tmp;
  t_mblock	*worst;

  check = 1;
  tmp = g_mem_list;
  worst = NULL;
  while (tmp && (check || tmp != g_mem_list))
    {
      check = 0;
      if (tmp->_available && tmp->_size >= size)
	{
	  if (worst == NULL)
	    worst = tmp;
	  else
	    {
	      if (tmp->_size >= worst->_size)
		worst = tmp;
	    }
	}
      tmp = tmp->_prev;
    }
  if (worst)
    worst->_available = 0;
  return (worst);
}
