NAME1 = checker
NAME2 = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADERS = inc/checker.h

OBJ_DIR	= obj
LIB_PATH = libft/libft.a

SOURCES1 = Main/checker.c \
		  Instructions/push.c \
		  instructions/swap.c \
		  Instructions/rotate.c \
		  Instructions/show_tab.c \
		  Tab_string_stuff/numbers_check.c \
		  Tab_string_stuff/str_to_tab.c\

SOURCES2 = Main/push_swap.c \
		  Instructions/push.c \
		  instructions/swap.c \
		  Instructions/rotate.c \
		  Instructions/show_tab.c \
		  Tab_string_stuff/fill_string.c\
		  Tab_string_stuff/numbers_check.c \
		  Tab_string_stuff/str_to_tab.c\
		  Tab_string_stuff/string_stuff.c\
		  Sort_stuff/algo.c \
		  Sort_stuff/bol_check.c \
		  Sort_stuff/quick_sort.c \
		  Sort_stuff/remove_instructions \

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
