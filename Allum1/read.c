/*
** read.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:34:38 2014 lancel_e
** Last update Sun Feb 16 20:26:40 2014 lancel_e
*/

#include "all.h"

char	*first_read(t_termc *term)
{
  char	*line;
  int	ret;

  line = malloc(3000 * sizeof(char));
  if (line  == NULL)
    return (NULL);
  term->line = line;
  my_putstr("\nOn witch line do you want to play ? :");
  ret = read(0, line, 2999);
  if (ret <= 0 || line[0] == 0)
    exit(EXIT_FAILURE);
  return (line);
}

char	*second_read(t_termc *term)
{
  char	*col;
  int	ret;

  col = malloc(3000 * sizeof(char));
  if (col == NULL)
    return (NULL);
  term->col = col;
  my_putstr("how many matchstick do you want ? :");
  ret = read(0, col, 2999);
  if (ret <= 0 || col[0] == 0)
    exit(EXIT_FAILURE);
  return (col);
}

int	who_won(t_map *allu)
{
  int	h;
  int	i;
  int	pipe;

  i = 0;
  h = 0;
  pipe = 0;
  while (allu->map[i] != '\0')
    {
      while (allu->map[i][h] != '\0')
	{
	  if (allu->map[i][h] == '|')
	    pipe = 1;
	  h = h + 1;
	}
      h = 0;
      i = i + 1;
    }
  if (pipe == 0)
    return (0);
  if (pipe == 1)
    return (1);
  return (-1);
}
