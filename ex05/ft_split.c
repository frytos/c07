/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:46:20 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/29 08:20:49 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_sep(char str, char *charset);
int		count_words(char *str, char *charset);
char	**fill_strs(char *str, char *charset, char **strs);
char	**ft_split(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**strs;

	if (str == NULL)
		str = "";
	if (charset == NULL)
		charset = "";
	if (str[0] == 0)
	{
		strs = (char **) malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	strs = (char **) malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[count_words(str, charset)] = NULL;
	return (fill_strs(str, charset, strs));
}

char	**fill_strs(char *str, char *charset, char **strs)
{
	int	i;
	int	i_word;
	int	len_word;

	i = 0;
	i_word = 0;
	while (str[i])
	{
		if ((is_sep(str[i - 1], charset) && !is_sep(str[i], charset))
			|| (i == 0 && !is_sep(str[i], charset)))
		{
			len_word = 0;
			while (!is_sep(str[i + len_word], charset) && str[i + len_word])
				len_word++;
			strs[i_word] = (char *)malloc((len_word + 1) * sizeof(char));
			if (strs[i_word] == NULL)
				return (NULL);
			strs[i_word][len_word] = '\0';
			while (len_word-- > 0)
				strs[i_word][len_word] = str[i + len_word];
			i_word++;
		}
		i++;
	}
	return (strs);
}

int	is_sep(char str, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (str == charset[index])
			return (1);
		index++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	index;
	int	word_count;

	if (str[0] == 0)
		return (0);
	index = 1;
	word_count = 0;
	if (!(is_sep(str[0], charset)))
		word_count++;
	while (str[index])
	{
		if (is_sep(str[index - 1], charset) && !(is_sep(str[index], charset)))
			word_count++;
		index++;
	}
	return (word_count);
}

// int main() {
// 	char *str[] = {NULL, "L'eglise d'Eve,   bien jolie.",
// 		".a.b.c......xsd.e.f.",
// 		"      ",
// 		 "https://www.google.com/search?q=pointer+of+pointers+&tbm=isch&ved="
// 		 	"2aBOUQ2-cCegQIABAA&oq=pointer+of+pointers+&gs_lp=EgNFGEMYiAYB&s"
// 			"client=img&ei=kmDdQqA4&bih=2395&biw=1440#imgrc=ljTaIKmOcM",
// 		""};
//     char *charset[]={NULL, " ',.", " ", "&+#/.?=-_", "",
// 			"abcdefghijklmnopqrstuvwxyz"};
// 	int nb_str = 6;
// 	int nb_charset = 6;
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	char **strs;
// 	while (i < nb_charset * nb_str)
// 	{
// 		if (charset[i / nb_str] != NULL && str[i % nb_str] != NULL)
// 		{
// 			if (i % nb_str == 0)
// 				printf("###############################################"
// 					"{%s}###############################################\n",
// 					charset[i / nb_str]);
// 			printf("\t\t\t{%s}\t--//-->\t[%s]\t with ", str[i % nb_str],
// 				charset[i / nb_str]);
// 			printf("%d words counted\n", count_words(str[i % nb_str],
// 				charset[i / nb_str]));
// 		}
// 		strs = ft_split(str[i % nb_str], charset[i / nb_str]);
// 		printf("-banana- %p -split-\n", strs);
// 		if (strs == NULL)
// 			printf("Bazingaaaa : (%p) NULL pointer returned\n", strs);
// 		while (strs != NULL && strs[j] != NULL)
// 		{
// 			while (k++ < j)
// 				printf("---");
// 			printf("%p-> strs[%d] : \"%s\"\n",&strs[j], j, strs[j]);
// 			k = 0;
// 			free(strs[j]);
// 			j++;
// 		}
// 		free(strs[j]);
// 		j = 0;
// 		printf("(i=%d)\n\n",i);
// 		free(strs);
// 		i++;
// 	}
//     return 0;
// }

// int main() {
// 	char *str[] = {"L'eglise d'Eve, bien jolie.",
// 		".a.b.c......xsd.e.f.",
// 		"https://www.google.com/search?q=pointer+of+pointers+&tbm=isch&ved="
// 			"2aBOUQ2-cCegQIABAA&oq=pointer+of+pointers+&gs_lp=EgNFGEMYiAYB&s"
// 			"client=img&ei=kmDdQqA4&bih=2395&biw=1440#imgrc=ljTaIKmOcM",
// 		""};
//     char *charset[]={" ',.", " ", "&+#/.?=-_", ""};
// 	int nb_str = 3;
// 	int nb_charset = 4;
// 	int i = 0;
// 	int j = 0;
// 	char **strs;
// 	while (i < nb_charset * nb_str)
// 	{
// 		if (i % nb_str == 0)
// 			printf("###############################################"
// 				"{%s}###############################################\n",
// 				charset[i / nb_str]);
// 		printf("\t\t\t{%s}\t--//-->\t[%s]\t with ", str[i % nb_str],
// 			charset[i / nb_str]);
// 		printf("%d words counted\n", count_words(str[i % nb_str],
// 			charset[i / nb_str]));
// 		strs = ft_split(str[i % nb_str], charset[i / nb_str]);
// 		printf("-banana- %p -split-\n", strs);
// 		if (strs == NULL)
// 			printf("Bazingaaaa : (%p) NULL pointer returned\n", strs);
// 		while (strs != NULL && strs[j])
// 		{
// 			printf("        %s\t",strs[j]);
// 			j++;
// 		}
// 		j = 0;
// 		printf("\n");
// 		while (strs != NULL && strs[j])
// 		{
// 			printf("strs[%d] |-->\t", j);
// 			j++;
// 		}
// 		j = 0;
// 		printf("(i=%d)\n\n",i);
// 		i++;
// 	}
//     return 0;
// }

		// if ((str[index + 1] && is_sep(str[index], charset)
		// 		&& !is_sep(str[index + 1], charset))
		// 	|| (index == 0 && !is_sep(str[index], charset)))
		// {
		// 	if (index != 0 || is_sep(str[index], charset))
		// 		index++;
		// 	len_word = 0;
		// 	while (!is_sep(str[index + len_word], charset))
		// 		len_word++;
		// 	strs[index_word] = (char *) malloc((len_word + 1) * sizeof(char));
		// 	if (strs[index_word] == NULL)
		// 		return (NULL);
		// 	strs[index_word][len_word] = '\0';
		// 	while (len_word-- > 0)
		// 		strs[index_word][len_word] = str[index + len_word];
		// 	index_word++;
		// }
