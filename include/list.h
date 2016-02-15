/*
** list.h for alum1 in /home/voyevoda/rendu/prog_elem/CPE_2015_Allum1/include
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Wed Feb 10 16:45:31 2016 Voyevoda
** Last update Mon Feb 15 15:06:59 2016 Voyevoda
*/

#ifndef LIST_H_
#define LIST_H_

struct l_list
{
  int	*v_line;
  int	line;
  int	flag_line;
  int	flag_match;
  int	flag_ia;
  int	game_over;
};
typedef struct l_list t_list;

#endif /*LIST_H_*/
