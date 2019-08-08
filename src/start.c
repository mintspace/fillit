/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbubnov <dbubnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:54:17 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/19 15:06:45 by dbubnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_figure	*head;
	int			fd;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error(-1);
	head = figure_reader(fd);
	close(fd);
	check_oll_figures(head);
	refresh(head, get_board_size(head));
	fill_figure_with_letters(head);
	back_track(head);
	fillit(head);
	print(head);
	dell_all_figures(head);
}
