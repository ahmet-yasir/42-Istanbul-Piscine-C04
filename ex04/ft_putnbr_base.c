/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaksi <akulaksi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:08:40 by akulaksi          #+#    #+#             */
/*   Updated: 2024/02/11 16:12:17 by akulaksi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_print_number(int nb, char *base)
{
	unsigned long temp;
	int	digit_count;
	int	digit_char;
    unsigned int base_len;

    base_len = ft_strlen(base);
	temp = nb;
	digit_count = 1;
	while (temp >= base_len)
	{
		temp /= base_len;
		digit_count *= base_len;
	}
	while (digit_count > 0)
	{
		digit_char = base[nb / digit_count];
		write(1, &digit_char, 1);
		nb %= digit_count;
		digit_count /= base_len;
	}
}

int ft_base_control(char *base)
{
    int i;
    int j;

    i = 0;
    if (!(base[0] == '\0' || ft_strlen(base) < 2))
        return (0);
    while (base[i] != '\0')
    {
        j = i + 1;
        while (base[j] != '\0')
        {
            if (base[i] == base[j] && i != j)
                return (0);
            j++;
        }
        if (base[i] == '+' || base[i] == '-')
            return (0);
        else if (base[i] <= 32 || base[i] >= 127)
            return (0);
        i++;
    }
    return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		    nbr = -nbr;
	}
    if (!(base[0] == '\0' || ft_strlen(base) < 2))
	    ft_print_number(nbr,base);
}
int main ()
{
    char hex[] = "0123456789abcdef";
    ft_putnbr_base(-2147483648,hex);
    return(0);
}