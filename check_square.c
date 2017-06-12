/*
** check_square.c for check_square in /home/benjamin.g/delivery/CPE_2016_BSQ
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Dec  6 13:57:34 2016 Benjamin GAYMAY
** Last update Tue Dec  6 14:12:33 2016 Benjamin GAYMAY
*/

#include <stdlib.h>

int	check_square(char **array, int x, int y, int size)
{
  int	x_max;
  int	save_x;
  int	y_max;

  x_max = x + size;
  save_x = x;
  y_max = y + size;
  while (y < y_max)
    {
      if (array[y] == NULL)
	return (0);
      while (x < x_max)
	{
	  if (array[y][x] == '.')
	    x++;
	  else
	    return (0);
	}
      x = save_x;
      y++;
    }
  return (1);
}
