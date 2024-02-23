/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:14:28 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/23 03:47:06 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int ft_ultimate_range(int **range, int min, int max)
{
	int	index;

	if (max - min <= 0)
	{
		range = NULL;
		return (0);
	}
	range[0] = malloc((max - min) * sizeof(int));
	if (range[0] == NULL)
		return (-1);
	index = 0;
	while (index < max - min)
	{
		range[0][index] = min + index;
		index++;
	}
	return (sizeof(range));
}

// int main(){
//     int **tab = malloc(sizeof(int**));
//     int max = 45;
//     int ret = ft_ultimate_range(tab, 10, max);
//     for (int i = 0; i < max; i++)
//         printf("t[%d] = %d\n", i, (*tab)[i]);
//     printf("return = %d\n", ret);
// }
