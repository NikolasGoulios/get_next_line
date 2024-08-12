**Name: 			get_next_line
Prototype:		char *get_next_line(int fd);
Parameters:		fd —> file descriptor
Return Value: 	Read line —> correct behaviour
				NULL —> nothing else to read OR error.
Ext.Functions: 	read, malloc, free
Turn in Files: 	1. get_next_line.c
				2. get_next_line_utils.c,
				3. get_next_line.h**
** Get Next Line **

This project is about programming a function that returns a line from a file
descriptor. And what does that mean? Lets find out.

GENERAL INFORMATIONS

Whats is the purpose of get next line algorithm ?
	• Provide a convenient way to read lines of text from a one line at a time.
		file or standard input, 
	• Abstract away complexity of handling input buffers and managing partial reads.

Where can it be useful in the future?
	• Text Processing: Useful for reading configuration files, logs, and other text- based data.
	• File Parsing: Applicable to parsing CSV files, structured logs, and large datasets.
	• Interactive Applications: Essential for reading user input line by line in command line applications.
	• Network Programming: Useful for reading data from network sockets in arbitrary chunks.

What other features can be added to this function ?
	• Different line endings (Unix \n, Windows \r\)
	• Delimiter Customisation (;)

What this project is trying to teach us?
	• Buffer management
	• Memory Management
	• State Maintenance(static variables)
	• System
  
KEY CONCEPTS

1. File Descriptors (Fd)
   • A file descriptor is an integer that uniquely identifies an open file in a
		computer’s operating system. For example, standard input (stdin) usually has FD 0,
		standard output (stdout) has FD 1, and standard error (stderr) has FD 2.
   • In this project, you’ll be reading from a file descriptor, which means you need
		to understand how to work with files in C.
2. Reading from a File.
   • Reading from a file involves opening the file, reading its content, and then
		closing the file.
   • The read function is used to read data from a file descriptor.
3. Buffer
   • A buffer is a temporary storage area in memory. When reading from a file, data
		is read into a buffer before being processed.
   • The size of the buffer affects how much data is read at a time.
4. Static Variables
   • A static variable retains its value between function calls. This is
		crucial for maintaining the state of the buffer between calls to get_next_line.
5. Dynamic Memory Allocation
   • Using functions like malloc and free to allocate and deallocate memory
		dynamically as needed.
                                                 
   
EDGE CASES

1. End of file.
2. Empty files.
3. Files with lines longer than the buffer size.

EXCERCISES

This way you will get to be more comfortable with functions that opening and reading files.
1. Read from Standard Input
	• Write a simple program to read lines from standard input and print them.
2. Use a Buffer
	• Modify the program to read data into a buffer and process it from there.
3. Implement Static Variables
	• Modify the program to use a static variable to keep track of the buffer
 		between function calls.

BONUS TIPS 

 1. Define OPEN_MAX as a macro to the header file because in Linux OS is 


CONTRIBUTIONS
This project is a personal exercise, and contributions are not currently being accepted. However, if you have suggestions or improvements, feel free to fork the repository and experiment on your own.

CREDITS
This project was inspired by challenges in understanding file handling and memory management in C. It’s an implementation based on personal learning and exploration.

CONTACTS
If you have any questions or just want to connect, you can reach me at:

	•	Email: ngoulios@student.hive.com
	•	GitHub: NikolasGoulios
     
                               