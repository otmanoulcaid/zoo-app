FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
NAME = xQueryServer
COMPILER = g++

HEADERS = XQueryProcess.hpp Server.hpp
SRCS = ${wildcard ./*.cpp}
OBJ = ${SRCS:.cpp=.o}

YELLOW = \033[33m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: run

run: $(NAME)
	@echo "$(YELLOW)Running the Server...$(RESET)"
	@./$(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)The object files are generated...$(RESET)"
	@$(COMPILER) $(FLAGS) $^ -o $(NAME)
	@echo "$(GREEN)The executable is generated...$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning the object files...$(RESET)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning the executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)Rebuilding the executable...$(RESET)"
