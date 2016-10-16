/*
** stat.h for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Feb  1 19:35:07 2016 benjamin rascol
** Last update Sat Feb 13 00:55:00 2016 
*/

#ifndef STAT_H_
#define STAT_H_

#define FALSE	0
#define TRUE	1

/*
 * Function types
 */

typedef enum	e_func_type
{
  FUNC_MALLOC,
  FUNC_CALLOC,
  FUNC_REALLOC,
  FUNC_ALLOC
}		t_func_type;

typedef struct	s_malloc_stat
{
  int		nb_allocation;
  int		nb_segment_fusioned;
  int		nb_segment_splited;

  int		nb_free;
  int		nb_malloc;
  int		nb_realloc;
  int		nb_calloc;

  int		nb_segment;
  int		nb_bytes_allocated;
  int		segment_size_average;
}		t_malloc_stat;

extern t_malloc_stat	g_malloc_stat;

/*
 * Initialiser
 */

void	init_stat();

/*
 * Updater
 */

void	update_fixed_stat();

/*
 * Printer
 */

void	get_stat();
void	stat_to_file();
void	putchar_fd(int fd, int c);
void	putnbr_fd(int fd, int n);
void	putstr_fd(int fd, char *str);

/*
 * statistic editors
 */

void	alloc_stat(t_func_type type);
void	split_stat();
void	free_stat();
void	fusion_stat();

#endif
