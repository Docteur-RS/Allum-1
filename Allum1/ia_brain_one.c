/*
** ia_brain_one.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:28:57 2014 lancel_e
** Last update Thu Feb 13 13:15:50 2014 lancel_e
*/

#include "all.h"

int	ia_turn_doc(t_map *allu)
{
  if (phase_one(allu) == 1)
    phase_two(allu);
  return (0);
}

int	phase_one(t_map *allu)
{
  if (check_line_pipe(allu) == 4 || check_line_pipe(allu) == 3)
    {
      if (check_line_pipe(allu) == 4)
	delete_entire_line_doc(allu);
      else if (check_line_pipe(allu) == 3)
	remove_only_one_doc(allu);
      return (0);
    }
  return (1);
}

int	how_much_per_line(t_map *allu, int line)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (allu->map[line][i] != '\0')
    {
      if (allu->map[line][i] == '|')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int	is_there_really_only_one_everywhere(t_map *allu)
{
  if (how_much_per_line(allu, 0) != 1 && how_much_per_line(allu, 0) != 0)
    return (1);
  if (how_much_per_line(allu, 1) != 1 && how_much_per_line(allu, 1) != 0)
    return (1);
  if (how_much_per_line(allu, 2) != 1 && how_much_per_line(allu, 2) != 0)
    return (1);
  if (how_much_per_line(allu, 3) != 1 && how_much_per_line(allu, 3) != 0)
    return (1);
  return (0);
}

int	check_line_pipe(t_map *allu)
{
  int	h;
  int	i;
  int	check;
  int	nb;

  i = 0;
  h = 0;
  check = 0;
  nb = 0;
  while (allu->map[i] != '\0')
    {
      while (allu->map[i][h] != '\0')
        {
	  if (allu->map[i][h] == '|')
	    check = 1;
          h = h + 1;
        }
      h = 0;
      if (check == 1)
	nb = nb + 1;
      check = 0;
      i = i + 1;
    }
  return (nb);
}
