/*
** main.c for allum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 14:50:12 2016 Voyevoda
** Last update Wed Feb 17 20:28:46 2016 Voyevoda
*/
#include <stdio.h>
#include <stdlib.h>
#include "./include/get_next_line.h"
#include "./include/fct.h"
#include "./include/list.h"

int	my_rand(int b)
{
  return (rand()%(b-0) + 0);
}

int	ai_turn(t_list *alphabet, int *alum)
{
  int	line;
  int	matches;

  my_putchar('a');
  while (alum[my_rand(3)] < 0)
    {
      line = alum[my_rand(3)];
      if (alum[my_rand(3)] > 0)
	{
	  matches = my_rand(alum[line]);
	  alum[line] = alum[line] - matches;
	}
      my_putstr("IA removed ");
      my_put_nbr(matches);
      my_putstr(" match(es) from line ");
      my_put_nbr(line + 1);
      my_putchar('\n');
      print_game_board(alum, alphabet);
      alphabet->flag_line = 0;
      my_putchar('\n');
      my_putstr("Your turn:\nLine : ");
    }
  alphabet->flag_line = 0;
  return (0);
}

int	player_turn_match_error(char *s, t_list *alphabet, int *alum)
{
  if (alphabet->line + 1 <= 0)
    {
      my_putstr("Error: invalid input (positive number expected");
      return (1);
    }
  return (0);
}

int		player_turn_match(char *s, t_list *alphabet, int *alum)
{
  int		j;
  int		k;

  if (alphabet->flag_match == 2)
    {
      if ((j = player_turn_match_error) == 1)
	return (1);
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
	  ai_turn(alphabet, alum);
	}
    }
  alphabet->flag_match++;
  return (0);
}

int		player_turn_line(char *s, t_list *alphabet)
{
  int		k;

  if (alphabet->flag_line == 0)
    {
      k = my_getnbr(s);
      if (k < 0 || k > 5)
	my_putstr("error impossible number");
      else
	{
	  k = k - 1;
	  printf("%d", k);
	  alphabet->line = k;
	  my_putstr("Matches: ");
	}
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
  alum = malloc_alum(alum, alphabet);
  my_putchar('\n');
  my_putstr("Your turn:\nLine : ");
  while ((s = get_next_line(0)))
    {
      player_turn_line(s, alphabet);
      player_turn_match(s, alphabet, alum);
      free(s);
    }
  return (0);
}
