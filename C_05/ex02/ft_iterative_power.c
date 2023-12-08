/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:02:42 by awissade          #+#    #+#             */
/*   Updated: 2023/08/30 09:26:18 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	resault;

	i = 1;
	resault = 1;
	if (power < 0)
		return (0);
	while (i <= power)
	{
		resault = resault * nb;
		i++;
	}
	return (resault);
}
