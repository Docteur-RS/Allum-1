/*
** my_str_to_wordtab.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:33:25 2014 lancel_e
** Last update Sun Feb 16 12:31:57 2014 lancel_e
*/

#include "all.h"

int	word_count_doc(char *str, char sepa)
{
  int	nbw;
  int	i;

  nbw = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == sepa)
      nbw = nbw + 1;
      i = i + 1;
    }
  return (nbw);
}

int	letter_count_doc(int word_comp, char *str, char sepa)
{
  int	nbl;
  int	is_word;
  int	i;
  int	nbw;

  nbw = 0;
  nbl = 0;
  i = 0;
  is_word = 0;
  while (str[i])
    {
      if (is_word == 0 && str[i] != sepa)
        {
          nbw = nbw + 1;
          is_word = 1;
        }
      if (str[i] == sepa)
	is_word = 0;
      i = i + 1;
      if (str[i] != sepa && nbw == word_comp)
	nbl = nbl + 1;
    }
  return (nbl);
}

char	**my_wordtab(char *words, char sepa)
{
  int	i;
  int	nbl;
  int	maker;
  char	**table;
  int	nbw;

  nbl = 0;
  i = 0;
  maker = 0;
  nbw = word_count_doc(words, sepa);
  table = malloc((nbw + 1) * sizeof(char *));
  if (table == NULL)
    return (NULL);
  table[nbw] = NULL;
  maker = maker + 1;
  while (i < nbw)
    {
      nbl = letter_count_doc((i + 1), words, sepa);
      table[i] = malloc((nbl + 1) * sizeof(char));
      if (table[i] == NULL)
	return (NULL);
      table[i][nbl] = '\0';
      i = i + 1;
    }
  return (table);
}

char	**str_to_wordtab_doc(char *words, char sepa)
{
  int	string;
  int	i;
  char	**tab;
  int	h;

  if ((tab = my_wordtab(words, sepa)) == NULL)
    return (NULL);
  h = 0;
  i = 0;
  string = 0;
  while (i <  word_count_doc(words, sepa))
    {
      while (h < letter_count_doc((i + 1), words, sepa))
	{
	  tab[i][h] = words[string];
	  string = string + 1;
	  h = h + 1;
	}
      i = i + 1;
      string = string + 1;
      h = 0;
    }
  return (tab);
}

int	disp_wordtab(char **wtab)
{
  int	h;
  int	i;

  i = 0;
  h = 0;
  while (wtab[i] != '\0')
    {
      while (wtab[i][h] != '\0')
	{
	  my_putchar(wtab[i][h]);
	  h = h + 1;
	}
      h = 0;
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
