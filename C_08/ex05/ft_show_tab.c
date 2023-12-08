/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:36:00 by awissade          #+#    #+#             */
/*   Updated: 2023/09/06 02:27:18 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

void	conver_size(int size)
{
	long	nbr;
	long	i;
	char	num[20];
	int		x;

	nbr = size;
	i = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr / i >= 10)
		i *= 10;
	x = 0;
	while (i >= 1)
	{
		num[x] = ('0' + (nbr / i));
		nbr = nbr % i;
		i = i / 10;
		x++;
	}
	num[x] = '\0';
	print_str(num);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		print_str(par[i].str);
		write(1, "\n", 1);
		conver_size(par[i].size);
		write(1, "\n", 1);
		print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
