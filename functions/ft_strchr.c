/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:03:53 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/05 14:45:55 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

// int	ft_strchr(char *s, char *c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (c[j] == '\0' && s[i] == '\0')
// 		return (1);
// 	while (s[i])
// 	{
// 		while (s[i + j] == c[j] && s[i + j] && c[j])
// 			j++;
// 		if (c[j] == '\0' && s[i + j] == '\0')
// 			return (1);
// 		else
// 			j = 0;
// 		i++;
// 	}
// 	return (0);
// }
/*int		main()
{
	char	s[] = "ouf that was hot";
	int	c = 't'; 
	printf("%s", ft_strchr(s, c));
	printf("%s", strchr(s, c));
}*/