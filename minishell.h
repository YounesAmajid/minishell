/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:09:54 by yamajid           #+#    #+#             */
/*   Updated: 2023/09/04 22:36:41 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MINISHELL_H_
#define _MINISHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <readline/history.h>
#include <readline/readline.h>

// ls             -l| grep  "          Makefile" >      out '\n'
// WORD -> SPA -> SPA -> SPA -> WORD -> SPA -> PIP -> SPA -> WORD -> SPA -> DQU -> SPA -> WORD -> DQU -> SPA ->  OUT -> SPA -> WORD -> END
// ls      NULL  NULL  NULL     grep    NULL   NULL   NULL    "     Makefile" NULL NULL 
/*
word : SQU ''
    DQU ""
    WORD 
redirections:
    output: >
    input : <
    herdoc: <<
    append: >>
pip
spa :isspace

*/

typedef enum e_tok{
    SPA, WORD, DQU, SQU, OUT, INP, HER, APP, PIP
} t_tok;

typedef struct s_lexer
{
    t_tok   type;
    char    *data;
    struct s_lexer *next;
} t_lexer;


#endif
