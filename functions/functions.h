/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:49:26 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/04 18:47:03 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_putstr_fd(char *s, int fd);
size_t     ft_strlen(char *str);
char	*ft_strjoin(char*s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);
int	    get_next_line(int fd, char **str);
int     ft_strchr(char *s, char *c);
char	**ft_split(char *s, char c);
char	*ft_strch(char *string);



#endif