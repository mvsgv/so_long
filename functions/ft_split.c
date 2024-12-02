/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:34:25 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:19 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

// static void	ft_free(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	if (arr)
// 	{
// 		while (arr[i])
// 		{
// 			free (arr[i]);
// 			i++;
// 		}
// 		free(arr);
// 	}
// }

// static int	word_count(const char *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	return (count);
// }

// static char	*make_tab(const char *start, const char *end)
// {
// 	char	*str;
// 	int		i;

// 	str = (char *)malloc(end - start + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (start < end)
// 		str[i++] = *start++;
// 	str[i] = '\0';
// 	return (str);
// }

// static int	if_dont_work(char **result, int i)
// {
// 	if (!result[i - 1])
// 	{
// 		ft_free(result);
// 		return (1);
// 	}
// 	return (0);
// }

// char	**ft_split(char *s, char c)
// {
// 	char		**result;
// 	const char	*start;
// 	int			i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (!*s)
// 			continue ;
// 		start = s;
// 		while (*s && *s != c)
// 			s++;
// 		result[i++] = make_tab(start, s);
// 		if (if_dont_work(result, i))
// 			return (NULL);
// 	}
// 	result[i] = NULL;
// 	return (result);
// }

// // static int	nbr_words(const char *s, char c)
// // {
// // 	int	count;
// // 	int	i;
// // 	int	len;

// // 	count = 0;
// // 	i = 0;
// // 	if (!s)
// // 		return (0);
// // 	len = ft_strlen(s);
// // 	while (i < len && s[i])
// // 	{
// // 		while (s[i] && s[i] == c)
// // 			i++;
// // 		while (s[i] && s[i] != c)
// // 			i++;
// // 		if (i < len)
// // 			count++;
// // 	}
// // 	return (count);
// // }

// // char	**ft_split(char const *s, char c)
// // {
// // 	int		i;
// // 	int		j;
// // 	char	**tab;
// // 	int		nbr_w;

// // 	nbr_w = nbr_words(s, c);
// // 	i = 0;
// // 	tab = (char **)malloc((nbr_w + 1) * sizeof(char *));
// // 	if (!s || !tab)
// // 		return (NULL);
// // 	j = 0;
// // 	while (j < nbr_w)
// // 	{
// // 		while (check_sep(s[i], c) == 0 && s[i])
// // 			i++;
// // 		while (check_sep(s[i], c) == 1 && s[i])
// // 		{
// // 			tab[j++] = ft_substr(s, i, ft_strlen(&s[i])
// // 					- ft_strlen(ft_strchr(&s[i], c)));
// // 			while (check_sep(s[i], c) == 1 && s[i])
// // 				i++;
// // 		}
// // 	}
// // 	tab[j] = 0;
// // 	return (tab);
// // }
static char	*ft_strncpy(char *str, int nb)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (nb + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i] && i < nb)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
static int	ft_charcpt(char *str, char chr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == chr)
			ret++;
		i++;
	}
	return (ret);
}

static int	ft_strnchr(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		y;
	int		cpt;
	char	**ret;

	i = 0;
	y = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_charcpt(str, sep) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		cpt = ft_strnchr(&str[i], sep);
		ret[y] = ft_strncpy(&str[i], cpt);
		if (str[i + cpt] != '\0')
			i += (cpt + 1);
		else
			i += cpt;
		y++;
	}
	ret[y] = NULL;
	free(str);
	return (ret);
}