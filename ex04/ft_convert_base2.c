/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:54:31 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/23 10:44:34 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int     check_base_and_size(char *str);
int     ft_atoi_base(char *str, char *base);
// int     check_n_size(char *base);
int     ft_if_char_in_base_which(char *str, char *base, int base_nb);
long    ft_add_coeff(char *str, char *base, int base_nb, long *ptr_u_long);
void    ft_putnbr_base(int nbr, char *base, char *r);
// void    ft_putchar(char c);
void    get_and_print_significand(long long_nbr, int base_number, char *base, char *r);
// char    convert_in_base(int significand, char *base);

int ft_atoi_base(char *str, char *base)
{
    int     index;
    int     sign;
    long    u_long;
    long    *ptr_u_long;

    if (check_base_and_size(base) <= 1)
        return (0);
    index = 0;
    while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
        index++;
    sign = 1;
    while (str[index] == 45 || str[index] == 43)
    {
        sign *= 44 - str[index];
        index++;
    }
    u_long = 0;
    ptr_u_long = &u_long;
    if (ft_if_char_in_base_which(&str[index], base, check_base_and_size(base)) < 0)
        return (0);
    ft_add_coeff(&str[index], base, check_base_and_size(base), ptr_u_long);
    return ((int)(sign * u_long));
}

long    ft_add_coeff(char *str, char *base, int base_nb, long *ptr_u_long)
{
    int     rank;
    int     index_rank;
    long    to_add;

    if (ft_if_char_in_base_which(&str[1], base, base_nb) >= 0)
    {
        rank = ft_add_coeff(&str[1], base, base_nb, ptr_u_long);
        index_rank = rank;
        to_add = ft_if_char_in_base_which(&str[0], base, base_nb);
        while (index_rank >= 0)
        {
            to_add *= base_nb;
            index_rank--;
        }
        *ptr_u_long += to_add;
        return (rank + 1);
    }
    else
    {
        *ptr_u_long += ft_if_char_in_base_which(&str[0], base, base_nb);
        return (0);
    }
}

int ft_if_char_in_base_which(char *str, char *base, int base_nb)
{
    int base_index;

    base_index = 0;
    while (base_index < base_nb)
    {
        if (str[0] == base[base_index])
            return (base_index);
        else
            base_index++;
    }
    return (-1);
}

void    ft_putnbr_base(int nbr, char *base, char *r)
{
    int     base_number;
    long    long_nbr;
    int		index;

    long_nbr = nbr;
    index = 0;
    if (check_base_and_size(base) > 1)
        base_number = check_base_and_size(base);
    else
        return ;
    if (long_nbr < 0)
    {
        *r = '-'; // ft_putchar('-');
	index++;
        long_nbr = -long_nbr;
    }
    get_and_print_significand(long_nbr, base_number, base, r++);
}

void    get_and_print_significand(long long_nbr, int base_number, char *base, char *r)
{
    if (long_nbr / base_number)
    {
        get_and_print_significand(long_nbr / base_number, base_number, base, r++);
        *r = base[long_nbr % base_number]; // ft_putchar(convert_in_base(long_nbr % base_number, base));
    }
    else
        *r = base[long_nbr % base_number]; // ft_putchar(convert_in_base(long_nbr % base_number, base));
}

// char    convert_in_base(int significand, char *base) // can be removed and reintegrated
// {
//     return (base[significand]);

// int check_n_size(char *str)
// {
//     int len;
//     int search_index;                                     
//                                                           
//     len = 0;                                              
//     while (str[len] != 0)                                 
//     {
//         if (str[len] == 43 || str[len] == 45)             
//             return (-3);                                  
//         if (str[0] == 32 || (str[0] >= 9 && str[0] <= 13))
//             return (-4);                                  
//         search_index = 1;                                 
//         while (str[len + search_index] != 0)              
//         {                                                 
//             if (str[len] == str[len + search_index])      
//                 return (-2);                              
//             search_index++;                               
//         }                                                 
//         len++;                                            
//     }                                                     
//     if (len > 1)                                          
//         return (len);                                     
//     else                                                  
//         return (-1);                                      
// } 


// void    ft_putchar(char c)
// {
//     write(1, &c, 1);
// }


