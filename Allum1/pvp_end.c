/*
** pvp_end.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Thu Feb 13 13:19:47 2014 lancel_e
** Last update Sat Feb 15 19:00:38 2014 lancel_e
*/

#include "all.h"

void    precise_who_won(int end)
{
  if (end == 2)
    my_putstr("\nYou lose ! TRY AGAIN !\n\n");
  if (end == 4)
    my_putstr("\nyou won... (IA is sad...)\n\n");
}
