/*
** calloc.c for  in /home/flav/epitech/CPE/rush/CPE_rush4stek_2016/m
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sat Jun  3 22:28:21 2017 flav
** Last update Sat Jun  3 22:35:05 2017 flav
*/

#include <sys/types.h>
#include <string.h>
#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  if (size == 0 || nmemb == 0)
    return (NULL);
  size = nmemb * size;
  ptr = malloc(size);
  memset(ptr, 0, size);
  return (ptr);
}
