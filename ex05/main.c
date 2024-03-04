/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:52 by argrouss          #+#    #+#             */
/*   Updated: 2024/03/04 20:37:22 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ft_split_retry.c"

int main(void)
{
	char *str = "     British soldiers are \"on the ground\" in Ukraine helping Kyiv’s forces fire long-range Storm Shadow missiles, according to a leak in Russian media of a top-secret call involving German air force officers.\nThe Kremlin said the leak demonstrated the direct involvement of the \"collective west\" in the war in Ukraine, while former British defence ministers expressed frustration with the German military in response to the revelations.";
	char *sep = " ,.\"\n";
	char **strs = ft_split(str, sep);

	printf("strs : %p\n", strs);
	int	i = 0;
	while (strs[i])
	{
		printf("strs[%d]{%p} = %s\n", i, strs[i], strs[i]);
		i++;
	}
}
