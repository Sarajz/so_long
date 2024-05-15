# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:08:42 by sarajime          #+#    #+#              #
#    Updated: 2024/05/15 16:58:22 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
FLAGS = -Wall -Werror -Wextra
FILES = ft_isalpha.c ft_isalnum.c ft_tolower.c ft_toupper.c ft_strnstr.c \
ft_strrchr.c ft_strlen.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_bzero.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_split.c \
ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_memchr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line.c get_next_line_utils.c ft_printf.c ft_numbers.c ft_unsigned.c \
ft_words.c

FILES_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJETS = $(FILES:.c=.o)

OBJETS_BONUS = $(FILES_BONUS:.c=.o)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJETS)
	ar rcs $(NAME) $(OBJETS)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:  $(OBJETS) $(OBJETS_BONUS)
	ar rcs $(NAME) $(OBJETS) $(OBJETS_BONUS)
	

.PHONY: all fclean clean re bonus
