/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:15:47 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/29 11:48:01 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		strpos(char *str, char c);
long	ft_atoi_base(char *nbr, char *base_from);
int		get_malloc_size(long n, int len_base);
char	*ft_putnbr_base(long n, char *base_to);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		chkbse_getsz(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (nbr == NULL)
		nbr = ""; 
	if (chkbse_getsz(base_to) <= 1 || chkbse_getsz(base_from) <= 1)
		return (NULL);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}

long	ft_atoi_base(char *nbr, char *base_from)
{
	int		i;
	long	sign;
	long	n;
	long	len_base_from;

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
	while (nbr[i] && strpos(base_from, nbr[i]) >= 0)
	{
		n = len_base_from * n + strpos(base_from, nbr[i]);
		i++;
	}
	n *= sign;
	return (n);
}

char	*ft_putnbr_base(long n, char *base_to)
{
	int		size;
	int		j;
	long	len_base_to;
	char	*nbr_converted;

	len_base_to = strpos(base_to, 0);
	size = get_malloc_size(n, len_base_to);
	nbr_converted = (char *) malloc(size * sizeof(char));
	if (nbr_converted == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr_converted[0] = '-';
		n = -n;
	}
	nbr_converted[size - 1] = '\0';
	j = 0;
	while (n > 0 && size - 2 - j >= 0)
	{
		nbr_converted[size - 2 - j] = base_to[n % len_base_to];
		n = n / len_base_to;
		j++;
	}
	return (nbr_converted);
}

int	get_malloc_size(long n, int len_base)
{
	int		size;
	long	n_malloc;

	size = 1;
	if (n < 0)
	{
		n_malloc = -n;
		size++;
	}
	else if (n == 0)
		return (2);
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
	{
		if (c != '\0' && str[pos] == '\0')
			return (-1);
		pos++;
	}
	return (pos);
}

// int main(void) {
//     char *input1 = "       -+-+---+--2147483647";
//     char *base_from1 = "0123456789";
//     char *base_to1 = "0123456789";
// 
//     char *input2 = "101010";
//     char *base_from2 = "01";
//     char *base_to2 = "0123456789";
// 
//     char *input3 = "F7A25";
//     char *base_from3 = "0123456789ABCDEF";
//     char *base_to3 = "0123456789";
// 
//     char *res;
//     printf("CONVERSION\n\n");
// 
//     res = ft_convert_base(input1, base_from1, base_to1);
//     printf("Test 1:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input1, base_from1, base_to1, res);
//     free(res);
// 
//     res = ft_convert_base(input2, base_from2, base_to2);
//     printf("Test 2:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input2, base_from2, base_to2, res); 
//     free(res);
// 
//     res = ft_convert_base(input3, base_from3, base_to3);
//     printf("Test 3:\n");
//     printf("Input: %s\nBase From: %s\nBase To: %s\nResult: %s\n\n", 
//             input3, base_from3, base_to3, res); 
//     free(res);
// 
//     return 0;
// }