###########################################################
#### NAME

NAME			= push_swap

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

SRCS			+= 01_setup/parsing.c
SRCS			+= 01_setup/index.c
SRCS			+= 02_moves/push_swap.c
SRCS			+= 02_moves/rotate.c
SRCS			+= 02_moves/reverse_rotate.c
SRCS			+= 03_sorting/sort_up_to5.c
SRCS			+= 03_sorting/sort_up_to500.c
SRCS			+= 03_sorting/get_median.c
SRCS			+= 03_sorting/count_move.c
SRCS			+= 03_sorting/quick_move.c
SRCS			+= 04_utils/list_utils.c
SRCS			+= 04_utils/parsing_utils.c
SRCS			+= 04_utils/utils.c
SRCS			+= main.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs/
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### INCLUDES

INCLUDE			= include
HEADER			= include/push_swap.h

###########################################################
#### COMPILATION

CC				=	clang
CFLAGS			+=	-Wall
CFLAGS			+=	-Wextra
CFLAGS			+=	-Werror

###########################################################
#### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)\

.PHONY: all clean fclean re

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
# $(@D) pour extraire le chemin du répertoire de destination du fichier .o et crée le répertoire si nécessaire.