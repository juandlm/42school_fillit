/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 21:49:21 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:15:07 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	tetrimino_minmax(uint8_t *x, uint8_t *y, t_coord *min, t_coord *max)
{
	uint8_t	i;

	i = 0;
	while (i < 4)
	{
		min->y = y[i] < min->y ? y[i] : min->y;
		max->y = y[i] > max->y ? y[i] : max->y;
		min->x = x[i] < min->x ? x[i] : min->x;
		max->x = x[i] > max->x ? x[i] : max->x;
		i++;
	}
}

char	**tetrimino_narrow(t_tetri piece, t_coord *min, const char *tetrimino)
{
	uint8_t	i;
	uint8_t	j;
	uint8_t	k;
	uint8_t	start;
	char	**pos;

	i = 0;
	j = 0;
	start = min->y * 5 + min->x;
	pos = (char **)ft_memalloc(sizeof(char *) * piece.height);
	while (i < piece.height)
	{
		k = 0;
		if (!(pos[i] = ft_strndup(tetrimino + start + j, piece.width)))
			return (NULL);
		while (pos[i][k])
		{
			if (pos[i][k] == '#')
				pos[i][k] = piece.letter;
			k++;
		}
		i++;
		j += 5;
	}
	return (pos ? pos : NULL);
}

t_tetri	tetrimino_build(const char *tetrimino, char letter)
{
	uint8_t coords[3];
	t_tetri piece;
	t_coord	*min;
	t_coord	*max;

	ft_memset(coords, 0, 3);
	piece = (t_tetri){letter, {0, 0, 0, 0}, {0, 0, 0, 0}, 0, 0, NULL};
	min = fillit_new_coord(4, 4);
	max = fillit_new_coord(0, 0);
	while (tetrimino[_X])
	{
		if (tetrimino[_X] == '#')
		{
			piece.x[_Z] = _X % 5;
			piece.y[_Z++] = _Y;
		}
		tetrimino[_X++] == '\n' ? _Y++ : _Y;
	}
	tetrimino_minmax(piece.x, piece.y, min, max);
	piece.width = max->x - min->x + 1;
	piece.height = max->y - min->y + 1;
	piece.pos = tetrimino_narrow(piece, min, tetrimino);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}

uint8_t	tetrimino_validation(const char *buffer, uint8_t endnl)
{
	t_input	b_stat;
	uint8_t	i;

	b_stat = (t_input){0, 0, 0, 0};
	i = 0;
	if (buffer[i] && (buffer[i] != '#' && buffer[i] != '.'))
		return (0);
	while (buffer[i])
	{
		buffer[i] == '.' ? b_stat.dots++ : b_stat.dots;
		if (buffer[i] == '#')
		{
			b_stat.hashes++;
			b_stat.adjacent += (buffer[i + 5] == '#') + (buffer[i - 5] == '#')
							+ (buffer[i + 1] == '#') + (buffer[i - 1] == '#');
		}
		buffer[i++] == '\n' ? b_stat.nlines++ : b_stat.nlines;
	}
	if (!endnl && buffer[20] != '\n')
		return (0);
	return ((buffer[4] == '\n' && buffer[9] == '\n'
			&& buffer[14] == '\n' && buffer[19] == '\n')
			&& b_stat.dots == 12 && b_stat.hashes == 4
			&& (b_stat.nlines + endnl) == 5
			&& (b_stat.adjacent == 6 || b_stat.adjacent == 8));
}

uint8_t	fillit_read_file(const int fd, t_tetri *tetriminos)
{
	char	letter;
	char	buffer[TETRI_SIZE + 1];
	uint8_t	rbytes;
	uint8_t	endnl;
	uint8_t	i;

	letter = 'A';
	endnl = 0;
	i = 0;
	while ((rbytes = read(fd, buffer, TETRI_SIZE)) >= 20)
	{
		buffer[rbytes] = '\0';
		endnl += (rbytes == 20);
		if (!tetrimino_validation(buffer, endnl))
			return (0);
		tetriminos[i] = tetrimino_build(buffer, letter++);
		if (!tetriminos[i].pos)
			return (0);
		i++;
	}
	return ((rbytes || !endnl) ? 0 : letter - 'A');
}
