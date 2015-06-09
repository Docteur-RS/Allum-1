/*
** all_pars.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:26:38 2014 lancel_e
** Last update Thu Feb 13 13:14:50 2014 lancel_e
*/

#include "all.h"

int	pars_read_doc(t_map *allu, int line, int col)
{
  int	i;

  i = 0;
  line = line - 1;
  while (allu->map[line][i])
    {
      if (allu->map[line][i] == '|' && col != 0)
	{
	  allu->map[line][i] = ' ';
	  col = col - 1;
	}
      i = i + 1;
    }
  return (0);
}

int	pars_read_ia_doc(t_map *allu, int line, int col)
{
  int	i;

  i = 0;
  while (allu->map[line][i])
    {
      if (allu->map[line][i] == '|' && col != 0)
	{
	  allu->map[line][i] = ' ';
	  col = col - 1;
	}
      i = i + 1;
    }
  return (0);
}
