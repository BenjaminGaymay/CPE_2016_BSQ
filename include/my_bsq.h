/*
** my_bsq.h for my_bsq in /home/benjamin.g/delivery/CPE_2016_BSQ/include
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Nov 14 09:36:02 2016 Benjamin GAYMAY
** Last update Tue Dec 13 17:39:30 2016 Benjamin GAYMAY
*/

#ifndef MY_BSQ_H_
# define MY_BSQ_H_

typedef struct	s_square
{
  int		x;
  int		y;
  int		size;
  int		save_x;
  int		save_y;
  int		save_size;
}		t_square;

int	my_bsq(char *buffer);
int	count_columns(char *buffer, int line);
int	count_lines(char *buffer);

void	find_largest_square(char **array, int line, int columns,
			    t_square *square);

void	replace_points(char **array, int x, int y, int size);

void	add_in_array(char **array, char *buffer, int line, int columns);
void	aff_array(char **array, int line);
void	init_square(t_square *square);

#endif /* !MY_BSQ_H_ */
