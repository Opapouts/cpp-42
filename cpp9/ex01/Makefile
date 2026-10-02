OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = main.cpp RPN.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

error : $(NAME)
	@echo "===Some edge error cases==="
	@echo
	./$(NAME) "3 0 /"
	@echo
	./$(NAME) "3 4 1 2 +"
	@echo
	./$(NAME) " + "
	@echo
	./$(NAME) "  "
	@echo
	./$(NAME) "2 3 + +"
	@echo
	./$(NAME) "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"

evaluation : $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all error evaluation clean fclean re
