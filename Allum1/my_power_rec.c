/*
** my_power_rec.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:30:28 2014 lancel_e
** Last update Thu Feb 13 10:28:28 2014 lancel_e
*/

#include "all.h"

int	my_power_rec(int nb, int power)
{
  int	i;
  int	resul;

  resul = 1;
  i = 0;
  return (new_fonc(nb, power, resul, i));
}

int	new_fonc(int nb, int power, int resul, int i)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (i < power)
    {
      resul = resul * nb;
      i = i + 1;
      if (i > 12)
	{
	  return (0);
	}
      new_fonc(nb, power, resul, i);
    }
  else
    return (resul);
  return (-1);
}
