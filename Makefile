NAME = wordle

OBJ_DIR = obj

SRC_DIR = src/

SRCS = 	${SRC_DIR}wordle.c \
		${SRC_DIR}readFile.c \
		${SRC_DIR}checker.c \
		${SRC_DIR}playGame.c \
		${SRC_DIR}getTodaysWord.c \

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes -g

RM = rm -rf

.SILENT:

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	printf "\r\rCompiling wordle.."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	printf "\rCompiling completed.\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

generate_test:
	valgrind --leak-check=full --show-reachable=yes --error-limit=no --gen-suppressions=all --log-file=$(NAME).log ./$(NAME)

test: all
	clear; valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no ./$(NAME)

run: all
	clear; ./$(NAME)

child_test: all