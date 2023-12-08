/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:16:49 by awissade          #+#    #+#             */
/*   Updated: 2023/08/29 10:03:41 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printing(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			write (1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		x;
	char	*tab;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			x = 0;
			while (av[i][x] == av[j][x])
				x++;
			if (av[i][x] > av[j][x])
			{
				tab = av[i];
				av[i] = av[j];
				av[j] = tab;
			}
			j++;
		}
		i++;
	}
	printing(ac, av);
}
