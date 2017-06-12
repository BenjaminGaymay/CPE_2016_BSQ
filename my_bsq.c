/*
** my_bsq.c for my_bsq in /home/benjamin.g/delivery/CPE_2016_BSQ
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Dec  5 13:28:31 2016 Benjamin GAYMAY
** Last update Thu Dec 15 10:52:01 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "my_bsq.h"
#include "my_printf.h"
#include "check_square.h"

int		my_bsq(char *buffer)
{
  char		**array;
  int		columns;
  int		lines;
  int		i;
  t_square	square;

  i = 0;
  lines = count_lines(buffer);
  columns = count_columns(buffer, 1);
  if (lines == 0)
    return (84);
  if ((array = malloc(sizeof(char*) * (lines + 1))) == NULL)
    return (84);
  while (i < lines)
    {
      if ((array[i] = malloc(sizeof(char) * (columns + 1))) == NULL)
	return (84);
      i++;
    }
  add_in_array(array, buffer, lines, columns);
  init_square(&square);
  find_largest_square(array, lines, columns, &square);
  aff_array(array, lines);
  return (0);
}

int	count_columns(char *buffer, int i)
{
  int	f;
  int	j;

  j = 0;
  f = 0;
  while (i > 0 && buffer[f] != '\0')
    {
      if (buffer[f] == '\n')
	i--;
      f++;
    }
  j = f;
  while (buffer[j] != '\n' && buffer[j] != '\0')
    j++;
  return (j - f);
}

int	count_lines(char *buffer)
{
  int	f;
  int	nb_line;

  f = 0;
  nb_line = 0;
  while (buffer[f] != '\0')
    {
      if (buffer[f] == '\n')
	nb_line++;
      f++;
    }
  if (buffer[f - 1] != '\n')
    nb_line++;
  return (nb_line - 1);
}

void	find_largest_square(char **array, int line,
			    int columns, t_square *square)
{
  while (square->y < line)
    {
      while (square->x < columns)
	{
	  while (check_square(array, square->x, square->y, square->size) == 1)
	    {
	      square->save_size = square->size;
	      square->save_x = square->x;
	      square->save_y = square->y;
	      square->size = square->size + 1;
	    }
	  square->x = square->x + 1;
	}
      square->x = 0;
      square->y = square->y + 1;
    }
  replace_points(array, square->save_x, square->save_y, square->save_size);
}

void	replace_points(char **array, int x, int y, int size)
{
  int	tmp_x;
  int	tmp_y;

  tmp_x = x;
  tmp_y = y;
  while (tmp_y < size + y)
    {
      while (tmp_x < size + x)
	{
	  array[tmp_y][tmp_x] = 'x';
	  tmp_x++;
	}
      tmp_x = x;
      tmp_y++;
    }
}
