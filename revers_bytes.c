/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:59:17 by mohtakra          #+#    #+#             */
/*   Updated: 2023/02/19 11:55:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

sigset_t	reverse_nbr_bytes(sigset_t set, int numbytes)
{
	sigset_t	reversed_number;
	int			number_of_bits;
	int			i;
	int			j;

	i = 0;
	j = 0;
	number_of_bits = 8 * numbytes;
	sigemptyset(&reversed_number);
	numbytes = 1;
	while ( i < number_of_bits)
	{
		if (i % 8 == 0 && i != 0)
		{
			numbytes++;
			j = 0;
		}
		if (set % 2 == 1)
		{
			sigaddset(&reversed_number, number_of_bits - ((8 * numbytes - 1) - j));
		}
		set = set / 2;
		i++;
		j++;
	}
	return (reversed_number);
}