/*
** main.c for allum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 14:50:12 2016 Voyevoda
** Last update Mon Feb 22 20:10:43 2016 Voyevoda
*/
#include <stdio.h>
#include <stdlib.h>
#include "./include/get_next_line.h"
#include "./include/fct.h"
#include "./include/list.h"

int	ai_turn(t_list *alphabet, int *alum)
{
  int	line;
  int	matches;

  while (matches != -1)
    if (alum[(line = my_rand(4, 0))] > 0)
      {
	my_putstr("\n\nAI's turn...");
	matches = my_rand(alum[line], 1);
	alum[line] = alum[line] - matches;
	my_putstr("\nAI removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line + 1);
	my_putchar('\n');
	print_game_board(alum, alphabet);
	alphabet->flag_line = 0;
	if (game_over(alum, 0) == 1)
	  return (1);
	my_putstr("\n\nYour turn:\nLine: ");
	matches = -1;
      }
  alphabet->flag_match = 0;
  alphabet->flag_line = 0;
  return (0);
}

int	player_turn_match_error(char *s, t_list *alphabet, int *alum)
{
  int	k;

  k = (check_number(s) == -1) ? -1 : my_getnbr(s);
  if (k > alum[alphabet->line])
    {
      my_putstr("Error: not enough matches on this line\nLine: ");
      alphabet->flag_line = 0;
      alphabet->flag_match = 1;
      return (1);
    }
  if (k < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      alphabet->flag_line = 0;
      alphabet->flag_match = 1;
      return (1);
    }
  if (k == 0)
    {
      my_putstr("Error: you have to remove at least one match\nLine: ");
      alphabet->flag_line = 0;
      alphabet->flag_match = 1;
      return (1);
    }
  return (0);
}

int		player_turn_match(char *s, t_list *alphabet, int *alum)
{
  int		k;

  if (alphabet->flag_match == 2)
    {
      if (player_turn_match_error(s, alphabet, alum) == 1)
	return (2);
      k = my_getnbr(s);
      if (k <= alum[alphabet->line])
	{
	  alum[alphabet->line] = alum[alphabet->line] - k;
	  my_putstr("Player removed ");
	  my_put_nbr(k);
	  my_putstr(" match(es) from line ");
	  my_put_nbr(alphabet->line + 1);
	  my_putchar('\n');
	  alphabet->line = 0;
	  print_game_board(alum, alphabet);
	  if (game_over(alum, 1) == 1 || ai_turn(alphabet, alum) == 1)
	    return (1);
	}
    }
  alphabet->flag_match++;
  return (0);
}

int		player_turn_line(int *alum, char *s, t_list *alphabet)
{
  int		k;

  k = 0;
  if (alphabet->flag_line == 0)
    {
      if (check_number(s) == -1)
	k = -1;
      else
	k = my_getnbr(s);
      if (player_turn_line_error(k, alum) == 1)
      	{
      	  alphabet->flag_match--;
      	  return (1);
	}
      k = k - 1;
      alphabet->line = k;
      my_putstr("Matches: ");
    }
  alphabet->flag_line++;
  return (0);
}

int		main(int ac, char **av)
{
  char		*s;
  t_list	*alphabet;
  int		*alum;

  (void) ac;
  (void) av;
  alum = malloc_alum();
  alphabet = malloc_alphabet(alum);
  my_putchar('\n');
  my_putstr("\nYour turn:\nLine: ");
  while ((s = get_next_line(0)))
    {
      player_turn_line(alum, s, alphabet);
      if (player_turn_match(s, alphabet, alum) == 1)
	{
	  free(s);
	  return (1);
	}
      free(s);
    }
  return (0);
}
