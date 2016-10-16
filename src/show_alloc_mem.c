/*
** show_alloc_mem.c for malloc in /home/kaso/Documents/rendu/EPITECH/YEAR2/PSU_2015_malloc/src
** 
** Made by soto adam
** Login   <kaso@epitech.net>
** 
** Started on  Fri Jan 29 15:59:12 2016 soto adam
** Last update Sat Feb 13 13:17:28 2016 
*/

#include "libmy_malloc.h"

void		show_alloc_mem()
{
  int		check;
  t_mblock	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = g_mem_list;
  check = 1;
  while ((check || tmp != g_mem_list) && tmp != NULL)
    {
      check = 0;
      if (!tmp->_available)
	{
	  printf("%p - %p : %d bytes\n",
	  tmp->_data, tmp->_data + tmp->_size, (int)(tmp->_size));
	}
      tmp = tmp->_next;
    }
}
