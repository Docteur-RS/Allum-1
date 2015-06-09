/*
** my_putstr.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:32:41 2014 lancel_e
** Last update Sun Feb 16 20:22:32 2014 lancel_e
*/

#include "all.h"

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

void	my_double_putstr(char *str, char *autre)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  while (*autre != '\0')
    {
      my_putchar(*autre);
      autre = autre + 1;
    }
}

void	my_triple_putstr(char *str, char *autre, char *fird)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  while (*autre != '\0')
    {
      my_putchar(*autre);
      autre = autre + 1;
    }
  while (*fird != '\0')
    {
      my_putchar(*fird);
      fird = fird + 1;
    }
}

void	my_quadriple_putstr(char *str, char *autre, char *fird, char *quad)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  while (*autre != '\0')
    {
      my_putchar(*autre);
      autre = autre + 1;
    }
  while (*fird != '\0')
    {
      my_putchar(*fird);
      fird = fird + 1;
    }
  while (*quad != '\0')
    {
      my_putchar(*quad);
      quad = quad + 1;
    }
}
