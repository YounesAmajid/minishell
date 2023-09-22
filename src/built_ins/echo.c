/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:32:41 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/22 03:39:37 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_need(char c)
{
  if (c == '-') return (0);
  return (1);
}
int ft_check_arg(char *str)
{
  int i;

  i = 1;
  if (!str)
	return (0);
  while (str[i] != '\0')
  {
    if (str[i] != 'n')
        return (0);
      i++;
  }
  return (1);
}

void echo(int argc, char **argv)
{
    int i;
	int flag;

    i = 1;
	flag = 0;
    if (argv[0] && !argv[1])
	{
    	printf("\n");
		return ;
	}
	else if (argv[0] && ft_check_arg(argv[i]) == 1 && !argv[2])
	{
		printf("1\n");
		return ;
	}
	if ((ft_need(*argv[1]) == 0 && ft_check_arg(argv[1]) == 1))
	{
		i = 2;
		flag = 1;
		while (i < argc && ft_check_arg(argv[i]) == 1)
				i++;
    	while (i < argc)
    	{
				if (i + 1 == argc)
					ft_putstr_fd(argv[i], STDOUT_FILENO);
				else
				{
					ft_putstr_fd(argv[i], STDOUT_FILENO);
					ft_putchar_fd(' ', STDOUT_FILENO);
				}
				i++;
    	}
	}
	else
	{
		flag = 0;
		while (i < argc && ft_check_arg(argv[i]) == 1)
				i++;
		while (i < argc)
    	{
				if (i + 1 == argc)
					ft_putstr_fd(argv[i], STDOUT_FILENO);
				else
				{
					ft_putstr_fd(argv[i], STDOUT_FILENO);
					ft_putchar_fd(' ', STDOUT_FILENO);
				}
				i++;
    	}
	}	
	if (flag == 0)
		printf("\n");
	_status(0);
	return ;
}


// void echo(int argc, char **argv)
// {
//     bool n_option;
//     int i;
    
//     i = 1;
//     n_option = false;
      
//     if (argc > 1 && argv[1] && strcmp(argv[1], "-n") == 0)
//     {
//         n_option = true;
//         i++;
//     }
//     while (i < argc)
//     {
//       if (i < argc - 1) {
//         printf("%s ", argv[i]);
//       }
//       else {
//         printf("%s", argv[i]);
//       }
//       i++;
//     }
//     if (!n_option) {
//       printf("\n");
//     }
// }