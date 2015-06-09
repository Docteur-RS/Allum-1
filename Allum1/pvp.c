/*
** pvp.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:34:23 2014 lancel_e
** Last update Sun Feb 16 14:40:28 2014 lancel_e
*/

#include "all.h"

int	player_one(t_map *allu, t_termc *term, char *line, char *col)
{
  while (44)
    {
      my_triple_putstr("your turn ", allu->play_one, ":\n");
      line = first_read(term);
      col = second_read(term);
      if (col == NULL || line == NULL)
	return (-1);
      my_quadriple_putstr(term->clean, "After ", allu->play_one, " turn !\n");
      if (only_digit(line, col, allu) == -1)
	continue ;
      if (how_much_per_line(allu, my_getnbr(line) - 1) < my_getnbr(col))
	{
	  disp_map_doc(allu->map);
	  continue ;
	}
      pars_read_doc(allu, my_getnbr(line), my_getnbr(col));
      if (who_won(allu) == 0)
	{
	  my_triple_putstr("\n", allu->play_one, " loses... TRY AGAIN ! \n\n");
	  return (1);
	}
      disp_map_doc(allu->map);
      break ;
    }
  return (0);
}

int	player_two(t_map *allu, t_termc *term, char *line, char *col)
{
  while (44)
    {
      my_triple_putstr("your turn ", allu->play_two, ":\n");
      line = first_read(term);
      col = second_read(term);
      if (col == NULL || line == NULL)
	return (-1);
      my_quadriple_putstr(term->clean, "After ", allu->play_two, " turn !\n");
      if (only_digit(line, col, allu) == -1)
	continue ;
      if (how_much_per_line(allu, my_getnbr(line) - 1) < my_getnbr(col))
	{
	  disp_map_doc(allu->map);
	  continue ;
	}
      pars_read_doc(allu, my_getnbr(line), my_getnbr(col));
      if (who_won(allu) == 0)
	{
	  my_triple_putstr("\n", allu->play_two, " loses... TRY AGAIN !\n\n");
	  return (1);
	}
      disp_map_doc(allu->map);
      break ;
    }
  return (0);
}

int		two_player_name(t_map *allu, int argc, char **argv)
{
  char	*play_one;
  char	*play_two;

  play_one = my_xmalloc_doc("player 1");
  play_two = my_xmalloc_doc("player 2");
  if (argc == 2)
    {
      allu->play_one = play_one;
      allu->play_two = play_two;
      return (0);
    }
  if (argc == 3)
    {
      my_putstr("Usage: ./allum1 [number of players: 1-2] [name of players]\n");
      return (-1);
    }
  if (only_ascii(argv[2], argv[3]) == -1)
    return (-1);
  if (argc == 4)
    {
      allu->play_one = argv[2];
      allu->play_two = argv[3];
    }
  return (0);
}

int		one_player_name(t_map *allu, int argc, char **argv)
{
  char	*play_one;

  play_one = my_xmalloc_doc("player 1");
  if (argc == 2)
    {
      allu->play_one = play_one;
      return (0);
    }
  if (only_ascii(argv[2], "no_player") == -1)
    return (-1);
  if (argc == 3 || argc == 4)
    allu->play_one = argv[2];
  return (0);
}

int	main_mode_two_player_doc(t_map *allu,  t_termc *term)
{
  char	*line;
  char	*col;
  int	stop;

  line = NULL;
  col = NULL;
  stop = 0;
  while (44)
    {
      if ((stop = player_one(allu, term, line, col)) == 1)
	return (2);
      if (stop == -1)
	return (-1);
      if ((stop = player_two(allu, term, line, col)) == 1)
	return (4);
      if (stop == -1)
	return (-1);
    }
  return (0);
}
