/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:07:04 by awissade          #+#    #+#             */
/*   Updated: 2023/08/17 05:37:18 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printing(char a1, char a2, char b1, char b2)
{
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}

void	int_to_char(int a, int b)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0' + (a / 10);
	a2 = '0' + (a % 10);
	b1 = '0' + (b / 10);
	b2 = '0' + (b % 10);
	ft_printing(a1, a2, b1, b2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			int_to_char(a, b);
			if (a < 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
