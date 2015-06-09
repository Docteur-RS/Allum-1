/*
** map_disp.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:29:59 2014 lancel_e
** Last update Sun Feb 16 13:59:31 2014 lancel_e
*/

#include "all.h"

int	special_count_for_disp_doc(char	**map, int line)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (map[line][i] != '\0')
    {
      if (map[line][i] == '|')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

void	disp_map_doc(char **map)
{
  if (special_count_for_disp_doc(map, 0) != 0)
    my_putstr(tgetstr("mr", NULL));
  my_putstr("1:");
  if (special_count_for_disp_doc(map, 0) != 0)
    my_putstr(tgetstr("me", NULL));
  my_putchar(' ');
  my_putstr(map[0]);
  my_putstr("\n");
  if (special_count_for_disp_doc(map, 1) != 0)
    my_putstr(tgetstr("mr", NULL));
  my_putstr("2:");
  if (special_count_for_disp_doc(map, 1) != 0)
    my_putstr(tgetstr("me", NULL));
  my_putchar(' ');
  my_putstr(map[1]);
  my_putstr("\n");
  disp_map_doc_end(map);
}

void	disp_map_doc_end(char **map)
{
  if (special_count_for_disp_doc(map, 2) != 0)
    my_putstr(tgetstr("mr", NULL));
  my_putstr("3:");
  if (special_count_for_disp_doc(map, 2) != 0)
    my_putstr(tgetstr("me", NULL));
  my_putchar(' ');
  my_putstr(map[2]);
  my_putstr("\n");
  if (special_count_for_disp_doc(map, 3) != 0)
    my_putstr(tgetstr("mr", NULL));
  my_putstr("4:");
  if (special_count_for_disp_doc(map, 3) != 0)
    my_putstr(tgetstr("me", NULL));
  my_putchar(' ');
  my_putstr(map[3]);
  my_putstr("\n");
}

void	end_all(t_map *allu, t_termc *term, char **envp)
{
  un_rawing(0, envp);
  wordtab_end(allu->map);
  if (term->line != NULL)
    free(term->line);
  if (term->col != NULL)
    free(term->col);
}
