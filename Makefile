# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 23:50:24 by piow00            #+#    #+#              #
#    Updated: 2022/08/19 16:55:17 by piow00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------- Sources ----------------------------------------------#

NAME		=		philo
SRCS		=		$(addprefix ./srcs/, main.c check_args.c error.c utils.c \
						init.c time.c)

#---------------------- Objects -----------------------------------------------#

OBJS		=		$(SRCS:.c=.o)
SUP_OBJS	=		rm -rf $(OBJS)
SUP_NAME	=		rm -rf $(NAME)

#---------------------- Flags / compil ----------------------------------------#

FLAGS		=		-Werror -Wall -Wextra -pthread -g
LFLAGS		=		$(FLAGS)  -fsanitize=address -fno-omit-frame-pointer
GCC			=		gcc

ifeq ($(shell uname), Linux)

GCC			=		gcc
endif

#---------------------- Couleurs ----------------------------------------------#

GN			=		\033[1;32m
RD			=		\033[1;31m
END			=		\033[0m

#---------------------- Texte -------------------------------------------------#

START		=		echo "$(GN)Start compilation\n$(END)"
END_COMP	=		echo "$(GN)End compilation\n$(END)"
S_OBJS		=		echo "$(RD)Suppression des objets\n$(END)"
S_NAME		=		echo "$(RD)Suppression du programme\n$(END)"

#---------------------- Compilation -------------------------------------------#

all : $(NAME)

$(NAME) : start philo

start : 
		@$(START)
		
philo :
		$(GCC) $(SRCS) $(FLAGS) -o $(NAME)
		@$(END_COMP)

l :
		$(GCC) $(SRCS) $(LFLAGS) -o $(NAME)
		@$(END_COMP)

clean :
		$(SUP_OBJS)
		@$(S_OBJS)

fclean : clean
		$(SUP_NAME)
		@$(S_NAME)

re : fclean all

.PHONY : all clean fclean re