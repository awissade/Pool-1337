/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:45 by awissade          #+#    #+#             */
/*   Updated: 2023/09/05 02:32:42 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*creat_tab(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*tab;

	len = 0;
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1);
	if (size <= 0)
		len = 0;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == 0)
		return (0);
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		x;
	int		j;

	tab = creat_tab(size, strs, sep);
	i = 0;
	j = 0;
	while (j < size)
	{
		x = 0;
		while (strs[j][x] != '\0')
			tab[i++] = strs[j][x++];
		x = 0;
		while (sep[x] != '\0' && j < size - 1)
			tab[i++] = sep[x++];
		j++;
	}
	tab[i] = '\0';
	return (tab);
}
