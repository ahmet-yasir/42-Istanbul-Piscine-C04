/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaksi <akulaksi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:50:09 by akulaksi          #+#    #+#             */
/*   Updated: 2024/02/11 15:07:35 by akulaksi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
    int	result;
    int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    while (str[i] == '+' || str[i] == '-')
	{
        if (str[i] == '-')
			sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
	{
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
