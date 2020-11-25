NAME	=	libftprintf.a

SRCDIR	=	./srcs/

SRC		=	$(addprefix ${SRCDIR}, ft_printf.c \
			parsing.c \
			printing.c \
			ft_atoi.c \
			printing_16base_lowercase.c \
			printing_16base_uppercase.c \
			utils.c \
			printing_chars_and_strings.c \
			printing_decimal_integer.c \
			printing_pointers.c )

INCDIR	=	./includes/

INCUTL	=	ft_printf_utils.h

INC		=	ft_printf.h

OBJS	=	${SRC:.c=.o}

CC		=	gcc

CCFLAGS	=	-Wall -Wextra -Werror

GREEN	=	\033[0;32m

CYAN	=	\033[0;36m

MAGENTA	=	\033[0;35m

LGREEN	=	\033[1;32m

LYELLOW	=	\033[1;33m

LRED	=	\033[1;31m

LBLUE	=	\033[1;34m

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS} ${INCDIR}${INC} ${INCDIR}${INCUTL}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${CYAN}Library "${NAME}" succesfully compiled"

%.o: %.c
	@${CC} ${CFLAGS} -I ${INCDIR} -c $< -o $@
	@echo "${MAGENTA}Object file: ${LYELLOW}$@ ${GREEN}successfuly compiled"

bonus: fclean all

clean:
	@rm -f ${OBJS}
	@echo "${LRED}All object files were cleaned"

fclean:		clean
	@rm -f ${NAME}
	@echo "${LRED}Binary file was cleaned"
	@echo "${LGREEN}Everything is cleaned succesfully"

re:		fclean all
	@echo "${LBLUE}Library successfuly rebuilt"