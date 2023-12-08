/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:50:44 by awissade          #+#    #+#             */
/*   Updated: 2023/09/07 22:03:58 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_char_instr(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_row(char *str, char *sep, int x)
{
	int	i;
	int	row;

	row = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_char_instr(sep, str[i]))
			i++;
		if (x == 0)
			return (i);
		if (str[i] != 0)
			row++;
		while (str[i] && !ft_char_instr(sep, str[i]))
			i++;
		if (x == 1)
			return (i);
	}
	return (row);
}

char	*ft_create_row(char *str, char *sep)
{
	int		i;
	char	*pt;
	int		len;
	int		j;

	j = 0;
	i = ft_count_row(str, sep, 0);
	len = ft_count_row(str, sep, 1);
	pt = (char *)malloc(len - i + 1);
	if (!pt)
		return (NULL);
	while (i < len)
	{
		pt[j] = str[i];
		i++;
		j++;
	}
	pt[j] = '\0';
	return (pt);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		row;
	char	**pt;

	i = 0;
	row = ft_count_row(str, charset, 10) + 1 ;
	pt = (char **)malloc(row * sizeof(char *));
	while (*str != '\0')
	{
		while (*str && ft_char_instr(charset, *str))
			str++;
		if (*str)
		{
			pt[i] = ft_create_row(str, charset);
			i++;
		}
		while (*str && !ft_char_instr(charset, *str))
			str++;
	}
	pt[i] = 0;
	return (pt);
}
