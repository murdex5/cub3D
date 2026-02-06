# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msisto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 11:05:32 by msisto            #+#    #+#              #
#    Updated: 2024/01/29 13:29:15 by msisto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_striteri.c

BSRC = \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
       ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstiter.c \
       ft_lstmap.c \

OUT = $(SRC:.c=.o)

BOUT = $(BSRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OUT)
	ar rsc $(NAME) $(OUT)

all: $(NAME)

bonus: $(BOUT)
	ar rsc $(NAME) $(BOUT)

clean: 
	rm -f $(OUT) $(BOUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
