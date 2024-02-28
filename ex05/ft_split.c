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
char	**fill_strs(char *str, char *charset, char **strs);
char	**ft_split(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		strs_size;


	if (str[0] == 0)
	{
		strs = (char **) malloc(sizeof(char*));
		if (!strs)
			return (NULL);
		strs[0] = 0;
		return (strs);
	}
	if (*charset == 0)
	{
		strs = (char **) malloc(2 * sizeof(char*));
		if (!strs)
			return (NULL);
		strs[0] = str;
		return (strs);
	}
	strs_size = count_words_and_char(str, charset)[0] + 1;
	strs = (char **) malloc(strs_size * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[strs_size - 1] = 0;
	return (fill_strs(str, charset, strs));
}

char	**fill_strs(char *str, char *charset, char **strs)
{
	int	index;
	int index_word;
	int len_word;

	index = 0;
	index_word = 0;
	while (str[index])
	{
		if ((str[index + 1] && is_sep(&str[index], charset) 
			&& !is_sep(&str[index + 1], charset)) 
			|| (index == 0 && !is_sep(&str[index], charset)))
		{
			//printf("  {->%s<-}[%d]", &str[index], index);
			if (index != 0 || is_sep(&str[index], charset))
				index++;
			//printf("if[%d]{->%s<-}\n", index, &str[index]);
			len_word = 0;
			while (!is_sep(&str[index + len_word], charset))
				len_word++;
			strs[index_word] = (char *) malloc((len_word + 1) * sizeof(char));
			if (strs[index_word] == NULL)
				return (NULL);
			strs[index_word][len_word] = '\0';
			while (len_word-- > 0)
				strs[index_word][len_word] = str[index + len_word];
			index_word++;
		}
		index++;
	}
	return (strs);
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
	
    if (is_sep(&str[0], charset) || !*str)
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

// int main() {
// 	char *str[] = {"L'eglise d'Eve, bien jolie.",
// 		".a.b.c......xsd.e.f.",
// 		//"https://www.google.com/search?q=pointer+of+pointers+&tbm=isch&ved=2aBOUQ2-cCegQIABAA&oq=pointer+of+pointers+&gs_lp=EgNFGEMYiAYB&sclient=img&ei=kmDdQqA4&bih=2395&biw=1440#imgrc=ljTaIKmOcM",
// 		""};
//     char *charset[]={" ',.", " ", "&+#/.?=-_", ""};
// 	int nb_str = 3;
// 	int nb_charset = 4;
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	char **strs;
// 	while (i < nb_charset * nb_str)
// 	{
// 		if (i % nb_str == 0)
// 			printf("###############################################{%s}###############################################\n", charset[i / nb_str]);
// 		printf("\t\t\t{%s}\t--//-->\t[%s]\t with ", str[i % nb_str], charset[i / nb_str]);
// 		printf("%d words counted", count_words_and_char(str[i % nb_str], charset[i / nb_str])[0]);
// 		printf(" and %d non-sep chars counted\n", count_words_and_char(str[i % nb_str], charset[i / nb_str])[1]);
// 		strs = ft_split(str[i % nb_str], charset[i / nb_str]);
// 		printf("-banana- %p -split-\n", strs);
// 		if (strs == NULL)
// 			printf("Bazingaaaa : (%p) NULL pointer returned\n", strs);
// 		while (strs != NULL && strs[j])
// 		{
// 			while (k++ < j)
// 				printf("---");
// 			printf("-> strs[%d] : \"%s\"\n", j, strs[j]);
// 			j++;
// 			k = 0;
// 		}
// 		j = 0;
// 		printf("(i=%d)\n\n",i);
// 		i++;
// 	}
//     return 0;
// }

int main() {
	char *str[] = {"L'eglise d'Eve, bien jolie.",
		".a.b.c......xsd.e.f.",
		//"https://www.google.com/search?q=pointer+of+pointers+&tbm=isch&ved=2aBOUQ2-cCegQIABAA&oq=pointer+of+pointers+&gs_lp=EgNFGEMYiAYB&sclient=img&ei=kmDdQqA4&bih=2395&biw=1440#imgrc=ljTaIKmOcM",
		""};
    char *charset[]={" ',.", " ", "&+#/.?=-_", ""};
	int nb_str = 3;
	int nb_charset = 4;
	int i = 0;
	int j = 0;
	char **strs;
	while (i < nb_charset * nb_str)
	{
		if (i % nb_str == 0)
			printf("###############################################{%s}###############################################\n", charset[i / nb_str]);
		printf("\t\t\t{%s}\t--//-->\t[%s]\t with ", str[i % nb_str], charset[i / nb_str]);
		printf("%d words counted", count_words_and_char(str[i % nb_str], charset[i / nb_str])[0]);
		printf(" and %d non-sep chars counted\n", count_words_and_char(str[i % nb_str], charset[i / nb_str])[1]);
		strs = ft_split(str[i % nb_str], charset[i / nb_str]);
		printf("-banana- %p -split-\n", strs);
		if (strs == NULL)
			printf("Bazingaaaa : (%p) NULL pointer returned\n", strs);
		while (strs != NULL && strs[j])
		{
			printf("        %s\t",strs[j]);
			j++;
		}
		j = 0;
		printf("\n");
		while (strs != NULL && strs[j])
		{
			printf("strs[%d] |-->\t", j);
			j++;
		}
		j = 0;
		printf("(i=%d)\n\n",i);
		i++;
	}
    return 0;
}