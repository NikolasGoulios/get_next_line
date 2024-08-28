
# Get Next Line in C

This project is about programming a function that returns a line from a file descriptor one line at a time.


## KEY CONCEPTS

File Descriptors (Fd) 
- A file descriptor is an integer that uniquely identifies an open file in a computer’s operating system. For example, standard input (stdin) usually has FD 0, standard output (stdout) has FD 1, and standard error (stderr) has FD 
- In this project, you’ll be reading from a file descriptor, which means you need to understand how to work with files in C.

Reading from a File. 
- Reading from a file involves opening the file, reading its content, and then closing the file. 
- The read function is used to read data from a file descriptor.
Buffer 
- A buffer is a temporary storage area in memory. When reading from a file, data is read into a buffer before being processed. 
- The size of the buffer affects how much data is read at a time.

Static Variables 
- A static variable retains its value between function calls. This is crucial for maintaining the state of the buffer between calls to get_next_line.
Dynamic Memory Allocation 
- Using functions like malloc and free to allocate and deallocate memory dynamically as needed.


## Lessons Learned

- Lesson learned, first understanding the project at its core its crusial. I re-buld the whole thing 5 times with almost 5 approaches. Before you switch try to address the issue and then change the algorithm. 
- Linux and MacOs has more differences than you expected. You'll find out (OPEN_MAX)
- Practice simple exercises to understand how those new consepts are working.
- Don't rely on online testers, you ll never understand the project. Make your own main, a simple one and start building it block by block. Dont be like me, be better.

## Exercises

This way you will get to be more comfortable with functions that opening and reading files.

- Read from Standard Input : Write a simple program to read lines from standard input and print them.
- Use a Buffer: Modify the program to read data into a buffer and process it from there.
- Implement Static Variables: Modify the program to use a static variable to keep track of the buffer between function calls.

## 🛠 Skills
C  , Makefile


## FAQ

#### What is the BUFFER_SIZE?

Ask your peers
#### How do I start?

By understanding what project asks and draw it. 


## 🔗 Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/nikolas-goulios)



## Authors

- [@NikolasGoulios](https://www.github.com/NikolasGoulios)


## Feedback

If you have any feedback, please reach out ngoulios@outlook.com
