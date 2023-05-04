###########################################################
#### NAME

NAME			= push_swap

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

###########################################################
#### SOURCES

SRCS			+= main.c
SRCS			+= list_utils.c
SRCS			+= utils.c
SRCS			+= index.c
SRCS			+= moves1.c
SRCS			+= moves2.c
#SRCS			+= moves3.c
SRCS			+= parsing.c
SRCS			+= lst_push_pop.c
SRCS			+= sort_3.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs/
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### LIBRARY

#LIBFT_PATH 	= libft/
#LIBFT 			= $(LIBFT_PATH)/libft.a

###########################################################
#### INCLUDES

#INCLUDES 		= -I./includes -I./minilibx-linux -I./$(LIBFT_PATH)/includes
INCLUDE			= include
HEADER			= include/push_swap.h
#HEADER			+= minilibx-linux/mlx.h
#HEADER			+= minilibx-linux/mlx_int.h

###########################################################
#### COMPILATION

CC				=	clang
CFLAGS			+=	-Wall
CFLAGS			+=	-Wextra
CFLAGS			+=	-Werror

#ifeq ($(everything),true)
#	CFLAGS		+= -Weverything

#else
#	CFLAGS		+= -Werror

#endif

#CFLAGS			+= -Wextra
#CFLAGS			+= -fPIE


###########################################################
#### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)\

del: fclean
	rm a.out

#bonus: fclean 
#	$(MAKE) -sC $(PATH_BONUS)

.PHONY: all clean fclean re del test full_test

###########################################################
#### HELP

#		CIBLE > DEPENDANCES > REGLES
# 		variables spéciales :
#
# $+ idem que $^ mais avec les doublons
# $| idem que $^ mais avec les doublons et triés
# $% nom de la cible d'une règle de substitution
# $! nom de la cible d'une règle de substitution
# $< nom de la première dépendance d'une règle de substitution
# $> nom de la dernière dépendance d'une règle de substitution
# $^ liste des dépendances d'une règle de substitution
# $@ nom de la cible d'une règle de substitution
# $? liste des dépendances plus récentes que la cible d'une règle de substitution
# $* nom du fichier sans son extension d'une règle de substitution