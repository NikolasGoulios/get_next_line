/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:27:32 by ngoulios          #+#    #+#             */
/*   Updated: 2024/08/28 15:57:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
/* 						--- OPEN Function ---

-The open function will open a file descriptor from a local file 
then return will be a small nonnegative number if succesfull 
, (-1) if somthing goes wrong with the open function !! EDGE CASE 

Here is how to test it -- But we will not use it 

/*int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY -O_CREAT);
	return 0;
}*/ 


/*
				--- FLAGS FOR CHECKS AND MEMMORY LEAKS ---  

cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h main.c (-D BUFFER_SIZE=10)

							--- LEAKS ---

//valgrind --leak-check=full ./your_program (LEAKS FOR LINUX)

//-fsanitize=address (LEAKS FOR MAC)

//-D BUFFER_SIZE=100000000 it works super slow, -D BUFFER_SIZE=1000000000 it doesnt work due to memmory.


/*
						--- DEFENCE PREP ---

*QUESTIONS*

1. How does your function handle diles with no new line at the end?
2. What happens if read() retruns an error ? How does your function respond ?
3. Explain why you need static variables for this implementation.
4. What would happen if BUFFER_SIZE is set to a very small or very large 
5. Describe how you manage memory within gnl and related functions
6. How does your functions handle reading from multiple file descriptors simultaneously
7. How does your implementation avoid memory leaks?
8. What happens if the buffer contains a newline character at the start ?
9. Why join is in ft_free, and how does it work ?
10. What would happen if the file is empty?
11. Why you chose calloc over malloc and how does it work ?
12. How would you modify gnl to handle extremely large files more efficiently?
13. What would happen if BS would change during runtime ?
14. Why static variable reset when fd is invalid or BS is non-possitive ?
15. Why you decided to split the functionality into multiple helper functions ?
16. How does your implementation handle very long lines that exceed BS ?

*ASWERS*

1. In the final read() if the EOF is reached the function will return whatever its 
left in the buffer as last line even if its ends with new line.

2. If this is the case of an error and read() returned -1 then the implementation 
will free any allocated memory and returns NULL to indicate an error. If read() returns error
then read_file will return an error same as the big function gnl.

3. Static Variable in C retain their value accross multiple function calls. 

*/
 