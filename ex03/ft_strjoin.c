/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:09 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/29 09:39:55 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
int		ft_strcat(char *dest, char *src, int len_dest);
int		get_malloc_len(int size, char **strs, char *sep);
char	*n_cat(int size, char **strs, char *sep, char *str_cat);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;
	char	*empty;

	if (strs == NULL)
		return (NULL);
	if (size <= 0)
	{
		empty = (char *) malloc(sizeof(char));
		if (!empty)
			return (NULL);
		*empty = 0;
		return (empty);
	}
	str_cat = (char *) malloc(get_malloc_len(size, strs, sep) * sizeof(char));
	if (str_cat == NULL)
		return (NULL);
	return (n_cat(size, strs, sep, str_cat));
}

char	*n_cat(int size, char **strs, char *sep, char *str_cat)
{
	int		index_strs;
	int		index_join;

	index_strs = 0;
	index_join = 0;
	while (index_strs < size)
	{
		index_join += ft_strcat(str_cat, strs[index_strs], index_join);
		if (index_strs < size - 1)
			index_join += ft_strcat(str_cat, sep, index_join);
		index_strs++;
	}
	str_cat[index_join] = 0;
	return (str_cat);
}

int	get_malloc_len(int size, char **strs, char *sep)
{
	int	len;
	int	index;

	len = 0;
	index = 0;
	while (index < size)
	{
		len += ft_strlen(strs[index]);
		index++;
	}
	len += (size - 1) * ft_strlen(sep);
	len += 1;
	return (len);
}

int	ft_strcat(char *dest, char *src, int len_dest)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (index);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// int main(){
// //    char    *tab[] = {""};
// //    char    *tab[] = {};
//     char    *tab[] = {"salut ",""," ca \n","va","?"};
// //    char *r = ft_strjoin(5, tab, "-");
//     char *r = ft_strjoin(5, tab, "");
// //    char *r = ft_strjoin(1, tab, "");
// //    char *r = ft_strjoin(0, tab, "");
// //    char *r = ft_strjoin(5, tab, "");
// //    char *r = ft_strjoin(0, tab, " ");
//     printf("Pointer returne : %s\n",r);
//     printf("%p\n",r);
//     free(r);
// }
