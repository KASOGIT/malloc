/*
** config.c for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Feb  1 13:26:10 2016 benjamin rascol
** Last update Sun Feb 14 17:22:33 2016 
*/

#include "config.h"
#include "libmy_malloc.h"

t_malloc_conf	g_malloc_conf;

t_algo		g_algo_keys[] =
  {
    {"NEXT-FIT", ALGO_NEXT_FIT},
    {"BEST-FIT", ALGO_BEST_FIT},
    {"WORST-FIT", ALGO_WORST_FIT},
    {"FIRST-FIT", ALGO_FIRST_FIT},
    {NULL, ALGO_UNKNOWN}
  };

t_stat		g_stat_keys[] =
  {
    {"STAT-COMPLETE", STAT_COMPLETE},
    {"STAT-SIMPLE", STAT_SIMPLE},
    {NULL, STAT_NONE}
  };

void	get_algo_type(char **token)
{
  int	i;

  i = 0;
  while ((g_algo_keys[i]).key != NULL)
    {
      if (strcmp((g_algo_keys[i]).key, token[0]) == 0 && atoi(token[1]) == 1)
	{
	  g_malloc_conf.algo = (g_algo_keys[i]).value;
	}
      i++;
    }
}

void	get_stat_type(char **token)
{
  int	i;

  i = 0;
  while ((g_stat_keys[i]).key != NULL)
    {
      if (strcmp((g_stat_keys[i]).key, token[0]) == 0 && atoi(token[1]) == 1)
	{
	  g_malloc_conf.stat = (g_stat_keys[i]).value;
	}
      i++;
    }
}

void	get_type(char *line)
{
  char	*token[2];

  if ((token[0] = strtok(line, "=")) == NULL
      || (token[1] = strtok(NULL, "\n")) == NULL)
    return ;
  get_algo_type(token);
  get_stat_type(token);
}

void		get_conf()
{
  FILE		*fp;
  char		*line;
  size_t	len;
  ssize_t	read_len;

  g_malloc_conf.algo = ALGO_BEST_FIT;
  g_malloc_conf.stat = STAT_NONE;
  if (CONFIG_PARSING != 1)
    return ;
  pthread_mutex_unlock(&g_mutex);
  if ((fp = fopen("/etc/malloc.conf", "r")) == NULL)
    {
      pthread_mutex_lock(&g_mutex);
      return ;
    }
  line = NULL;
  len = 0;
  while ((read_len = getline(&line, &len, fp)) != -1)
    {
      get_type(line);
      free(line);
    }
  fclose(fp);
  pthread_mutex_lock(&g_mutex);
}
