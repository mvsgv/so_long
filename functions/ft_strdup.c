/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:37:27 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 08:30:59 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
// int	main()
// {
// 	const char	s1[] = "'\0'";

// 	printf("my function : %s/n", ft_strdup(((void *)0)));
// 	printf("original one : %s", strdup(((void *)0)));
// }