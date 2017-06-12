/*
** main.c for main in /home/benjamin.g/delivery/CPE_2016_BSQ
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Dec  5 11:28:10 2016 Benjamin GAYMAY
** Last update Fri Dec 30 18:41:41 2016 Benjamin GAYMAY
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "my_bsq.h"
#include "my_printf.h"

int		main(int ac, char **av)
{
  struct stat	stat_file;
  char		*buffer;
  int		file;

  stat(av[1], &stat_file);
  if (ac == 2)
    {
      if ((file = open(av[1], O_RDONLY)) < 0)
	return (-1);
      else
	{
	  if ((buffer = malloc(sizeof(char) * (stat_file.st_size + 1))) == NULL)
	    return (84);
	  if ((read(file, buffer, stat_file.st_size) != stat_file.st_size))
	    return (84);
	  if (buffer[0] != 0)
	    my_bsq(buffer);
	}
    }
  else
    my_printf("./bsq name_of_your_file\n");
  return (0);
}
