NAME1 = checker
NAME2 = push_swap

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

HEADERS = inc/checker.h

OBJ_PATH = obj
LIB_PATH = libft/libft.a
SRC_PATH = src

SOURCES1 = checker.c \
		  push.c \
		  swap.c \
		  rotate.c \
		  show_tab.c \
		  numbers_check.c \
		  str_to_tab.c\
		  quick_sort.c \

SOURCES2 = push_swap.c \
		  push.c \
		  swap.c \
		  rotate.c \
		  show_tab.c \
		  fill_string.c\
		  numbers_check.c \
		  str_to_tab.c\
		  string_stuff.c\
		  algo.c \
		  bol_check.c \
		  quick_sort.c \
		  three_sort.c \
		  remove_instructions.c \
		  quick_swap.c \
		  test_ret.c \

SRCS1 = $(addprefix $(SRC_PATH)/,$(SOURCES1))
OBJS1 = $(addprefix $(OBJ_PATH)/,$(SOURCES1:.c=.o))

SRCS2 = $(addprefix $(SRC_PATH)/,$(SOURCES2))
OBJS2 = $(addprefix $(OBJ_PATH)/,$(SOURCES2:.c=.o))

all : $(NAME1)

$(NAME1) : $(NAME2)
	@make -C libft/
	@$(CC) $(OBJS1) $(LIB_PATH) -o $(NAME1)
	@echo "Compilation $(NAME1) OK"

$(NAME2) : $(OBJS2) $(OBJS1)
	@make -C libft/
	@$(CC) $(OBJS2) $(LIB_PATH) -o $(NAME2)
	@echo "Compilation $(NAME2) OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME1) $(NAME2)
	@rm -rf $(LIB_PATH)

re : fclean all

.PHONY = make re fclean clean all
