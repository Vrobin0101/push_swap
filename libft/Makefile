# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 09:13:58 by vrobin            #+#    #+#              #
#    Updated: 2019/10/26 11:43:21 by vrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = libft.h

OBJ_PATH = obj
SRC_PATH = .

SOURCES = ft_memset.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strlen.c		\
	   ft_strdup.c		\
	   ft_strndup.c		\
	   ft_strcpy.c		\
	   ft_strncpy.c		\
	   ft_strcat.c		\
	   ft_strncat.c		\
	   ft_strlcat.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_strstr.c		\
	   ft_strnstr.c		\
	   ft_strcmp.c		\
	   ft_strncmp.c		\
	   ft_atoi.c		\
	   ft_isalpha.c		\
	   ft_isdigit.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_memalloc.c	\
	   ft_memdel.c		\
	   ft_strnew.c		\
	   ft_strdel.c		\
	   ft_strclr.c		\
	   ft_striter.c		\
	   ft_striteri.c	\
	   ft_strmap.c		\
	   ft_strmapi.c		\
	   ft_strequ.c		\
	   ft_strnequ.c		\
	   ft_strsub.c		\
	   ft_strjoin.c		\
	   ft_strjoinf.c	\
	   ft_strtrim.c		\
	   ft_strsplit.c	\
	   ft_itoa.c		\
	   ft_putchar.c		\
	   ft_putstr.c		\
	   ft_putendl.c		\
	   ft_putnbr.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   ft_lstnew.c		\
	   ft_lstdelone.c	\
	   ft_lstdel.c		\
	   ft_lstadd.c		\
	   ft_lstiter.c		\
	   ft_lstmap.c		\
	   ft_print_words_table.c \
	   ft_itooct.c		\
	   ft_high_sqrt.c	\
	   ft_itoa_base.c	\
	   ft_fritoa_base.c	\
	   get_next_line.c \
	   ft_printf.c    \
		  parse_format.c \
		  parse_flag.c   \
		  number_conv.c  \
		  aff_number.c   \
		  edit_ret.c     \
		  csp_conv.c     \
		  point.c		 \
		  percent_conv.c \
		  fill_float.c	 \
		  check_float.c  \
		  clear_buff.c	 \
		  tab_i.c		 \
		  fix_stuff.c	 \
		ft_llutoa_base.c		\
		ft_strnjoin.c	\
		print_until.c	\
		check_next.c \

SRCS = $(addprefix $(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p obj
	@printf "\033[1mCompiling \033[0;36m$(basename $(notdir $@))\033[0m\n" ;
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@rm -rf obj

fclean : clean
	@rm -rf $(NAME)

re : fclean all
