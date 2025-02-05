ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =		$(LIB_DIR)libft_malloc_$(HOSTTYPE).so
NAME_NO_PATH =	libft_malloc_$(HOSTTYPE).so
LIBNAME =	$(LIB_DIR)libft_malloc.so
INC_DIR =	inc/
SRC_DIR =	src/
LIB_DIR =	lib/
OBJ_DIR =	.obj/

CC =		cc
CFLAGS =	-Wall -Werror -Wextra -g3  -I$(INC_DIR) -pedantic

SRCS =		malloc.c utils.c page.c
OBJS =		$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: dir
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $(OBJS)
	ln -sf $(NAME_NO_PATH) $(LIBNAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(LIB_DIR)

test: all
	$(CC) $(CFLAGS) -g3 -o test main.c -L$(LIB_DIR) -lft_malloc

clean:
	rm -rf .obj

fclean: clean
	rm -rf lib test core

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
