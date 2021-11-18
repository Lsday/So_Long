/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:30:20 by oronda            #+#    #+#             */
/*   Updated: 2021/11/17 16:16:05 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	print_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
