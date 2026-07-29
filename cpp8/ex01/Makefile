OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = main.cpp Span.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

NAME = span

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

run : $(NAME)
	@./$(NAME)
evaluation : $(NAME)
	@./$(NAME) 3
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all run evaluation clean fclean re
