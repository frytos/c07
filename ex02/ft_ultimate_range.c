/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:14:28 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/28 17:55:30 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);
int	*ft_range(int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL || min >= max)
		return (0);
	else
		return (max - min);
}

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

// int main(int argc, char *argv[]){
// 	(void) argc;
// 	printf("go\t");
//     int **tab = malloc(sizeof(int**));
//     int max = atoi(argv[1]);
//     int ret = ft_ultimate_range(tab, 10, max);
// 	printf("Return value : %d\n", ret);
//     for (int i = 0; i < max - 10; i++)
//         printf("t[%d] = %d\n", i, (*tab)[i]);
//     printf("return = %d\n", ret);
//     free(*tab);
//     free(tab);
// }
