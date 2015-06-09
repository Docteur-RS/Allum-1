/*
** my_strlen.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:32:57 2014 lancel_e
** Last update Mon Feb 10 18:04:59 2014 lancel_e
*/

int	my_strlen(char *tab)
{
  int	nb_carac;

  if (tab[0] == '\0')
    return (0);
  nb_carac = 0;
  while (tab[nb_carac] != 0)
    {
      nb_carac = nb_carac + 1;
    }
  return (nb_carac);
}
