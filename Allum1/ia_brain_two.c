/*
** ia_brain_two.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:29:24 2014 lancel_e
** Last update Thu Feb 13 13:16:57 2014 lancel_e
*/

#include "all.h"

int	phase_two(t_map *allu)
{
  int	one;
  int	two;
  int	l_one;
  int	l_two;

  witch_last_line_doc(allu, &one, &two);
  if (one == 100 || two == 100)
    if (ph_two_end_case_one(allu, one, two) == 0)
      return (0);
  l_one = how_much_per_line(allu, one);
  l_two = how_much_per_line(allu, two);
  if (is_case_three_doc(l_one, l_two) == 1)
    {
      ph_two_end_case_three(allu, two);
      return (0);
    }
  if (is_case_two_doc(l_one, l_two) == 1 || is_case_two_doc(l_one, l_two) == 2)
    {
      ph_two_end_case_two(allu, one, two, is_case_two_doc(l_one, l_two));
      return (0);
    }
  allu->one = one;
  allu->two = two;
  phase_two_end(allu, l_one, l_two);
  return (0);
}

void	 ph_two_end_case_three(t_map *allu, int two)
{
  pars_read_ia_doc(allu, two, how_much_per_line(allu, two));
}

void	ph_two_end_case_two(t_map *allu, int one, int two, int witch)
{
  int	line;

  line = 0;
  if (witch == 1)
    line = two;
  if (witch == 2)
    line = one;
  pars_read_ia_doc(allu, line, how_much_per_line(allu, line));
}

int	 is_case_three_doc(int l_one, int l_two)
{
  if (l_one == 1 && l_two == 1)
    return (1);
  return (0);
}

int	 is_case_two_doc(int l_one, int l_two)
{
  if (l_one == 1)
    return (1);
  if (l_two == 1)
    return (2);
  return (0);
}
