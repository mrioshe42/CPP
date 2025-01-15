NAME := RPN
CC := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror -g
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=obj/%.o)
INC := -I./inc

all: $(NAME)

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp | obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) -rf obj

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
