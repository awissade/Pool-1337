/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:52:39 by awissade          #+#    #+#             */
/*   Updated: 2023/08/26 11:09:37 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_signe(int *signe)
{
	if (*signe % 2 == 1)
		*signe = -1;
	else
		*signe = 1;
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	r;

	i = 0;
	signe = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	ft_signe(&signe);
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * signe);
}
