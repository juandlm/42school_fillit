/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:20:47 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:13:37 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	tetrimino_place(t_tetri *tetriminos, t_grid *grid,
						uint8_t x, uint8_t y)
{
	uint8_t i;
	uint8_t j;

	i = 0;
	while (i < tetriminos->width)
	{
		j = 0;
		while (j < tetriminos->height)
		{
			if (tetriminos->pos[j][i] != '.' && grid->str[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	tetrimino_set(tetriminos, grid, fillit_new_coord(x, y), tetriminos->letter);
	return (1);
}

void	tetrimino_set(t_tetri *tetriminos, t_grid *grid, t_coord *loc, char c)
{
	uint8_t i;
	uint8_t j;

	i = 0;
	while (i < tetriminos->width)
	{
		j = 0;
		while (j < tetriminos->height)
		{
			if (tetriminos->pos[j][i] != '.')
				grid->str[loc->y + j][loc->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&loc);
}

uint8_t	fillit_solver(t_grid *grid, t_tetri *tetriminos)
{
	uint8_t x;
	uint8_t y;

	if (!tetriminos->letter)
		return (1);
	y = 0;
	while (y < grid->size - tetriminos->height + 1)
	{
		x = 0;
		while (x < grid->size - tetriminos->width + 1)
		{
			if (tetrimino_place(tetriminos, grid, x, y))
			{
				if (fillit_solver(grid, tetriminos + 1))
					return (1);
				else
					tetrimino_set(tetriminos, grid,
					fillit_new_coord(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_grid	*fillit_new_grid(uint8_t size, t_grid *grid)
{
	uint8_t		i;
	uint8_t		j;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->str = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		grid->str[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			grid->str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

t_grid	*fillit_solution(t_tetri *tetriminos, uint8_t count)
{
	t_grid	*grid;
	uint8_t	size;

	size = 2;
	grid = NULL;
	while ((size * size) < count * 4)
		size++;
	grid = fillit_new_grid(size, grid);
	while (!fillit_solver(grid, tetriminos))
	{
		size++;
		fillit_del_grid(grid);
		grid = fillit_new_grid(size, grid);
	}
	return (grid);
}
