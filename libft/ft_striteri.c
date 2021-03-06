/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:16:55 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 22:56:22 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	k;

	if (s)
	{
		i = ft_strlen(s);
		k = 0;
		while (k < i)
		{
			f(k, &s[k]);
			k++;
		}
	}
}
