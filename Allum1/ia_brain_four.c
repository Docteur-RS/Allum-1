/*
** ia_brain_four.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:28:32 2014 lancel_e
** Last update Sun Feb 16 20:13:15 2014 lancel_e
*/

#include "all.h"

void	 egalise_mode_one(t_map *allu, int one, int two)
{
  int	less;

  less = how_much_per_line(allu, two) - how_much_per_line(allu, one);
  pars_read_ia_doc(allu, two, less);
}

void	 egalise_mode_two(t_map *allu, int one, int two)
{
  int	less;

  less = how_much_per_line(allu, one) - how_much_per_line(allu, two);
  pars_read_ia_doc(allu, one, less);
}

void	phase_two_end(t_map *allu, int l_one, int l_two)
{
  if (l_one < l_two)
    egalise_doc(allu, 1, allu->one, allu->two);
  else if (l_one > l_two)
    egalise_doc(allu, 2, allu->one, allu->two);
  else
    remove_only_one_doc(allu);
}

int	 only_digit(char *line, char *col, t_map *allu)
{
  int	i;
  int	nop;

  i = 0;
  nop = 0;
  if (my_strlen(line) != 2)
    nop = 2;
  else if (line[i] != '1' && line[i] != '2' && line[i] != '3'
	   && line[i] != '4')
    nop = 3;
  else if (line[0] == '\n')
    nop = 2;
  else if (how_much_per_line(allu, my_getnbr(line) -1) < my_getnbr(col))
    nop = 1;
  if (only_digit_decide(allu, nop) == -1)
    return (-1);
  if (only_digit_two(line, col, allu) == -1)
    return (-1);
  return (0);
}
