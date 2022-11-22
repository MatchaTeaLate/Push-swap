/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:17:47 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/22 23:29:21 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);

char		**ft_split(const char *str, char c);

void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t type, size_t size);
void		*ft_memset(void *s, int c, size_t n);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);

char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char*str, int c);
char		*ft_strdup(const char *s);
char		*ft_itoa(int n);

long long	ft_atoi(const char *str);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_lstsize(t_list *lst);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
