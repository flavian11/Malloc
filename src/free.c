/*
** free.c for  in /home/flav/epitech/CPE/rush/CPE_rush4stek_2016/m
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sat Jun  3 22:11:51 2017 flav
** Last update Sat Jun  3 22:39:04 2017 flav
*/

#include <assert.h>
#include <unistd.h>
#include "malloc.h"

void		free(void *ptr)
{
  t_block	*ptr_meta;

  if (ptr == NULL)
    return ;
  ptr_meta = (t_block *)ptr - 1;
  assert(ptr_meta->free == 1);
  ptr_meta->free = 0;
}
