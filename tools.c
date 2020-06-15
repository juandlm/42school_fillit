/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 17:14:14 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:13:20 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	*fillit_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	fillit_del_tetri(t_tetri *tetriminos, uint8_t count)
{
	uint8_t	i;
	uint8_t	y;

	i = 0;
	while (i < count)
	{
		y = 0;
		while (y < tetriminos[i].height)
		{
			ft_memdel((void **)&(tetriminos[i].pos[y]));
			y++;
		}
		ft_memdel((void**)&(tetriminos[i].pos));
		i++;
	}
	tetriminos = NULL;
}

void	fillit_del_grid(t_grid *grid)
{
	uint8_t i;

	i = 0;
	while (i < grid->size)
	{
		ft_memdel((void **)&(grid->str[i]));
		i++;
	}
	ft_memdel((void **)&(grid->str));
	ft_memdel((void **)&grid);
}

void	fillit_print(t_grid *grid)
{
	uint8_t i;

	i = 0;
	while (i < grid->size)
	{
		ft_putendl(grid->str[i]);
		i++;
	}
}

t_coord	*fillit_new_coord(uint8_t x, uint8_t y)
{
	t_coord		*loc;

	loc = (t_coord *)ft_memalloc(sizeof(t_coord));
	loc->x = x;
	loc->y = y;
	return (loc);
}
