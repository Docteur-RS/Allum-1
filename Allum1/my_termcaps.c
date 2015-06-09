/*
** my_termcaps.c for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Sun Feb  9 17:34:11 2014 lancel_e
** Last update Sun Feb 16 20:24:20 2014 lancel_e
*/

#include "all.h"

void	rawing_ini(int *ok, int *i)
{
  *ok = 0;
  *i = 0;
}

char	**term_var_finder(char **envp, int *ok)
{
  int	i;
  char	**term;

  i = 0;
  while (envp[i])
    {
      if (envp[i][0] == 'T' && envp[i][1] == 'E'  &&
          envp[i][2] == 'R' && envp[i][3] == 'M' && envp[i][4] == '=')
        {
	  term = str_to_wordtab_doc(envp[i], '=');
	  *ok = 1;
        }
      i = i + 1;
    }
  return (term);
}

int			rawing(int fd, char **envp)
{
  struct termios	termios_p;
  int			i;
  char			**term;
  int			ok;

  rawing_ini(&ok, &i);
  term = term_var_finder(envp, &ok);
  if (ok == 0)
    return (-1);
  if (tgetent(NULL, term[1]) != 1)
    exit(EXIT_FAILURE);
  if (tcgetattr(fd, &termios_p) == -1)
    return (-1);
  termios_p.c_cc[VMIN] = 1;
  termios_p.c_cc[VTIME] = 0;
  termios_p.c_lflag &= ~(IGNBRK);
  if (tcsetattr(fd, TCSADRAIN, &termios_p) == -1)
    exit(EXIT_FAILURE);
  return (0);
}

int			un_rawing(int fd, char **envp)
{
  struct termios	termios_p;
  int			i;
  char			**term;
  int			ok;

  rawing_ini(&ok, &i);
  term = term_var_finder(envp, &ok);
  if (ok == 0)
    return (-1);
  if (tgetent(NULL, term[1]) != 1)
    exit(EXIT_FAILURE);
  if (tcgetattr(fd, &termios_p) == -1)
    return (-1);
  termios_p.c_cc[VMIN] = 1;
  termios_p.c_cc[VTIME] = 0;
  termios_p.c_lflag |= (IGNBRK);
  if (tcsetattr(fd, TCSADRAIN, &termios_p) == -1)
    exit(EXIT_FAILURE);
  return (0);
}
