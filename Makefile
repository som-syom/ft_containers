NAME      = ft_containers
CC        = clang++
CFLAGS    = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
INC       = ./includes

FILES			= main
SRCS_DIR  = ./
SRCS      = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS      = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o:
	$(CC) $(CFLAGS) -I$(INC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $@

test-vector:
	$(CC) $(CFLAGS) -I$(INC) ./tester/vector_test.cpp
test-stack:
	$(CC) $(CFLAGS) -I$(INC) ./tester/stack_test.cpp
test-map:
	$(CC) $(CFLAGS) -I$(INC) ./tester/map_test.cpp

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test-vector test-stack test-map