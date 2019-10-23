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
		  string_arguments.c \
		  bol_set.c \

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
		  quick_sort.c \
		  bol_set.c \
		  three_sort.c \
		  remove_instructions.c \
		  quick_swap.c \
		  test_ret.c \
		  string_arguments.c \

SRCS1 = $(addprefix $(SRC_PATH)/,$(SOURCES1))
OBJS1 = $(addprefix $(OBJ_PATH)/,$(SOURCES1:.c=.o))

SRCS2 = $(addprefix $(SRC_PATH)/,$(SOURCES2))
OBJS2 = $(addprefix $(OBJ_PATH)/,$(SOURCES2:.c=.o))

all : $(NAME1)

$(NAME1) : $(NAME2)
	@$(CC) $(OBJS1) $(LIB_PATH) -o $(NAME1)
	@echo "\033[1mCompilation \033[1;35mCHECKER   : \033[;32m[COMPLETE]\033[0m"

$(NAME2) : $(OBJS2) $(OBJS1)
	@make -C libft/
	@$(CC) $(OBJS2) $(LIB_PATH) -o $(NAME2)
	@echo "\033[1mCompilation \033[1;35mPUSH_SWAP : \033[;32m[COMPLETE]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p obj
	@printf "\033[1mCompiling \033[0;36m$(basename $(notdir $@))\033[0m\n" ;
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME1) $(NAME2)
	@rm -rf $(LIB_PATH)

re : fclean all

.PHONY = make re fclean clean all
