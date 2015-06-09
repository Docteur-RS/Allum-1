/*
** my_getnbr.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:30:12 2014 lancel_e
** Last update Tue Feb 11 18:44:05 2014 lancel_e
*/

#include "all.h"

int	nbr_comp(char *str)
{
  int	comp;

  comp = sign_comp(str);
  while (str[comp] >= '0' && str[comp] <= '9')
    {
      comp = comp + 1;
    }
  comp = comp - sign_comp(str);
  return (comp);
}

int     sign_comp(char *str)
{
  int   i;
  int   z;

  i = 0;
  z = 0;
  while (str[i])
    {
      if (str[i] == '+' || str[i] == '-')
        {
          z = z + 1;
        }
      i = i + 1;
    }
  return (z);
}

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  int	lon;
  int	n;

  i = sign_comp(str);
  s = 0;
  n = 0;
  lon = nbr_comp(str) - 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      s = (str[i] - 48) * my_power_rec(10, lon);
      n = n + s;
      lon = lon - 1;
      i = i + 1;
    }
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	n = n * (- 1);
      i = i + 1;
    }
  return (n);
}
