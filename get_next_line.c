/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:05 by ngoulios          #+#    #+#             */
/*   Updated: 2024/05/22 12:58:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char    *get_next_line(int fd)
//{
	//fd is the file descriptior
	// Open the file or create one

	// read the file 
	// return the next line
	
	 // Read tests (learn more info about read function to create more accurate tests)
	 // int buf = 0; is the buffer that will store things from read but..
	 // static int stash = 0; it will store the whole amount of the buff 
	 // buf again 0 to start string other charaters

	 // stash will be freed but only the 
//}

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY -O_CREAT);
	return 0;
}
