OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = Bsp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo "Launch a test case with the command make test0"

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@
test0 : $(NAME)
	clear
	./$(NAME) 0
test1 : $(NAME)
	clear
	./$(NAME) 1
test2 : $(NAME)
	clear
	./$(NAME) 2
test3 : $(NAME)
	clear
	./$(NAME) 3
test4 : $(NAME)
	clear
	./$(NAME) 4
testall	: $(NAME)
	clear
	./$(NAME) 0
	@echo
	./$(NAME) 1
	@echo
	./$(NAME) 2
	@echo
	./$(NAME) 3
	@echo
	./$(NAME) 4
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all test0 test1 test2 test3 test4 testall clean fclean re
