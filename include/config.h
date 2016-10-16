/*
** config.h for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Feb  1 13:31:29 2016 benjamin rascol
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#define CONFIG_PARSING 0

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
** Configuration types.
*/

typedef enum		e_algo_type
  {
    ALGO_FIRST_FIT,
    ALGO_WORST_FIT,
    ALGO_BEST_FIT,
    ALGO_NEXT_FIT,
    ALGO_UNKNOWN
  }			t_algo_type;

typedef enum		e_stat_type
  {
    STAT_COMPLETE,
    STAT_SIMPLE,
    STAT_NONE
  }			t_stat_type;

typedef struct		s_stat
{
  char			*key;
  t_stat_type		value;
}			t_stat;

typedef struct		s_algo
{
  char			*key;
  t_algo_type		value;
}			t_algo;

typedef struct		s_malloc_conf
{
  t_stat_type		stat;
  t_algo_type		algo;
}			t_malloc_conf;

extern t_malloc_conf   g_malloc_conf;

void			get_conf();

#endif
