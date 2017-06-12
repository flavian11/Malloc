/*
** struct.h for  in /home/flav/epitech/CPE/rush/CPE_rush4stek_2016/m
** 
** Made by flav
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sat Jun  3 18:40:03 2017 flav
** Last update Sat Jun  3 22:35:55 2017 flav
*/

#pragma once

#include <sys/types.h>

typedef struct s_block	t_block;

struct		s_block
{
  size_t	size;
  int		free;
  int		magic;
  t_block	*next;
};

void		*malloc(size_t size);
