/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:42:09 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/23 03:51:13 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
int		ft_strcat(char *dest, char *src, int len_dest);
int		get_malloc_len(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		index_cat;
	char	*str_cat;

	if (size == 0)
		return (malloc(sizeof(char)));
	str_cat = malloc(get_malloc_len(size, strs, sep) * sizeof(char));
	if (str_cat == NULL)
		return (NULL);
	index = 0;
	index_cat = 0;
	while (index < size)
	{
		if (strs[index][0])
			index_cat += ft_strcat(str_cat, strs[index], index_cat);
		if (index < size - 1 && strs[index][0])
			index_cat += ft_strcat(str_cat, sep, index_cat);
		index++;
	}
	str_cat[index_cat] = 0;
	return (str_cat);
}

int	get_malloc_len(int size, char **strs, char *sep)
{
	int	len;
	int	empty_string;
	int	index;

	len = 0;
	empty_string = 0;
	index = 0;
	while (index < size)
	{
		if (!strs[index][0])
			empty_string++;
		else
			len += ft_strlen(strs[index]);
		index++;
	}
	len += (size - empty_string - 1) * ft_strlen(sep);
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
// //    char    *tab[] = {"salut","comment","ca","va","?"};
//     char    *tab[] = {"salut","","ca","va","?"};
//     char *r = ft_strjoin(5, tab, "-");
// //    char *r = ft_strjoin(5, tab, "");
// //    char *r = ft_strjoin(0, tab, " ");
//     printf("%s\n",r);
//     printf("%p\n",r);
// }