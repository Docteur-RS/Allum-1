/*
** all.h for allum1 in /home/lancel_e/Documents/PROJET/alum1/dispatch
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Thu Feb 13 12:15:54 2014 lancel_e
** Last update Sun Feb 16 14:33:00 2014 lancel_e
*/

#ifndef ALL_H_
# define ALL_H_

# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <ncurses/curses.h>

typedef struct	s_map
{
  char	**map;
  int	line;
  int	col;
  int	mode;
  int	who_turn;
  int	one;
  int	two;
  char	*play_one;
  char	*play_two;
}		t_map;

typedef struct	s_termc
{
  char	*clean;
  char	*line;
  char	*col;
}		t_termc;

char	*my_xmalloc_doc(char *str);
void	end_all(t_map *allu, t_termc *term, char **envp);
int	only_ascii(char *str1, char *str2);
void	my_quadriple_putstr(char *str, char *autre, char *fird, char *quad);
void	my_triple_putstr(char *str, char *autre, char *fird);
void	my_double_putstr(char *str, char *autre);
int	one_player_name(t_map *allu, int argc, char **argv);
int	two_player_name(t_map *allu, int argc, char **argv);
void	phase_two_end(t_map *allu, int l_one, int l_two);
void	witch_last_line_end_doc(t_map *allu, int *one, int *two);
void	my_double_putstr(char *str, char *autre);
int	only_digit_decide(t_map *allu, int nop);
int	only_digit_two(char *line, char *col, t_map *allu);
void	precise_who_won(int end);
int	my_strlen(char *tab);
void	rawing_ini(int *ok, int *i);
char	*tgetstr(char *id, char **area);
char	*first_read(t_termc *term);
char	*second_read(t_termc *term);
int	player_one(t_map *allu, t_termc *term, char *line, char *col);
int	player_two(t_map *allu, t_termc *term, char *line, char *col);
int	pars_read_doc(t_map *allu, int line, int col);
int	pars_read_ia_doc(t_map *allu, int line, int col);
int	col_line_pars_debug_doc(t_map *allu);
void	err_msg_doc(int nb);
void	egalise_mode_one(t_map *allu, int one, int two);
void	egalise_mode_two(t_map *allu, int one, int two);
int	ia_turn_doc(t_map *allu);
int	phase_one(t_map *allu);
int	how_much_per_line(t_map *allu, int line);
int	is_there_really_only_one_everywhere(t_map *allu);
int	check_line_pipe(t_map *allu);
int	phase_two(t_map *allu);
void	ph_two_end_case_three(t_map *allu, int two);
void	ph_two_end_case_two(t_map *allu, int one, int two, int witch);
int	is_case_three_doc(int l_one, int l_two);
int	is_case_two_doc(int l_one, int l_two);
int	ph_two_end_case_one(t_map *allu, int one, int two);
void	egalise_doc(t_map *allu, int mode, int one, int two);
void	witch_last_line_doc(t_map *allu, int *one, int *two);
int	comp_line_doc(t_map *allu, int *line);
void	only_one_last_on_line(t_map *allu, int line);
int	remove_only_one_doc(t_map *allu);
int	delete_entire_line_doc(t_map *allu);
int	only_digit(char *line, char *col, t_map *allu);
int	main_mode_two_player_doc(t_map *allu,  t_termc *term);
int	mode_doc(t_map *allu, char **argv, int argc);
int	main_sub_doc(t_map *allu,  t_termc *term);
int	who_won(t_map *allu);
int	special_count_for_disp_doc(char**map, int line);
void	disp_map_doc(char **map);
void	disp_map_doc_end(char **map);
int	tgetent(char *bp, const char *name);
int	sign_comp(char *str);
int	my_getnbr(char *str);
void	wordtab_end(char **wtab);
int	word_count_doc(char *str, char sepa);
int	letter_count_doc(int word_comp, char *str, char sepa);
char	**my_wordtab(char *words, char sepa);
char	**str_to_wordtab_doc(char *words, char sepa);
int	disp_wordtab(char **wtab);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_power_rec(int nb, int power);
int	new_fonc(int nb, int power, int resul, int i);
int	rawing(int fd, char **envp);
int	un_rawing(int fd, char **envp);

#endif /* !ALL_H_ */
