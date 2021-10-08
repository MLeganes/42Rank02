/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:11:06 by amorcill          #+#    #+#             */
/*   Updated: 2021/10/08 14:12:43 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>		// [man 2 open]
# include <unistd.h>	// [man 2 read]
# include <stdio.h>		// [man 3 printf]
# include <stdlib.h>	// [man free]

char	*get_next_line(int fd);
#endif
