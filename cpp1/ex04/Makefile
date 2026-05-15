OBJ_DIR = objects

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = main.cpp Handler.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = Sed

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@
evaluation : $(NAME)
	@echo "-----Launching test case-----"
	@echo "This is the (test) case. If you want to modify the (test) case you can" > test
	@echo "modify the Makefile and perform your own (test)s. The replaced word" >> test
	@echo "will be (test). You will probably see another word here." >> test
	@echo "Random text to make the file bigger. Test, (test), (test)." >> test
	@echo "Goodbye." >> test
	@./$(NAME) test test yolo
	@echo "-----The input used was (test test yolo)-----"
	@echo "-----Infile content shown below-----"
	@cat test
	@echo "-----Outfile content shown below-----"
	@cat test.replace

cleanup :
	rm test test.replace
clean :
	rm -rf $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all evaluation cleanup clean fclean re
