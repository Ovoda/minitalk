SERV		= server
CLIENT		= client
SRCS_PATH	= ./srcs/

INCS	=	-I./includes

RM		= rm -rf
CC		= clang

CLIENT_SRCS_NAMES	=	client.c
SERV_SRCS_NAMES		=	server.c		\
						singleton.c
SRCS_NAMES			=	tools.c

CLIENT_SRCS = $(addprefix $(SRCS_PATH), $(CLIENT_SRCS_NAMES))
SERV_SRCS = $(addprefix $(SRCS_PATH), $(SERV_SRCS_NAMES))
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAMES))

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERV_OBJS = $(SERV_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)



%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all : $(CLIENT) $(SERV)

$(SERV):	$(SERV_OBJS) $(OBJS)
	$(CC) $(SERV_OBJS) $(OBJS)  $(INCS) -o $(SERV)

$(CLIENT):	$(CLIENT_OBJS) $(OBJS)
	$(CC) $(CLIENT_OBJS) $(OBJS) $(INCS) -o $(CLIENT)

clean:
	$(RM) $(SERV_OBJS) $(OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERV) $(CLIENT)

re: clean all

.PHONY: clean all fclean re
