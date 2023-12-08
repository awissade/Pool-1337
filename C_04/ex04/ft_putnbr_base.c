/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:12:20 by awissade          #+#    #+#             */
/*   Updated: 2023/08/28 15:13:34 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '-'
				|| base[j] == '+' || base[i] == '-' || base[i] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	printing(long n, int i, char *base)
{
	int	x;

	x = 1;
	while (n / x >= i)
		x = x * i;
	while (x >= 1)
	{
		write (1, &base[n / x], 1);
		n = n % x;
		x = x / i;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		c;
	long	n;

	n = nbr;
	c = check(base);
	if (c < 1)
		return ;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	printing(n, c, base);
}
