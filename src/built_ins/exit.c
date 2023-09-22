/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:15 by yelwadou          #+#    #+#             */
/*   Updated: 2023/09/22 08:05:57 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	ft_atoi(const char *str)
{
	long long	res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

void exit_built(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("exit\n");
        printf("bash: exit: %s: numeric argument required\n", argv[1]);
    }
    
    // if (argv[0] && !argv[1])
    //     exit(g_global_exit);
    // else if (argv[0] && argv[1])
    
}
