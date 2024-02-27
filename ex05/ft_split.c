/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:46:20 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/27 02:00:05 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(char *str, char *charset);
int		get_malloc_size(char *str, char *charset);
int		is_sep(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if
	}




}

int	get_malloc_size(char *str, char *charset)
{
	int	index;
	int	start_str;
	int size;
	index = 0;
	start_str = 0;
	size = 0;
	while (str[index])
	{
		
		if(is_sep(&str[index], charset))
		{
			size += index - 1 - start_str;

		}
	}
}

int	is_sep(char *str, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (str[0] == charset[index])
			return (1);
		index++;
	}
	return (0);
}