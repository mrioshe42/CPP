NAME := megaphone
CC := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=obj/%.o)

all: $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) -rf obj

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
