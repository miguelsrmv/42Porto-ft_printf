# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 16:13:23 by mde-sa--          #+#    #+#              #
#    Updated: 2023/05/02 13:08:03 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc


SRC		=	${wildcard *.c} ${wildcard libft/*.c}

OBJ		=	${SRC:.c=.o}

RM = rm -f

AR = ar -rc


%.o : %.c 
	@${CC} -c $< -I . -o $@

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

test:
	@make
	@make clean
	@cc -I. test.c libftprintf.a -o a.out && ./a.out


clean:
	@make clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) $(OBJ)

re: fclean all