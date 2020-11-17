# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaadi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 16:34:29 by asaadi            #+#    #+#              #
#    Updated: 2019/12/25 15:37:03 by asaadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rc

RA = ranlib

SRCS = ft_printf.c ft_putnbrunsigned.c print_unsigned.c ft_nbrlen.c \
	   print_dec_int.c check_flag.c ft_atoi.c ft_strjoin.c ft_isdigit.c ft_strlen.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c print_char.c print_string.c \
	   ft_substr.c ft_strdup.c print_hexadec.c print_address.c check_flag_sec.c \
	   check_flags_char_string.c ft_is_conversion.c print_percentage.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RA) $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean: 
	rm -rf $(OBJS)


fclean: clean
	rm -rf $(NAME)

re : fclean all
