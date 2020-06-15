/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 21:21:12 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:13:34 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetri	tetriminos[MAX_TETRI + 1];
	t_grid	*grid;
	uint8_t	count;

	if (argc == 2)
	{
		grid = NULL;
		ft_bzero(tetriminos, sizeof(t_tetri) * (MAX_TETRI + 1));
		count = fillit_read_file(open(argv[1], O_RDONLY), tetriminos);
		if (count == 0 || count > 26 ||
			(grid = fillit_solution(tetriminos, count)) == NULL)
		{
			if (tetriminos->pos)
				fillit_del_tetri(tetriminos, count);
			fillit_exit("error");
		}
		fillit_print(grid);
		fillit_del_grid(grid);
		fillit_del_tetri(tetriminos, count);
	}
	else
		ft_putendl("usage: fillit input_file");
	return (0);
}
