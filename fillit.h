/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 21:17:05 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:14:39 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_TETRI 26
# define TETRI_SIZE 21
# define _X coords[0]
# define _Y coords[1]
# define _Z coords[2]

# include "./libft/libft.h"

# include <unistd.h>
// # include <inttypes.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_coord
{
	uint8_t		x;
	uint8_t		y;
}				t_coord;

typedef struct	s_grid
{
	uint8_t		size;
	char		**str;
}				t_grid;

typedef struct	s_input
{
	uint8_t		dots;
	uint8_t		hashes;
	uint8_t		nlines;
	uint8_t		adjacent;
}				t_input;

typedef struct	s_tetri
{
	char		letter;
	uint8_t		x[4];
	uint8_t		y[4];
	uint8_t		width;
	uint8_t		height;
	char		**pos;
}				t_tetri;

void			*fillit_exit(char *str);
void			fillit_del_tetri(t_tetri *tetriminos, uint8_t count);
void			fillit_del_grid(t_grid *grid);
void			fillit_print(t_grid *grid);
t_coord			*fillit_new_coord(uint8_t x, uint8_t y);
uint8_t			fillit_read_file(const int fd, t_tetri *tetriminos);
t_grid			*fillit_solution(t_tetri *tetriminos, uint8_t count);
void			tetrimino_set(t_tetri *tetri, t_grid *grid, t_coord *loc,
				char c);

#endif
