/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeteuse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:00:25 by njaros            #+#    #+#             */
/*   Updated: 2022/03/31 09:34:22 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coquillette.h"

void	*free_lst_analyse(t_list **to_free)
{
	ft_lstclear(to_free, free);
	return (NULL);
}