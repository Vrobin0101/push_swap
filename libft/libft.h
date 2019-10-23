/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:51:42 by spuisais          #+#    #+#             */
/*   Updated: 2019/10/23 08:51:43 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 500
# define DET detail

typedef struct		s_detail
{
	int						strlen;
	int						sign;
	int						number;
	int						field;
	int						precision;
	int						zero;
	int						maj;
	int						diese;
	int						oct;
	int						iflong;
	int						ifshort;
	int						minus;
	int						plus;
	int						space;
	int						hexa;
	int						nega;
	int						iffloat;
	int						overbuff;
	long long unsigned int	len;
	char					*hexachar;
}					t_detail;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinf(char **s1, char **s2, int k);
char				*ft_strtrim(char const *s);
char				*ft_itoa(long long n);
char				*ft_litoa(long long n);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa_base(long long value, char *base);
char				*ft_fritoa_base(long long value, char *base);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strskip(const char *str, char c);
const char			*print_until(char *format, int *len);
int					ft_high_sqrt(int nb);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long int			ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
unsigned long long	ft_itooct(unsigned long long nb);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_print_words_table(char **tab);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_printf(const char *format, ...);
int					bol_nine(char *tmp);
char				*edit_ret(char *buff, char *string, t_detail *detail);
char				*edit_point(char *buff, char *string, t_detail *detail);
char				*point_inf(char *buff, char *string, t_detail *detail);
char				*point_sup(char **buff, char **string, int *i,
		t_detail *detail);
char				*nega(long double *f, long double *rest, long long int *a,
		t_detail *detail);
void				clear_buff(char **buff, int *j, t_detail **detail);
void				edit_precision(char **buff, char **string,
		t_detail **detail);
void				parse_format(const char **format, va_list args, int *len);
void				parse_flag(const char **format, va_list args,
		t_detail **detail, int *len);
size_t				aff_char(va_list args, t_detail *detail, char *buff);
size_t				aff_string(va_list args, t_detail *detail, char *buff);
size_t				tab_i(va_list args, t_detail *detail, char *buff);
size_t				aff_pointer(va_list args, t_detail *detail, char *buff);
size_t				int_conv(va_list args, t_detail *detail, char *buff);
size_t				uint_conv(va_list args, t_detail *detail, char *buff);
size_t				octal_conv(va_list args, t_detail *detail, char *buff);
size_t				hexa_conv(va_list args, t_detail *detail, char *buff);
size_t				float_conv(va_list args, t_detail *detail, char *buff);
size_t				bin_conv(va_list args, t_detail *detail, char *buff);
size_t				percent_conv(va_list args, t_detail *detail, char *buff);
size_t				get_fct(const char *format, va_list args, t_detail *detail);
size_t				aff_number(char *buff, char *string, t_detail *detail);
size_t				ifc_null(char *buff, char *string, t_detail *detail);
size_t				fix_stuffx(unsigned long long ll, char *buff,
		t_detail *detail);
size_t				fix_stuffo(unsigned long long ll, char *buff, t_detail
		*detail);
t_detail			*set_det(t_detail *detail);
char				*ft_llutoa_base(unsigned long long value, char *base);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
#endif
