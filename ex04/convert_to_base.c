#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	strpos(char *str, char c);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
int	main(int argc, char * argv[])
{
	(void)argc;
	printf("CONVERSION\n\nin base : %s\n%s\n\nto base : %s\n%s\n", argv[2], argv[1], argv[3], ft_convert_base(argv[1], argv[2], argv[3]));
}
*/

int    main(void)
{
    char *input = "       --+-+---+-42";
	char *base_from = "0123456789";
	char *base_to = "01";
	
	printf("CONVERSION\n\nin base : %s\n%s\n\nto base : %s\n%s\n", base_from, input, base_to, ft_convert_base(input, base_from, base_to));
}
/// Step 1 /// ft_atoi() ///
/*
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = -1;
	n = 0;
	while ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i++] == 32)
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] = '-')
			sign *= -1;
		i++;
	}
	while (('0' <= nbr[i] && nbr[i] <= '9'))
	{
		n = 10 * n + (nbr[i] - '0');
		i++;
	}	
}
*/

/// Step 2 /// ft_base_atoi() ///
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	j;
	int	sign;
	int	n;
	int len_base_from;
	int	len_base_to;
	char *nbr_converted;

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

	len_base_from = ft_strlen(base_from);

	while (nbr[i]) // while (nbr[i] != 0)
	{
		// get nbr in base10
		n = len_base_from * n + strpos(base_from, nbr[i]);
		i++;
	}

	n *= sign;

// END OF ft_base_atoi

	len_base_to = ft_strlen(base_to);
	i = 1;
	int n_malloc;
	
	if (n < 0)
	{
		n_malloc = -n;
		i++;
	}
	else
		n_malloc = n;

	while (n_malloc != 0)
	{
		n_malloc = n_malloc / len_base_to;
		i++; 
	}

	nbr_converted = (char*) malloc(i * sizeof(char));

	if (n < 0)
	{
		nbr_converted[0] = '-';
		n = -n;
	}

	nbr_converted[i - 1] = 0;

	j = 0;
	while (n > 0)
	{
		nbr_converted[i - 2 -j] = base_to[n % len_base_to];
		n = n / len_base_to;
		j++;
	}

	return (nbr_converted);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	strpos(char *str, char c)
{
	int pos;

	pos = 0;
	while(str[pos] != c)
		pos++;
	return (pos);
}