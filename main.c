#include "minishell.h"

void    lexer(t_lexer **lex, char *line)
{
    int		i;
    t_lexer	*node;
    
    i = 0;
    while (line[i])
    {                                                                                                                                                                                                                                                                                                                                                                                

    }
}

int main(int ac, char **av, char **envp)
{
    char    *line;
    t_lexer *lex;

    lex = NULL;
    while (1){
        line = readline("➜  Minishell ");
        if (!line) break;
		printf("%s\n", line);
        lexer(&lex, line);
        while (lex)
        {
            printf("%s", lex->data);
            lex = lex->next;
        }
        break ;
    }
	return (0);
}