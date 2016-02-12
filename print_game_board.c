/*
** print_game_board.c for alum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_allum1_bootstrap
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 12:04:49 2016 Voyevoda
** Last update Fri Feb 12 19:28:38 2016 Voyevoda
*/
#include <stdlib.h>
#include <unistd.h>
#include "./include/list.h"
#include "./include/fct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void print_stars()
{
  int	i;

  i = 0;
  while (i < 9)
    {
      my_putchar('*');
      i++;
    }
}

int	print_line(int *alum1, int i,int count)
{
  int space;
  int	k;
  int	j;

  k = 0;
  j = 0;
  count = 0;
  space = (7 - alum1[i]) / 2;
  my_putchar('*');
  while (k < space)
    {
      my_putchar(' ');
      k++;
      count++;
    }
  if (k == space)
    {
      while (j < alum1[i])
	{
	  my_putchar('|');
	  j++;
	  count++;
	}
    }
  return (count);
}

void	print_game_board(int *alum1)
{
  int	i;
  int	k;
  int	space;
  int	count;

  i = 0;
  print_stars();
  my_putchar('\n');
  while (i < 4)
    {
      count =  print_line(alum1, i, count);
      space = (7 - alum1[i]) /2;
      while (count < 7)
	{
	  my_putchar(' ');
	  count++;
	  k++;
	}
      my_putchar('*');
      my_putchar('\n');
      i++;
      k = 0;
    }
  print_stars();
}

int	*malloc_alum(int *alum1, t_list *alphabet)
{
  alum1 = malloc(sizeof(int*) * (4));
  alum1[0] = 1;
  alum1[1] = 3;
  alum1[2] = 5;
  alum1[3] = 7;
  alphabet->L1 = 1;
  alphabet->L2 = 3;
  alphabet->L3 = 5;
  alphabet->L4 = 7;
  print_game_board(alum1);
  return (alum1);
}
