/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:43:52 by awissade          #+#    #+#             */
/*   Updated: 2023/08/26 08:50:47 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	if_positif(int nb)
{
	char	a;
	int		i;

	i = 1;
	while (nb / i >= 10)
		i = i * 10;
	while (i >= 1)
	{
		a = '0' + (nb / i);
		nb = nb % i;
		i = i / 10;
		write(1, &a, 1);
	}
}

void	if_negatif(int nb)
{
	write(1, "-", 1);
	nb = nb * (-1);
	if_positif(nb);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		if_positif(nb);
	else
	{
		if (nb != -2147483648)
			if_negatif(nb);
		else
			write(1, "-2147483648", 11);
	}
}
