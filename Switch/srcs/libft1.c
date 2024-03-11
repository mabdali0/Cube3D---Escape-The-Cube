/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By:  mabdali <mabdali@student.42perpignan.fr>    +#+  +:+       +#+        */
/*    rloussig <rloussig@student.42perpignan.fr>  +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	int			j;
	char		diff;

	if (((to_find == 0 || str == 0) && len == 0) || !ft_strlen(to_find))
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		diff = 0;
		while (str[i + j] && !diff && i + j < len)
		{
			if (!to_find[j])
				return ((char *)(str + i));
			else if (!(to_find[j] == str[i + j]))
				diff = 1;
			j++;
		}
		if (!diff && !to_find[j])
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	diff;

	if (((to_find == 0 || str == 0)) || !ft_strlen(to_find))
		return ((char *)str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		diff = 0;
		while (str[i + j] && !diff)
		{
			if (!to_find[j])
				return ((char *)(str + i));
			else if (!(to_find[j] == str[i + j]))
				diff = 1;
			j++;
		}
		if (!diff && !to_find[j])
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	c;
	size_t	i;

	str = &c;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[i] && start < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	int		res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (minus * res);
}
