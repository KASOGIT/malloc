/*
** stat_printer.c for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Tue Feb  9 22:39:19 2016 benjamin rascol
** Last update Sat Feb 13 00:45:49 2016 
*/

#include "libmy_malloc.h"

void	print_stat(int fd)
{
  putstr_fd(fd, "   ########### Malloc statistics ###########\n\n");
  putstr_fd(fd, "\tMalloc call(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_malloc);
  putstr_fd(fd, "\n\n\tCalloc call(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_calloc);
  putstr_fd(fd, "\n\n\tRealloc call(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_realloc);
  putstr_fd(fd, "\n\n\tFree call(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_free);
  putstr_fd(fd, "\n\n");
  if (g_malloc_conf.stat != STAT_COMPLETE)
    return ;
  putstr_fd(fd, "\tAllocation call(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_allocation);
  putstr_fd(fd, "\n\tSplited segment(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_segment_splited);
  putstr_fd(fd, "\n\tFusioned segment(s)\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_segment_fusioned);
  putstr_fd(fd, "\n\tCurrent segment(s) number\t");
  putnbr_fd(fd, g_malloc_stat.nb_segment);
  putstr_fd(fd, "\n\tTotal bytes allocated\t\t");
  putnbr_fd(fd, g_malloc_stat.nb_bytes_allocated);
  putstr_fd(fd, "\n\tSegments size average\t\t");
  putnbr_fd(fd, g_malloc_stat.segment_size_average);
  putstr_fd(fd, "\n\n* Allocation call(s): Number of break point move.\n");
}

void	get_stat()
{
  update_fixed_stat();
  print_stat(1);
}

void	stat_to_file()
{
  int	fd;

  if ((fd = open("malloc_stat.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    return ;
  update_fixed_stat();
  print_stat(fd);
  close(fd);
}
