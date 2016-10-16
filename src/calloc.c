/*
** calloc.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_malloc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Feb  5 14:41:16 2016 
** Last update Thu Feb 11 14:43:26 2016 
*/

#include "libmy_malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;
  size_t	align_size;

  alloc_stat(FUNC_CALLOC);
  align_size = ALIGN_SIZE_MEM(size * nmemb);
  if ((int)nmemb <= 0 || (int)size <= 0)
    return (NULL);
  if ((ptr = malloc(align_size)) == NULL)
    return (NULL);
  memset(ptr, 0, align_size);
  return (ptr);
}
