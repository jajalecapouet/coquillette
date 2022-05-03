/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:52:11 by njaros            #+#    #+#             */
/*   Updated: 2022/05/03 09:07:27 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dest && src)
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0')
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = '\0';	
	}
}
