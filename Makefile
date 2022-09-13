########## 		   NAMES 		##########

NAME = push_swap

CHECK = checker

########## 		  SOURCES 		##########

SRC = ./ft_atoi.c ./ft_new_node.c ./ft_print_stacks.c ./ft_push.c ./ft_put_tail.c ./ft_putnbr.c ./ft_reverse_rotate.c ./ft_rotate.c ./ft_sort.c ./ft_swap.c ./push_swap.c

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

########## 		  COMMANDS		##########

#MAKE_LIBFT = cd ${LIBFT_PATH} && make all

#CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean -s

#FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean -s

RM = rm -f

########## 		  TARGETS 		##########

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

${CHECK}: ${OBJ}
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(CHECK) $(OBJ)

########## 		   RULES 		##########

all: ${NAME} 
	${CREATE_PROJ_MSG}

bonus: ${CHECK}
	${CREATE_BONUS_MSG}

clean:
	${CLEAN_LIBFT}
	${RM} ${OBJ}

fclean: clean 
	${FCLEAN_LIBFT}
	${RM} ${NAME} ${CHECK}
	${REMOVED_MSG}
	

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	@cd ${LIBFT_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

.PHONY: all bonus clean fclean re norm