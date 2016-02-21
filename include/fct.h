/*
** fct.h for Alum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1/include
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 15:09:19 2016 Voyevoda
** Last update Sun Feb 21 13:39:47 2016 Voyevoda
*/

#ifndef FCT_H_
#define FCT_H_
#include "./list.h"

int	check_number(char *str);
int	player_turn_line_error(int k, int *alum);
int	game_over(int *alum, int flag);
int	my_rand(int b, int a);
void	my_putchar(char c);
void	my_putstr(char *str);
void	print_game_board(int *alum1, t_list *alphabet);
int	def_board(char **alum1);
int	*malloc_alum();
int	my_getnbr(char *str);
int	my_put_nbr(int nb);
t_list	*malloc_alphabet(int *alum);

#endif /*FCT_H_*/
