/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:35:21 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/29 08:42:33 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chkbse_getsz(char *base)
{
	int	index;
	int	search_index;

	index = 0;
	if (base == NULL)
		return (-4);
	while (base[index])
	{
		if ((9 <= base[index] && base[index] <= 13) || base[index] == 32)
			return (-2);	
		if (base[index] == '-' || base[index] == '+')
			return (-1);
		search_index = index + 1;
		while (base[search_index])
		{
			if (base[index] == base[search_index])
				return (-3);
			search_index++;
		}
		index++;
	}
	return (index);
}
