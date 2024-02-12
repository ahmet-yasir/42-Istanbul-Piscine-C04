/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaksi <akulaksi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:08:40 by akulaksi          #+#    #+#             */
/*   Updated: 2024/02/12 13:51:58 by akulaksi         ###   ########.fr       */
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

void	ft_print_number(long nb, char *base)
{
	long	temp;
	long	digit_count;
	long	digit_char;
	long	base_len;

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

int	ft_base_control(char *str)
{
	int	i;
	int	j;
	int	x;

	x = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || x == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] >= 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	temp;

	temp = nbr;
	if (ft_base_control(base) == 1)
	{
		if (temp < 0)
		{
			write(1, "-", 1);
			temp = -temp;
		}
		ft_print_number(temp, base);
	}
}
