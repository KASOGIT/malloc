/*
** fd_display.c for  in /home/rascol_b/rendu/PSU/PSU_2015_malloc
** 
** Made by benjamin rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed Feb 10 17:37:58 2016 benjamin rascol
** Last update Sun Oct 16 22:35:33 2016 
*/

#include "libmy_malloc.h"

void	putchar_fd(int fd, int c)
{
  if (write(fd, &c, 1) == -1)
    printf("Error write\n");
}

void		putnbr_fd(int fd, int n)
{
  unsigned int	nb;

  nb = n;
  if (n < 0)
    {
      putchar_fd('-', fd);
      nb = -n;
    }
  if (nb > 9)
    {
      putnbr_fd(fd, nb / 10);
      putnbr_fd(fd, nb % 10);
    }
  else
    putchar_fd(fd, '0' + nb);
}

void	putstr_fd(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    printf("Error write\n");
}
