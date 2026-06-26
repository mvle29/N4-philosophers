NAME = philo
TEST = test
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = include/ libft/
INCLUDE = $(foreach H,$(HEADER),-I $H)

SRC_MUTEXES_DIR = mutexes/
SRC_MUTEXES_FILES = meal_mutex.c print_mutex.c
SRC_MUTEXES = $(foreach F,$(SRC_MUTEXES_FILES),$(SRC_MUTEXES_DIR)$F)

SRC_THREADS_DIR = threads/
SRC_THREADS_FILES = actions.c actions2.c thread_routine.c $(SRC_MUTEXES)
SRC_THREADS = $(foreach F,$(SRC_THREADS_FILES),$(SRC_THREADS_DIR)$F)

SRC_DIR = src/
SRC_FILES = main.c parse.c error.c cleanup.c init.c $(SRC_THREADS)
SRC = $(foreach F,$(SRC_FILES),$(SRC_DIR)$F)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

re : fclean all

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

libft/libft.a :
	make -C libft/

.PHONY = all re clean fclean
