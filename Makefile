##
## EPITECH PROJECT, 2023
## server
## File description:
## Makefile
##

CC	=	gcc

PATH_CLIENT = src/client
PATH_SERVER = src/server
COMMANDS = commands
COMMUNICATION = communication
UTILS = utils
MYTEAMS = myteams
FILE = file
CREATE = create

SRC_CLIENT	=	$(PATH_CLIENT)/$(MYTEAMS)/main.c	\
				$(PATH_CLIENT)/$(MYTEAMS)/check_arg.c	\
				$(PATH_CLIENT)/$(MYTEAMS)/my_teams.c	\
				$(PATH_CLIENT)/$(UTILS)/handling_select.c	\
				$(PATH_CLIENT)/$(UTILS)/create_socket.c	\
				$(PATH_CLIENT)/$(UTILS)/connection.c	\
				$(PATH_CLIENT)/$(UTILS)/parse_tools.c	\
				$(PATH_CLIENT)/$(UTILS)/usage.c	\
				$(PATH_CLIENT)/$(UTILS)/str_to_word_array.c	\
				$(PATH_CLIENT)/$(UTILS)/signal.c	\
				$(PATH_CLIENT)/$(UTILS)/quote.c	\
				$(PATH_CLIENT)/$(COMMUNICATION)/server_response.c	\
				$(PATH_CLIENT)/$(COMMUNICATION)/client_response.c	\
				$(PATH_CLIENT)/$(COMMUNICATION)/send_response.c	\
				$(PATH_CLIENT)/$(COMMANDS)/handling_cmd.c	\
				$(PATH_CLIENT)/$(COMMANDS)/create.c	\
				$(PATH_CLIENT)/$(COMMANDS)/create_bis.c	\
				$(PATH_CLIENT)/$(COMMANDS)/info.c	\
				$(PATH_CLIENT)/$(COMMANDS)/list.c	\
				$(PATH_CLIENT)/$(COMMANDS)/login.c	\
				$(PATH_CLIENT)/$(COMMANDS)/logout.c	\
				$(PATH_CLIENT)/$(COMMANDS)/help.c	\
				$(PATH_CLIENT)/$(COMMANDS)/messages.c	\
				$(PATH_CLIENT)/$(COMMANDS)/send.c	\
				$(PATH_CLIENT)/$(COMMANDS)/subscribe.c	\
				$(PATH_CLIENT)/$(COMMANDS)/subscribed.c	\
				$(PATH_CLIENT)/$(COMMANDS)/unsubscribe.c	\
				$(PATH_CLIENT)/$(COMMANDS)/use.c	\
				$(PATH_CLIENT)/$(COMMANDS)/user.c	\
				$(PATH_CLIENT)/$(COMMANDS)/users.c	\

SRC_SERVER	=	$(PATH_SERVER)/main.c	\
				$(PATH_SERVER)/init_server.c	\
				$(PATH_SERVER)/my_teams.c	\
				$(PATH_SERVER)/handling_select.c	\
				$(PATH_SERVER)/manage_client.c	\
				$(PATH_SERVER)/check_arg.c	\
				$(PATH_SERVER)/manage_client_response.c	\
				$(PATH_SERVER)/$(UTILS)/find_user.c	\
				$(PATH_SERVER)/$(UTILS)/find_team.c	\
				$(PATH_SERVER)/$(UTILS)/find_channel.c	\
				$(PATH_SERVER)/$(UTILS)/find_thread.c	\
				$(PATH_SERVER)/$(UTILS)/usage.c	\
				$(PATH_SERVER)/$(UTILS)/gen_uuid.c	\
				$(PATH_SERVER)/$(UTILS)/str_to_word_array.c	\
				$(PATH_SERVER)/$(UTILS)/create_socket.c	\
				$(PATH_SERVER)/$(UTILS)/signal.c	\
				$(PATH_SERVER)/$(UTILS)/team_tools.c	\
				$(PATH_SERVER)/$(UTILS)/shut_down.c	\
				$(PATH_SERVER)/$(UTILS)/tab_management.c	\
				$(PATH_SERVER)/$(UTILS)/response.c	\
				$(PATH_SERVER)/$(UTILS)/user_utils.c	\
				$(PATH_SERVER)/$(FILE)/restore.c	\
				$(PATH_SERVER)/$(FILE)/restore_team.c	\
				$(PATH_SERVER)/$(FILE)/save.c	\
				$(PATH_SERVER)/$(FILE)/save_team.c	\
				$(PATH_SERVER)/$(FILE)/default.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/create.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/send_create_event.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/malloc_team.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/create_team.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/create_channel.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/create_thread.c	\
				$(PATH_SERVER)/$(COMMANDS)/$(CREATE)/create_comment.c	\
				$(PATH_SERVER)/$(COMMANDS)/handling_cmd.c	\
				$(PATH_SERVER)/$(COMMANDS)/info.c	\
				$(PATH_SERVER)/$(COMMANDS)/list.c	\
				$(PATH_SERVER)/$(COMMANDS)/login.c	\
				$(PATH_SERVER)/$(COMMANDS)/login_bis.c	\
				$(PATH_SERVER)/$(COMMANDS)/logout.c	\
				$(PATH_SERVER)/$(COMMANDS)/messages.c	\
				$(PATH_SERVER)/$(COMMANDS)/send.c	\
				$(PATH_SERVER)/$(COMMANDS)/subscribe.c	\
				$(PATH_SERVER)/$(COMMANDS)/subscribe_bis.c	\
				$(PATH_SERVER)/$(COMMANDS)/subscribed.c	\
				$(PATH_SERVER)/$(COMMANDS)/subscribed_bis.c	\
				$(PATH_SERVER)/$(COMMANDS)/unsubscribe.c	\
				$(PATH_SERVER)/$(COMMANDS)/use_find.c	\
				$(PATH_SERVER)/$(COMMANDS)/use.c	\
				$(PATH_SERVER)/$(COMMANDS)/use_bis.c	\
				$(PATH_SERVER)/$(COMMANDS)/user.c	\
				$(PATH_SERVER)/$(COMMANDS)/users.c	\

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

NAME_CLIENT	=	myteams_cli

NAME_SERVER	=	myteams_server

CFLAGS	+=	-Wall -Wextra -g3

CFLAGS	+=	-I include/

CFLAGS	+=	-I libs/myteams/

LDFLAGS	+=	-L libs/myteams/ -lmyteams -luuid

all:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LDFLAGS) $(LDLIBS) $(CFLAGS)

$(NAME_SERVER):	$(OBJ_SERVER)
		$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(LDFLAGS) $(LDLIBS) $(CFLAGS)

clean:
		$(RM) $(OBJ_CLIENT)
		$(RM) $(OBJ_SERVER)

fclean:	clean
		$(RM) $(NAME_CLIENT)
		$(RM) $(NAME_SERVER)

re: fclean all

.PHONY:	all clean fclean re
