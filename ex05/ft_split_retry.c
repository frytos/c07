/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_retry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:36:47 by argrouss          #+#    #+#             */
/*   Updated: 2024/03/04 20:30:27 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   Split str to an array of substrings, which are separated by spaces.      */
/*   We first need to figure the size of the array containing the strings.    */
/*   We need to count the number of substrings we'll need to store in the     */
/*   pointers' array to malloc() the correct memory size. Then we'll fill     */
/*   it with the substrings, for which we'll need to malloc() memory to as    */
/*   we fill the substrings and store the pointers in the array.              */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    **ft_split(char *str, char *sep);
char	**fill_strs(char **strs, char *str, char *sep);
int	count_substrs(char *str, char *sep);
int	is_sep(char *str, int i, char *sep);

char    **ft_split(char *str, char *sep)
{
	char	**strs;
	int	wc;

	wc = count_substrs(str, sep);
	strs = (char **) malloc((wc + 1) * sizeof(char*));
	if (!strs)
		return (NULL);
	strs[wc] = NULL;
	return (fill_strs(strs, str, sep));
}

char	**fill_strs(char **strs, char *str, char *sep)
{
	int	i = 0;
	int	i_strs = 0;
	int	len_word = 0;
	int	i_offset = 0;
	
	while(str[i])
	{
		i_offset = 0;
		len_word = 0;
		if (is_sep(str, i, sep))
			i++;
		if (is_sep(str, i - 1, sep) && !is_sep(str, i, sep))
		{
			while (!is_sep(str, i + len_word, sep))
				len_word++;
			i_offset = len_word;
			strs[i_strs] = (char *) malloc((len_word + 1) * sizeof(char));
				if (!strs[i_strs])
					return (NULL);
			strs[i_strs][len_word] = 0;
			len_word--;
			while (len_word >= 0)
			{
				strs[i_strs][len_word] = str[i + len_word];
				len_word--;
			}
			i_strs++;	
			i += i_offset + 1;
		}
	}
	return (strs);
}

int	count_substrs(char *str, char *sep)
{
	int	i = 0;
	int	wc = 0;

	while (str[i])
	{
		if (!is_sep(str, i - 1, sep) && is_sep(str, i, sep))
			wc++;
		i++;
	}
	return (wc);			
}

int	is_sep(char *str, int i, char *sep)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (i < 0 || i >= len)
		return (1);
	while(*sep)
	{
		if (*sep == str[i] || !str[i])
			return (1);
		sep++;
	}
	return (0);
}

