/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:12:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/28 12:12:48 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//include

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//structure
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//prototype partie 1

//ft_atoi.c: OK!
int		ft_atoi(const char *theString);
//ft_bzero.c: OK!
void	ft_bzero(void *s, size_t n);
//ft_calloc.c: OK!
void	*ft_calloc(size_t Count, size_t size);
//ft_isalnum.c: OK!
int		ft_isalnum(int c);
//ft_isalpha.c: OK!
int		ft_isalpha(int c);
//ft_isascii.c: OK!
int		ft_isascii(int c);
//ft_isdigit.c: OK!
int		ft_isdigit(int c);
//ft_isprint.c: OK!
int		ft_isprint(int c);
//ft_memchr.c: OK!
void	*ft_memchr(const void *s, int c, size_t n);
//ft_memcmp.c: OK!
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//ft_memcpy.c: OK!
void	*ft_memcpy(void *destination, const void *source, size_t size);
//ft_memmove.c: OK!
void	*ft_memmove(void *destination, const void *source, size_t size);
//ft_memset.c: OK!
void	*ft_memset(void *pointeur, int value, size_t count);
//ft_strchr.c: OK!
char	*ft_strchr(const char *string, int searchedChar);
//ft_strdup.c: OK!
char	*ft_strdup(char *src);
//ft_strjoin.c: OK!
char	*ft_strjoin(char const *s1, char const *s2);
//ft_strlcat.c: OK!
size_t	ft_strlcat(char *s1, const char *s2, size_t n);
//ft_strlcpy.c: OK!
size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);
//ft_strlen.c: OK!
size_t	ft_strlen(const char *str);
//ft_strncmp.c: OK!
int		ft_strncmp(const char *first, const char *second, size_t length);
//ft_strnstr.c: OK!
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
//ft_strrchr.c: OK!
char	*ft_strrchr(const char *string, int searchedChar);
//ft_substr.c: OK!
char	*ft_substr(char const *s, unsigned int start, size_t len);
//ft_tolower.c: OK!
int		ft_tolower(int character);
//ft_toupper.c: OK!
int		ft_toupper(int character);

//prototype partie 2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const	*str, char charset);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//Bonus

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
