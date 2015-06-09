##
## Makefile for Makefile in /home/lancel_e/Documents/DIVERS/script/base Makefile
## 
## Made by lancel_e
## Login   <lancel_e@epitech.net>
## 
## Started on  Tue Jan  7 14:24:41 2014 lancel_e
## Last update Sun Feb 16 14:25:30 2014 lancel_e
##

CC	= gcc

SRC	= all_pars.c \
	  error.c \
	  ia_brain_four.c \
	  ia_brain_one.c \
	  ia_brain_three.c \
	  ia_brain_two.c \
	  ia_executiv.c \
	  main.c \
	  map_disp.c \
	  my_getnbr.c \
	  my_power_rec.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_str_to_wordtab.c \
	  my_str_to_wordtab_end.c \
	  my_termcaps.c \
	  pvp.c \
	  pvp_end.c \
	  read.c \
	  default_name.c

NAME	= allum1

OBJ	= $(SRC:.c=.o)

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) -lncurses
	cat comp
clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
