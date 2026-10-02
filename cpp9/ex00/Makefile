OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = main.cpp BitcoinExchange.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

NAME = btc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

evaluation : $(NAME)
	cat inputs/eval.txt
	@echo
	./$(NAME) inputs/eval.txt

test : $(NAME)
	cat inputs/test1.txt
	./$(NAME) inputs/test1.txt

clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all run test clean fclean re
