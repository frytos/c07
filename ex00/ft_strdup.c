/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:40:10 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/22 15:34:01 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		index;
	int		len;
	char	*duplicate;

	len = 0;
	while (src[len])
		len++;
	duplicate = (char *) malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	index = 0;
	while (src[index])
	{
		duplicate[index] = src[index];
		index++;
	}
	duplicate[index] = 0;
	return (duplicate);
}

// int    main()
// {
//     char str[30] = "bonjour comment ca va ?";
//     char *dup = ft_strdup(str);
//     printf("%s\n",dup);
// }
