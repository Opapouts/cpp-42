OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = main.cpp Harl.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = Harl

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@
evaluation : $(NAME)
	@echo "We are going to execute the program with all the different level codes and a wrong one"
	@echo
	@echo "First level--->DEBUG"
	@./$(NAME) DEBUG
	@echo
	@echo "Second level--->INFO"
	@./$(NAME) INFO
	@echo
	@echo "Third level--->WARNING"
	@./$(NAME) WARNING
	@echo
	@echo "Fourth level--->ERROR"
	@./$(NAME) ERROR
	@echo
	@echo "Wrong level code--->WRONG"
	@./$(NAME) WRONG
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all evaluation clean fclean re
