/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <alprival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:15:23 by argomez           #+#    #+#             */
/*   Updated: 2022/12/21 20:40:14 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define DECIMAL "0123456789"
# define HEXADECIMAL "0123456789abcdef"

typedef struct s_printf_fd
{
	va_list	parameters;
	int		file_descriptor;
	int		return_value;
}	t_printf_fd;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//CHARS
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

//DISPLAYS
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//LISTS
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

//MEMORIES
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *s, size_t n);
void		*ft_memmove(void *dest, const void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);

//STRS
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strchrc(const char *s, int c);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_char(char *s1, char c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char	*dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_extension(const char *str, const char *ext);

//UTILS
long long	ft_atoi(char *nptr);
char		*ft_itoa(int n);
int			is_tab_sorted(long int *tab, int size);
long long	ft_btod(int *numbers);
void		ft_sort_int_tabs(int *array, int size);

//PRINTF
int			ft_printf(const char *format, ...);
void		ft_printf_char(char c, int *ptr);
void		ft_printf_str(char *str, int *ptr);
void		ft_printf_nbr(unsigned long long nb, char *base, int *ptr);
void		ft_printf_decimal(int nb, int *ptr);
void		ft_printf_hexa(unsigned int nb, char c, int *ptr);
void		ft_printf_ptr(unsigned long long nb, int *ptr);
void		ft_printf_unsigned(unsigned int nb, int *ptr);

//PRINTF_FD
int			ft_printf_fd(int file_descriptor, const char *args, ...);
void		display_char(t_printf_fd *datas, char c);
void		display_string(t_printf_fd *datas, char *string);
void		print_string(t_printf_fd *datas);
void		print_decimal(t_printf_fd *datas);
void		print_hexadecimal(t_printf_fd *datas);
void		print_number(t_printf_fd *datas, long long int number, char *base);
void		print_pointer(t_printf_fd *datas);

//GNL
char		*get_next_line(int fd);
char		*ft_strjoin_malloc(char *s1, char *s2);
char		*ft_strjoin_malloc_env(char *s1, char *s2);

#endif
