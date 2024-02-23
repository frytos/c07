/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:54:13 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/23 10:54:42 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char    *ft_strdup(char *src);
// int	ft_strlen(char *str);
int	len_in_base(long nb, char *base);
int     check_base_and_size(char *str);

int     ft_atoi_base(char *str, char *base);
// int     check_n_size(char *base);
int     ft_if_char_in_base_which(char *str, char *base, int base_nb);
long    ft_add_coeff(char *str, char *base, int base_nb, long *ptr_u_long);
void    ft_putnbr_base(int nbr, char *base, char *r);
// void    ft_putchar(char c);
void    get_and_print_significand(long long_nbr, int base_number, char *base, char *r);
// char    convert_in_base(int significand, char *base);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	arr_len[10];
	//char	*n;
	char	*r;
	long	nb_int;

	// arr_len[0] = ft_strlen(nbr);
	if (check_base_and_size(base_from) < 0 || check_base_and_size(base_from) < 0)
		return (NULL);
	arr_len[1] = check_base_and_size(base_from);
	arr_len[2] = check_base_and_size(base_to);
	// n = ft_strdup(nbr);
	nb_int = ft_atoi_base(nbr, base_from);
	if (nb_int < INT_MIN || INT_MAX < nb_int)
		return (NULL);
	r = malloc(len_in_base(nb_int, base_to));
	// if (r == NULL)
	// 	return (NULL);
	ft_putnbr_base(nb_int, base_to, r);	
	return (r);
}

int	len_in_base(long nb, char *base)
{
	int	len_base;
	int	len_nb;

	len_nb = 1;
	if (nb < 0)
	{
		nb = - nb;
		len_nb++;
	}
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (nb / len_base > 0)
	{
		len_nb++;
		nb /= len_base;
	}
	return (len_nb);
}

int check_base_and_size(char *str)
{
    int len;
    int search_index;

    len = 0;
    while (str[len] != 0)
    {
        if (str[len] == 43 || str[len] == 45)
            return (-3);
        search_index = 1;
        while (str[len + search_index] != 0)
        {
            if (str[len] == str[len + search_index])
                return (-2);
            search_index++;
        }
        len++;
    }
    if (len > 1)
        return (len);
    else
        return (-1);
}

// char    *ft_strdup(char *src)
// {
//     int     index;
//     int     len;
//     char    *duplicate;
// 
//     len = 0;
//     while (src[len])
//         len++;
//     duplicate = malloc((len + 1) * sizeof(char));
//     if (duplicate == NULL)
//         return (NULL);
//     index = 0;
//     while (src[index])
//     {
//         duplicate[index] = src[index];
//         index++;
//     }
//     duplicate[index] = 0;
//     return (duplicate);
// }

// int	ft_strlen(char *str)
// {
// 	int	len;
// 
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return(len);
// }

int main(int argc, char **argv)
{
    (void)argc;
    // (void)argv;
    // printf("%s",ft_convert_base("ff", "0123456789abcdef", "01"));
    printf("%s",ft_convert_base(argv[1], argv[2], argv[3]));
    //ex : ./a.out 1458 0123456789 0123456789abcdef
}
