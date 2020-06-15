/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 22:24:50 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:11:31 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar(char c);
void	ft_putendl(char const *s);
void	ft_putstr(char const *str);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strnew(size_t size);

#endif
