/*
** ia_executiv.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:29:37 2014 lancel_e
** Last update Tue Feb 11 18:51:30 2014 lancel_e
*/

#include "all.h"

void	 only_one_last_on_line(t_map *allu, int line)
{
  int	i;

  if (how_much_per_line(allu, line) == 1)
    pars_read_ia_doc(allu, line, 1);
  i = 0;
  while (allu->map[line][i] != '|')
    {
      i = i + 1;
    }
  while (allu->map[line][i])
    {
      if (how_much_per_line(allu, line) > 1)
	{
	  pars_read_ia_doc(allu, line, 1);
	}
      else
	break ;
      i = i + 1;
    }
}

int	remove_only_one_doc(t_map *allu)
{
  int	nb;

  nb = 0;
  if (is_there_really_only_one_everywhere(allu) == 1)
    nb = 1;
  if (how_much_per_line(allu, 0) > nb)
    pars_read_ia_doc(allu, 0, 1);
  else  if (how_much_per_line(allu, 1) > nb)
    pars_read_ia_doc(allu, 1, 1);
  else  if (how_much_per_line(allu, 2) > nb)
    pars_read_ia_doc(allu, 2, 1);
  else  if (how_much_per_line(allu, 3) > nb)
    pars_read_ia_doc(allu, 3, 1);
  else
    return (-1);
  return (0);
}

int	delete_entire_line_doc(t_map *allu)
{
  if (how_much_per_line(allu, 0) >= 1)
    pars_read_ia_doc(allu, 0, how_much_per_line(allu, 0));
  else  if (how_much_per_line(allu, 1) >= 1)
    pars_read_ia_doc(allu, 1, how_much_per_line(allu, 1));
  else  if (how_much_per_line(allu, 2) >= 1)
    pars_read_ia_doc(allu, 2, how_much_per_line(allu, 2));
  else  if (how_much_per_line(allu, 3) >= 1)
    pars_read_ia_doc(allu, 3, how_much_per_line(allu, 3));
  else
    return (-1);
  return (-1);
}

int	only_digit_decide(t_map *allu, int nop)
{
  if (nop != 0)
    {
      if (nop == 1)
	err_msg_doc(1);
      if (nop == 2)
	err_msg_doc(2);
      if (nop == 3)
	err_msg_doc(3);
      disp_map_doc(allu->map);
      return (-1);
    }
  return (0);
}

int	only_digit_two(char *line, char *col, t_map *allu)
{
  int	i;

  i = 0;
  while (col[i])
    {
      if (((col[i] < 49 || col[i] > 58)  && line[i] != '\n') || line[0] == '\n')
	{
	  err_msg_doc(1);
	  disp_map_doc(allu->map);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}
