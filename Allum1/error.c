/*
** error.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:28:13 2014 lancel_e
** Last update Sat Feb 15 18:32:38 2014 lancel_e
*/

#include "all.h"

int	col_line_pars_debug_doc(t_map *allu)
{
  if (allu->line >= 4)
    {
      err_msg_doc(2);
      disp_map_doc(allu->map);
      return (-1);
    }
  else
    return (0);
}

void	err_msg_doc(int nb)
{
  if (nb == 1)
    my_putstr("Illegal move.\n");
  if (nb == 2)
    my_putstr("Only number [1 or 2 or 3 or 4] please !\n");
  if (nb == 3)
    my_putstr("Something went wrong ! (you...)\n");
}
