ifndef VERPOSE
.SILENT:
endif

#-------------------- Define Color -------------------#

R	= "\033[1;31m"
G	= "\033[1;32m"
Y	= "\033[1;33m"
B	= "\033[1;34m"
C	= "\033[0;36m"
P	= "\033[0;35m"
RS	= "\033[0m"

#------------------- End Define Color ------------------#

RCS	= ./src/Cub3d.c\
./src/testing.c \
./src/keys.c \
./src/keys1.c \
./src/drawHelper.c \
./src/init.c \
./src/MKcmd.c \
./src/draw.c \
./src/parsing.c \
./src/parsing_utils.c

OBJS	= $(RCS:.c=.o)

NAME	= cub3d

CFLAGS	= -g -Wall -Werror -Wextra

mlx = ./mlx/libmlx.a

$(NAME)	:
		echo $(G)"cub3d is being compiled..." $(RS)
		-@make -C ./mlx 2>/dev/null || true
		@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
		@echo $(B)"         ║"$(C)"░░░░░███████░░██░░░░██░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░███████░░░███████░░██░░░░░░██░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░░███████░░████████░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
		@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
		@echo "$                         "$(G)"_________Created_By__________"$(RS)
		@echo "                        "$(P)"  𝓘𝓶𝓪𝓭 𝓢𝓪𝓪𝓭 && 𝓨𝓪𝓼𝓼𝓲𝓻 𝓣𝓸𝓾𝓪𝓫"$(RS)
		@echo "$                         "$(G)"-----------------------------"$(RS)
		@echo "\n"
		gcc $(CFLAGS) -o cub3d $(RCS) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		echo $(R)"Cub3d object files are being deleted..." $(RS)
		rm -f $(OBJS)
		-@make clean -C mlx 2>/dev/null || true

fclean : clean
		echo $(R)"Cub3d executable file is being deleted..." $(RS)
		rm -f $(NAME)
		-@make clean -C mlx 2>/dev/null || true

re : fclean all
