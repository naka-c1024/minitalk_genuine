# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 14:49:03 by ynakashi          #+#    #+#              #
#    Updated: 2021/11/11 12:01:36 by ynakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

CLIENT_NAME = client
SERVER_NAME = server

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

# This wasn't flagged when creating object files -> suffix rule
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

LIBFT_PATH	= ./libft/
LIBFT_OBJS	= $(LIBFT_PATH)*.o
LIBFT_ARC	= $(LIBFT_PATH)*.a
LIBFT_MAKE	= make -C $(LIBFT_PATH)

ifdef WITH_BONUS
CLIENT_SRCS = $(CLIENT_BONUS_SRCS)
SERVER_SRCS = $(SERVER_BONUS_SRCS)
CLIENT_OBJS = $(CLIENT_BONUS_OBJS)
SERVER_OBJS = $(SERVER_BONUS_OBJS)
endif

# suffix rule
# make -p で暗黙のルールが見れる
# explicitly add a flag when creating object files
#$< 最初の依存するファイルの名前 -> 元になるファイル
#$@ ターゲットファイル名 -> 作りたいファイル
#echo $<
#echo $@
.c.o	:
		$(CC) $(CFLAGS) -c $< -o $@

#$(OBJS)	: $(SRCS)
#	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME)	: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_OBJS) -o $(SERVER_NAME)

all		: $(NAME)

clean	:
		$(RM) $(LIBFT_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean	: clean
		$(RM) $(CLIENT_NAME) $(SERVER_NAME)
		$(RM) $(LIBFT_ARC)

re		: fclean all

bonus	:
	make WITH_BONUS=1

.PHONY	: all clean fclean re bonus
