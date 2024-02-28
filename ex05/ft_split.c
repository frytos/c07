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


#include <stdio.h>
#include <stdlib.h>

int    is_sep(char *str, char *charset);
int		*count_words_and_char(char *str, char *charset);
char	**ft_split(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	int		index;
	char	**strs;
	int		count[2];
	int		strs_size;

	index = 0;
	strs_size = count_words_and_char(str, charset)[0] + 1;
	strs = (char **) malloc(strs_size * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[strs_size - 1] = 0;


	return (strs);
}


	



void	fill_strs(char *str, char *charset, char **strs)
{
	int	index;
	int	start_word;
	int len_word;
	index = 0;

	if (is_sep(&str[index], charset) && !is_sep(&str[index + 1], charset))
	{
		len_word = 0;
		while (!is_sep(&str[len_word + 1], charset))
			len_word++;
	}
	while (str[index])
	{
		
	}
}

int    is_sep(char *str, char *charset)
{
    int    index;

    index = 0;
    while (charset[index])
    {
        if (str[0] == charset[index])
            return (1);
        index++;
    }
    return (0);
}

int		*count_words_and_char(char *str, char *charset)
{
    int index;
    int in_word;
    int word_count;
	int char_count;
	int	count[2];

    index = 0;
	char_count = 0;
    if (is_sep(&str[0], charset))
	{
		in_word = 0;
		word_count = 0;
	}
	else
	{
		in_word = 1;
		word_count = 1;
	}
    while (str[index])
    {
        if(!(is_sep(&str[index], charset)))
		{
			char_count++;
			if (!in_word)
			{
				in_word = 1;
            	word_count++;
			}
		}
		else
			in_word = 0;
        index++;
    }
	count[0] = word_count;
	count[1] = char_count;
	return (count);
}

int main() {
	char *str[] = {"L'eglise d'Esvres, bien jolie.",
		".a.b.c......xsd.e.f."};
    char *charset[]={" ',.", " "};
	int nb_str = 2;
	int nb_charset = 2;
	int i = 0;
	while (i < nb_charset * nb_str)
	{
		if (i % nb_str == 0)
			printf("---------{>%s<}---------\n", charset[i / nb_str]);
		printf("%s\n", str[i % nb_str]);
		printf("# words = %d\n", count_words_and_char(str[i % nb_str], charset[i / nb_str])[0]);
		printf("# words = %d\n", count_words_and_char(str[i % nb_str], charset[i / nb_str])[1]);
		printf("\n");
		i++;
	}
    return 0;
}