/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaksi <akulaksi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:29:07 by akulaksi          #+#    #+#             */
/*   Updated: 2024/02/11 17:29:36 by akulaksi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int nb)
{
	int	temp;
	int	digit_count;
	int	digit_char;

	temp = nb;
	digit_count = 1;
	while (temp >= 10)
	{
		temp /= 10;
		digit_count *= 10;
	}
	while (digit_count > 0)
	{
		digit_char = '0' + nb / digit_count;
		write(1, &digit_char, 1);
		nb %= digit_count;
		digit_count /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = 147483648;
		}
		else
			nb = -nb;
	}
	ft_print_number(nb);
}
