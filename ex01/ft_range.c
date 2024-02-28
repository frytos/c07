/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:37:08 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/28 17:54:43 by argrouss         ###   ########.fr       */
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
	array = (int *) malloc((max - min) * sizeof(int));
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

// int main(int argc, char **argv)
// {
// 	argc--;
// 	argv++;
// 	int	max = atoi(argv[0]);
//     int    *t = ft_range(10, max);
// 	printf("Pointer returned : %p\n", t);
//     for (int i = 0; i < max - 10; i++)
//         printf("t[%d] = %d\n", i, t[i]);
//     free(t);
// }
