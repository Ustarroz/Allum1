/*
** malloc.c for allum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Sun Feb 21 13:23:27 2016 Voyevoda
** Last update Sun Feb 21 13:40:11 2016 Voyevoda
*/

#include <stdlib.h>
#include <unistd.h>
#include "./include/list.h"
#include "./include/fct.h"

t_list	*malloc_alphabet(int *alum)
{
  t_list *alphabet;

  alphabet = malloc(sizeof(t_list));
  alphabet->v_line = malloc(sizeof(int*) * (4));
  alphabet->v_line[0] = 1;
  alphabet->v_line[1] = 3;
  alphabet->v_line[2] = 5;
  alphabet->v_line[3] = 7;
  alphabet->flag_line = 0;
  alphabet->flag_match = 1;
  alphabet->flag_ia = 1;
  alphabet->game_over = 0;
  print_game_board(alum, alphabet);
  return (alphabet);
}
