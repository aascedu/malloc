ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

INC_DIR =	inc/
SRC_DIR =	src/
LIB_DIR =	lib/
NAME =		$(LIB_DIR)libft_malloc_$(HOSTTYPE).so
OBJ_DIR =	.obj/

CC =		cc
CFLAGS =	-Wall -Werror -Wextra -shared -I$(INC_DIR) -fPIC
SRCS =		malloc.c

OBJS =		$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: dir
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(LIB_DIR)

clean:
	rm -rf .obj

fclean: clean
	rm -rf lib

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re