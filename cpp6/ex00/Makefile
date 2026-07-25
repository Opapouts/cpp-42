OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = main.cpp ScalarConverter.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

NAME = convert

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

run : $(NAME)
	@clear
	@echo "====Basic tests given in the evaluation sheet===="
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f 
	@echo
	@echo "====Some edge cases===="
	./$(NAME) -13
	@echo
	./$(NAME) 2147483647
	@echo
	./$(NAME) 2147483648
	@echo
	./$(NAME) 999999999999
	@echo
	./$(NAME) abc

clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all run clean fclean re
