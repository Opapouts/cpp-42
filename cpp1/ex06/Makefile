OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = main.cpp Harl.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = harlFilter

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@
evaluation : $(NAME)
	@echo "The difference in this exercise is that we are using switch statements and when a"
	@echo "level code is called, all the other levels above it are called as well."
	@echo
	@echo "-----Executing with level code DEBUG-----"
	@./$(NAME) DEBUG
	@echo
	@echo "-----Executing with level code INFO-----"
	@./$(NAME) INFO
	@echo
	@echo "-----Executing with level code WARNING-----"
	@./$(NAME) WARNING
	@echo
	@echo "-----Executing with level code ERROR-----"
	@./$(NAME) ERROR
	@echo
	@echo "-----Executing with wrong level code-----"
	@./$(NAME) WRONG

clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all evaluation clean fclean re
