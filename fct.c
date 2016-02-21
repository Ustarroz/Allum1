/*
** fct.c for alum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Sat Feb 20 17:08:30 2016 Voyevoda
** Last update Sun Feb 21 17:45:33 2016 Voyevoda
*/

#include <stdlib.h>
#include <unistd.h>
#include "./include/list.h"
#include "./include/fct.h"
#include <time.h>

int	my_rand(int b, int a)
{
  if (b == a)
    return (a);
  srand(time(NULL));
  return (rand() % (b - a) + a);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	game_over(int *alum, int flag)
{
  int	total;

  total = alum[0] + alum[1] + alum[2] + alum[3];
  if (total == 0 && flag == 0)
    {
      my_putstr("\nI lost.. snif.. bul I'll get you next time!!\n");
      return (1);
    }
  if (total == 0 && flag == 1)
    {
      my_putstr("\nYou lost, too bad..\n");
	return (1);
    }
  return (0);
}

int	player_turn_line_error(int k, int *alum)
{
  if (k > 4 || k == 0)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (1);
    }
  if (k < 0 || (k < '0' && k > '9'))
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (1);
    }
  if (alum[k - 1] == 0)
    {
      my_putstr("Error: this line is empty\nLine: ");
      return (1);
    }
  return (0);
}

int	check_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (- 1);
      i++;
    }
  if (i == 0)
    return (- 1);
  return (0);
}
