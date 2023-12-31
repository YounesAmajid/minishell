/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:47 by asabri            #+#    #+#             */
/*   Updated: 2023/09/28 12:26:44 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		n;
	char	*dp;
	char	*sp;

	n = (int) len - 1;
	dp = (char *)dst;
	sp = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n >= 0)
		{
			dp[n] = sp[n];
			n--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
