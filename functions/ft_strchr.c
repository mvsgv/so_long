/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:03:53 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 10:16:50 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_strchr(char *s, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '\0' && c[j] == '\0')
		return (1);
	while (s[i])
	{
		while (s[i + j] == c[j] && s[i + j] && c[j])
			j++;
		if (s[i] == '\0' && c[j + i] == '\0')
			return (1);
		else
			j = 0;
		i++;
	}
	return (0);
}
/*int		main()
{
	char	s[] = "ouf that was hot";
	int	c = 't'; 
	printf("%s", ft_strchr(s, c));
	printf("%s", strchr(s, c));
}*/