/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:27:32 by ngoulios          #+#    #+#             */
/*   Updated: 2024/08/28 16:50:01 by ngoulios         ###   ########.fr       */
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

3. Static Variable in C retain their value accross multiple function calls. In gnl the satic variable its
crusial cause it stores data through function calls that hasnt been returned yet or not enough data where read to buffer 
in order to meet the criteria to be retruned. Static variable is our storage room for data that hasnt been yet 
preccesed.

4. Memory is dynamicly allocated using ft_calloc (instead of malloc (see q.11)) whenever a new buffer or line is needed.
Each time a line is returned by gnl the buffer is being updated by the ft_next which creates a new buffer with the remaining 
date. If error, the allocated memory is all freed and returns NULL.
Additionaly, at the EOF or invalid file descriptor then memory in the tatic buffer is freed too.

5.		Small BS : the funcion will still work correctly but it will make many more calls of read() to gather enough data.
	This ofcurse leads to performance inefficiencies but wont affect correctness (almost cause its going to call a function so many times 
	and this potentially (hardware  reasons, lack of enough memory) can cause an issue with the return statments (read coud fail))

		Big BS: tIf BUFFER_SIZE is very large, the function might read a significant portion of the file in a single read() call. 
	This can be efficient in terms of reducing the number of system calls, but it will use more memory to store the buffer.

6. Using an array of static buffers indexed  by the fd. Each time that gnl is called with a different fd, it will use the 
coresponding buffer for that fd ensuring that the state for each fd is preserved independently.

7. (see q.4) By handling the memory thats been allocated and freed when error occures or eof still everything will be freed.

8. If the buffer starts with a new line char, the ft_line will return a strig contained by just that nl as it is consider as 
a valid C line. Then the ft_next will update the buffer and free that nl and then the function will continue add data if any,

9. What has been allocated has to be freed, as a general rule for memory allocation. 

10. If the file is emty, the first call will return 0, indicating that the EOF has been reached. The gnl will return NULL immidiately 
cause there is no data to return. 

11. ft_calloc over malloc ? Yes, cause we will make sure that any memory that will be allocated will be set immidiatelly to
\0 and we will ensure that there will be no garbage data in between. Malloc allocates without initializing it thats why calloc 
is chosen. Ensures safety, starts with a known inviroment of 0s.

12. 



*/
 