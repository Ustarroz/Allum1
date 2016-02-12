/*
** my_put_nbr.c for my_put_nbr in /home/ustarr_r/rendu
**
** Made by Ustarroz Robin
** Login   <ustarr_r@epitech.net>
**
** Started on  Fri Oct  9 19:11:39 2015 Ustarroz Robin
** Last update Fri Feb 12 15:10:24 2016 Voyevoda
*/
#include "./include/fct.h"

int	my_put_nbr(int nb)
{
  int	a;

  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
  if (nb > 0)
    {
      a = nb%10;
      nb = nb/10;
      my_put_nbr(nb);
      my_putchar(48 + a);
    }
  return (0);
}
