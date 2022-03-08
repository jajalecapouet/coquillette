/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:33:39 by njaros            #+#    #+#             */
/*   Updated: 2021/11/02 15:33:41 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + ('a' - 'A'));
	return (c);
}
