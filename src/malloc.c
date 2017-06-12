/*
** malloc.c for  in /home/flav/epitech/CPE/rush/CPE_rush4stek_2016/m
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sat Jun  3 18:36:09 2017 flav
** Last update Sat Jun  3 22:37:24 2017 flav
*/

#include <sys/types.h>
#include <unistd.h>
#include "malloc.h"

t_block	*g_start = NULL;
t_block	*g_prev = NULL;

t_block		*can_reuse(size_t size)
{
  t_block	*tmp;

  tmp = g_start;
  while (tmp && (tmp->size > size || tmp->free == 1))
    tmp = tmp->next;
  return (tmp);
}

void		*malloc(size_t size)
{
  t_block	*res;

  if (size <= 0)
    return (NULL);
  if ((res = can_reuse(size)) != NULL)
    return (res + 1);
  if ((res = sbrk(size + sizeof(t_block))) == (void *)-1)
    return (NULL);
  res->size = size;
  res->free = 1;
  res->magic = 0xDEADBEEF;
  res->next = NULL;
  if (g_start == NULL)
    g_start = res;
  if (g_prev != NULL)
    g_prev->next = res;
  g_prev = res;
  return (res + 1);
}
