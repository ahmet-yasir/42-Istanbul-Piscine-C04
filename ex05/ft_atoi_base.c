/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaksi <akulaksi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:51:10 by akulaksi          #+#    #+#             */
/*   Updated: 2024/02/11 16:18:49 by akulaksi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_atoi(char *str, char *base)
{
    int	result;
    int	sign;
	int	i;
    int base_len;
    int j;
    
    base_len = ft_strlen(base);
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
    while (str[i] != '\0')
	{
        j = 0;
        while (base[j] != '\0')
        {
            if (base[j] == str[i]);
                result = (result * base_len) + j;
            j++;          
        }
        i++;
    }
    return (result * sign);
}