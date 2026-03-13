/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:12:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/13 13:17:58 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void  parsing(char *argv, t_gc **collector);

void  parsing(char *argv, t_gc **collector)
{
   char  *test;

   test = gc_malloc(collector, ft_strlen(argv));
   ft_putstr_fd(test, 1);
   gc_clear(collector);
   exit (1);
}
