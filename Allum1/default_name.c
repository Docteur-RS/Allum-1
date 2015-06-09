/*
** default_name.c for allum1 in /home/lancel_e/rendu/Allum1
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb 16 15:30:23 2014 lancel_e
** Last update Sun Feb 16 15:30:24 2014 lancel_e
*/

#include "all.h"

char	*my_xmalloc_doc(char *str)
{
  char	*ret;
  int	i;

  i = 0;
  ret = malloc((my_strlen(str) + 1) * sizeof(char));
  if (ret == NULL)
    exit(EXIT_FAILURE);
  while (str[i])
    {
      ret[i] = str[i];
      i = i + 1;
    }
  ret[i] = '\0';
  return (ret);
}
