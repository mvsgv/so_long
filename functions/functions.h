/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:49:26 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 15:15:02 by mavissar         ###   ########.fr       */
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
int     ft_strlen(char *str);
char	*ft_strjoin(char*s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);
char    *ft_strchr(char *s);
char	*next_line(char **string);
char	*read_line(int fd, char *to_save, char *buffer);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif