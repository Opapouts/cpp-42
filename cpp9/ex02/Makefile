OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = main.cpp PmergeMe.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

NAME = PmergeMe

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

run : $(NAME)
	./$(NAME) 3 5 9 7 4

script : $(NAME)
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

evaluation : run script
	./$(NAME) "-1" "2"

clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all run script evaluation clean fclean re
