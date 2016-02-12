/*
** main.c for allum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 14:50:12 2016 Voyevoda
** Last update Fri Feb 12 19:06:01 2016 Voyevoda
*/
#include <stdio.h>
#include <stdlib.h>
#include "./include/get_next_line.h"
#include "./include/fct.h"
#include "./include/list.h"

int		player_turn_match(char *s, t_list *alphabet, int *alum)
{
  int		k;
  static int	flag = 0;

  if (flag == 1)
    {
      k = my_getnbr(s);
      if (alphabet->line + 1 <= 0)
	my_putstr("Error: invalid input (positive number expected");
      else if (k < alum[alphabet->line + 1])
	alum[alphabet->line] = alum[alphabet->line] - k;
      else
	alum[alphabet->line] = 0;
      my_putstr("Player removed ");
      my_put_nbr(k);
      my_putstr(" match(es) from line ");
      my_put_nbr(alphabet->line + 1);
      my_putchar('\n');
      print_game_board(alum);
    }
  flag++;
  if (flag == 2)
    flag = 0;
  return (0);
}

int		player_turn_line(char *s, t_list *alphabet)
{
  int		k;
  static int	flag = 0;

  if (flag == 0)
    {
      k = my_getnbr(s);
      if (k < 0 || k > 4)
	my_putstr("error impossible number");
      else
	{
	  alphabet->line = k - 1;
	  my_putstr("Matches: ");
	}
    }
  flag++;
  if (flag == 2)
    flag = 0;
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
