/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:11:55 by awissade          #+#    #+#             */
/*   Updated: 2023/08/22 21:35:52 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hexa;
	unsigned char	t7wil;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			t7wil = (unsigned char)str[i];
			write(1, "\\", 1);
			write(1, &hexa [t7wil / 16], 1);
			write(1, &hexa [t7wil % 16], 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
