/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:14:28 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/22 23:19:00 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	index;

	if (max - min <= 0)
	{
		range = NULL;
		return (0);
	}
	array = malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (-1);
	index = 0;
	while (index < max - min)
	{
		array[index] = min + index;
		index++;
	}
	return (sizeof(range));
}

int main(){
    int **tab = malloc(sizeof(int**));
    int ret = ft_ultimate_range(tab, 10, 20);
    for (int i = 0; i < 10; i++)
        printf("t[%d] = %d\n", i, (*tab)[i]);
    printf("return = %d\n", ret);

}
