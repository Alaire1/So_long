/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:55:25 by akaraban          #+#    #+#             */
/*   Updated: 2023/08/24 14:26:55 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_chcat(char *dest, char src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src [j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_col_fd(unsigned int n, int fd)
{
	unsigned int	nbr;
	char			*str;

	str = ft_strdup(GREEN);
	nbr = n;
	if (nbr >= 10)
		ft_putnbr_col_fd(nbr / 10, fd);
	str = ft_chcat(str, nbr % 10 + '0');
	str = ft_strcat(str, RESET);
	ft_putstr_fd(str, fd);
	free(str);
}
