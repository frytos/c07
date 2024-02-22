/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:37:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/22 15:58:27 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*array;
	int	index;

	if (min >= max)
		return (NULL);
	array = malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (NULL);
	index = 0;
	while (index < (max - min))
	{
		array[index] = min + index;
		index++;
	}
	return (array);
}	


int main()
{
    int    *t = ft_range(10, 20);
    for (int i = 0; i < 10; i++)
        printf("t[%d] = %d\n", i, t[i]);
}
