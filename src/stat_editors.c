/*
** stat_editors.c for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Tue Feb  2 17:53:07 2016 benjamin rascol
** Last update Sun Feb 14 17:08:35 2016 benjamin rascol
*/

#include "libmy_malloc.h"

void		check_for_init()
{
  static int	init = FALSE;

  if (init == FALSE)
    {
      init = TRUE;
      get_conf();
      init_stat();
    }
}

void	alloc_stat(t_func_type type)
{
  check_for_init();
  if (CONFIG_PARSING == 1 &&
      (g_malloc_conf.stat == STAT_COMPLETE
       || g_malloc_conf.stat == STAT_SIMPLE))
    {
      if (type == FUNC_MALLOC)
	g_malloc_stat.nb_malloc++;
      else if (type == FUNC_REALLOC)
	g_malloc_stat.nb_realloc++;
      else if (type == FUNC_CALLOC)
	g_malloc_stat.nb_calloc++;
      else
	g_malloc_stat.nb_allocation++;
	  stat_to_file();
    }
}

void	split_stat()
{
  check_for_init();
  if (CONFIG_PARSING == 1 && g_malloc_conf.stat == STAT_COMPLETE)
    {
      g_malloc_stat.nb_segment_splited++;
    }
}

void	free_stat()
{
  check_for_init();
  if (CONFIG_PARSING == 1 &&
      (g_malloc_conf.stat == STAT_COMPLETE
       || g_malloc_conf.stat == STAT_SIMPLE))
    {
      g_malloc_stat.nb_free++;
      stat_to_file();
    }
}

void	fusion_stat()
{
  check_for_init();
  if (CONFIG_PARSING == 1 && g_malloc_conf.stat == STAT_COMPLETE)
    {
      g_malloc_stat.nb_segment_fusioned++;
    }
}
