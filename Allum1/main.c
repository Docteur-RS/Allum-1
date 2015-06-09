/*
** main.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:29:49 2014 lancel_e
** Last update Sun Feb 16 15:20:43 2014 lancel_e
*/

#include "all.h"

int		main(int argc, char **argv, char **envp)
{
  char		*allum;
  t_map		allu;
  t_termc	term;
  int		end;

  allum = my_xmalloc_doc("   |   a  |||  a ||||| a|||||||");
  if (envp == NULL || envp[0] == NULL)
    return (0);
  if (mode_doc(&allu, argv, argc) == -1)
    return (0);
  if (rawing(0, envp) == -1)
    return (-1);
  term.clean = tgetstr("cl", NULL);
  my_putstr(term.clean);
  if ((allu.map = str_to_wordtab_doc(allum, 'a')) == NULL)
    return (-1);
  disp_map_doc(allu.map);
  if (allu.mode == 1)
    main_mode_two_player_doc(&allu, &term);
  else
    if ((end = main_sub_doc(&allu, &term)) == -1)
      return (-1);
  precise_who_won(end);
  end_all(&allu, &term, envp);
  return (0);
}

int	only_ascii(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (str1[i] < 32 || str1[i] == 127)
        return (-1);
      i = i + 1;
    }
  i = 0;
  while (str2[i])
    {
      if (str2[i] < 32 || str2[i] == 127)
        return (-1);
      i = i + 1;
    }
  return (0);
}

int	mode_doc_end(t_map *allu, int argc, char **argv)
{
  if (argv[1][0] == '2')
    {
      if (two_player_name(allu, argc, argv) == -1)
	return (-1);
      allu->mode = 1;
    }
  else if (argv[1][0] == '1')
    {
      if (one_player_name(allu, argc, argv) == -1)
	return (-1);
      allu->mode = 0;
    }
  else
    {
      my_putstr("Only one or two players please !\n");
      return (-1);
    }
  return (1);
}

int	mode_doc(t_map *allu, char **argv, int argc)
{
  allu->mode = 0;
  if (argc == 2 || argc == 4 || argc == 3)
    {
      if (mode_doc_end(allu, argc, argv) == -1)
	return (-1);
      else
	return (0);
    }
  else
    {
      my_putstr("Usage: ./allum1 [number of players: 1-2] [name of players]\n");
      return (-1);
    }
  return (0);
}

int	main_sub_doc(t_map *allu, t_termc *term)
{
  char	*line;
  char	*col;

  while (44)
    {
      line = first_read(term);
      col = second_read(term);
      if (line == NULL || col == NULL)
	return (-1);
      my_putstr(term->clean);
      my_triple_putstr("After: ", allu->play_one ," turn !\n");
      if (only_digit(line, col, allu) == -1)
	continue ;
      pars_read_doc(allu, my_getnbr(line), my_getnbr(col));
      if (who_won(allu) == 0)
	return (2);
      disp_map_doc(allu->map);
      my_putstr("\nAfter: IA turn !\n");
      ia_turn_doc(allu);
      disp_map_doc(allu->map);
      if (who_won(allu) == 0)
	return (4);
    }
  return (0);
}
