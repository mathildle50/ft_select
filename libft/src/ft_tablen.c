/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:46:57 by mallard           #+#    #+#             */
/*   Updated: 2017/07/10 02:03:43 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}
