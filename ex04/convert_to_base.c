/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:15:47 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/24 22:15:52 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		strpos(char *str, char c);
int		ft_atoi_base(char *nbr, char *base_from);
int		get_malloc_size(int n, int len_base);
char	*ft_putnbr_base(int n, char *base_to);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}

char	*ft_putnbr_base(int n, char *base_to)
{
	int		i;
	int		j;
	int		len_base_to;
	char	*nbr_converted;

	len_base_to = strpos(base_to, 0);
	i = get_malloc_size(n, len_base_to);
	nbr_converted = (char *) malloc(i * sizeof(char));
	if (nbr_converted == NULL)
		return ("Error malloc()");
	if (n < 0)
	{
		nbr_converted[0] = '-';
		n = -n;
	}
	nbr_converted[i - 1] = 0;
	j = -1;
	while (n > 0)
	{
		nbr_converted[i - 2 - ++j] = base_to[n % len_base_to];
		n = n / len_base_to;
	}
	return (nbr_converted);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	i;
	int	sign;
	int	n;
	int	len_base_from;

	i = 0;
	sign = 1;
	n = 0;
	while ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	len_base_from = strpos(base_from, 0);
	while (nbr[i])
	{
		n = len_base_from * n + strpos(base_from, nbr[i]);
		i++;
	}
	n *= sign;
	return (n);
}

int	get_malloc_size(int n, int len_base)
{
	int	size;
	int	n_malloc;

	size = 1;
	if (n < 0)
	{
		n_malloc = -n;
		size++;
	}
	else
		n_malloc = n;
	while (n_malloc != 0)
	{
		n_malloc = n_malloc / len_base;
		size++;
	}
	return (size);
}

int	strpos(char *str, char c)
{
	int	pos;

	pos = 0;
	while (str[pos] != c)
		pos++;
	return (pos);
}

// int main(void) {
//     char *input1 = "       -+-+---+--2147483647";
//     char *base_from1 = "0123456789";
//     char *base_to1 = "0123456789";

//     char *input2 = "101010";
//     char *base_from2 = "01";
//     char *base_to2 = "0123456789";

//     char *input3 = "F7A25";
//     char *base_from3 = "0123456789ABCDEF";
//     char *base_to3 = "0123456789";

//     printf("CONVERSION\n\n");

//     printf("Test 1:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input1, base_from1, base_to1, 
// 			ft_convert_base(input1, base_from1, base_to1));

//     printf("Test 2:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input2, base_from2, base_to2, 
// 			ft_convert_base(input2, base_from2, base_to2));

//     printf("Test 3:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input3, base_from3, base_to3, 
// 			ft_convert_base(input3, base_from3, base_to3));

//     return 0;
// }

// int main(int argc, char *argv[]) {
//     if (argc != 4) {
//         printf("Usage: %s <input> <base_from> <base_to>\n", argv[0]);
//         return 1;
//     }

//     char *input = argv[1];
//     char *base_from = argv[2];
//     char *base_to = argv[3];

//     printf("CONVERSION\n\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n", 
//             input, base_from, base_to, 
// 			ft_convert_base(input, base_from, base_to));

//     return 0;
// }