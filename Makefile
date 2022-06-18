src = *.c ./parse/*.c ./exec/*.c ./libft_m/*.c
minishell = minishell
RDLINE        := -L/Users/hboukili/goinfre/.brew/opt/readline/lib -I /Users/hboukili/goinfre/.brew/opt/readline/include
FLAGS =  -lreadline -Wall -Wextra -Werror
CC = cc

all : minishell
	
$(minishell): $(src)	
	@$(CC) $(FLAGS) $(RDLINE) $(src) -o minishell
	@tput setaf 2; echo "MINISHELL IS READY"

clean :
	@rm -f minishell
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all 