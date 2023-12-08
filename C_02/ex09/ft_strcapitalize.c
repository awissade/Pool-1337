/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:54:31 by awissade          #+#    #+#             */
/*   Updated: 2023/08/21 15:01:53 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_character(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if (str[i - 1] < '0'
			|| (str[i - 1] > '9' && str[i - 1] < 'A')
			|| (str[i - 1] > 'Z' && str[i - 1] < 'a')
			|| str[i - 1] > 'z')
		{
			str[i] = str[i] - ('a' - 'A');
		}
	}
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
			|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
		{
			str[i] = str[i] + ('a' - 'A');
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[0] >= 'a' && str[0] <= 'z'))
		{
			str[0] = str[0] - ('a' - 'A');
			i++;
		}
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			ft_character(str, i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
