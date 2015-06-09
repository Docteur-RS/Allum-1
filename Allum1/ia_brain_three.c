/*
** ia_brain_three.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:29:11 2014 lancel_e
** Last update Tue Feb 11 18:51:03 2014 lancel_e
*/

#include "all.h"

int	 ph_two_end_case_one(t_map *allu, int one, int two)
{
  int	line;

  line = 0;
  if (one != 100)
    line = one;
  else
    line = two;
  only_one_last_on_line(allu, line);
  return (0);
}

void	egalise_doc(t_map *allu, int mode, int one, int two)
{
  if (mode == 1)
    egalise_mode_one(allu, one, two );
  if (mode == 2)
    egalise_mode_two(allu, one, two);
}

void	witch_last_line_doc(t_map *allu, int *one, int *two)
{
  *one = 100;
  *two = 100;
  if (how_much_per_line(allu, 0) != 0)
    {
      if (*two == 100 && *one != 100)
	*two = 0;
      if (*one == 100)
	*one = 0;
    }
  if (how_much_per_line(allu, 1) != 0)
    {
      if (*two == 100 && *one != 100)
	*two = 1;
      if (*one == 100)
	*one = 1;
    }
  if (how_much_per_line(allu, 2) != 0)
    {
      if (*two == 100 && *one != 100)
	*two = 2;
      if (*one == 100)
	*one = 2;
    }
  witch_last_line_end_doc(allu, one, two);
}

void	witch_last_line_end_doc(t_map *allu, int *one, int *two)
{
  if (how_much_per_line(allu, 3) != 0)
    {
      if (*two == 100 && *one != 100)
	*two = 3;
      if (*one == 100)
	*one = 3;
    }
}

int	comp_line_doc(t_map *allu, int *line)
{
  while (*line < 4)
    {
      if (allu->map[*line][0] == '|')
	return (0);
      else if (allu->map[*line][1] == '|')
	return (1);
      else if (allu->map[*line][2] == '|')
	return (2);
      else if (allu->map[*line][3] == '|')
	return (3);
      else if (allu->map[*line][4] == '|')
	return (4);
      else if (allu->map[*line][5] == '|')
	return (5);
      else if (allu->map[*line][6] == '|')
	return (6);
      else
	line = line + 1;
    }
  return (-1);
}
