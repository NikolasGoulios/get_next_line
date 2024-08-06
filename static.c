/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:27:32 by ngoulios          #+#    #+#             */
/*   Updated: 2024/08/06 13:14:50 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Static Variable Example 
int fun()
{
    static int count = 0;
    count++;
    return count;
}
 
int main()
{
	//It will print as long as it lives in the program
    printf("%d ", fun());
    printf("%d ", fun());
	printf("%d ", fun());
	printf("%d ", fun());
	printf("%d ", fun());
	printf("%d ", fun());
	printf("%d ", fun());
    return 0;
	// OutPut : 1 2 3 4 5 6 7 
	// If the printf was less , it will print as many as printf is 
}

// --- OPEN Function --- //

/* -The open function will open a file descriptor from a local file 
   -then return will be a small nonnegative number if succesfull 
   -  (-1) if somthing goes wrong with the open function !! EDGE CASE */

// Here is how to test it -- But we will not use it//
/*int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY -O_CREAT);
	return 0;
}*/ 


// --- FLAGS FOR CHECKS AND MEMMORY LEAKS ---  //

// cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h main.c (-D BUFFER_SIZE=10)

// *** LEAKS *** //

//valgrind --leak-check=full ./your_program (LEAKS FOR LINUX)

//-fsanitize=address (LEAKS FOR MAC)

//-D BUFFER_SIZE=100000000 it works super slow, -D BUFFER_SIZE=1000000000 it doesnt work due to memmory.
 