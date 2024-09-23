
# Get Next Line in C

This project is about programming a function that returns a line from a file descriptor. One line at a time.
The subject doesn not require Makefiles, but I like to keep things tidy and nice.
Allways make your own mains, allways. I know you think its ok not to but... but its a great way to understand wht youre doing.


## KEY CONCEPTS

- File Descriptors (Fd) 

- Reading from a File. 

- Buffer 

- Static Variables 

- Dynamic Memory Allocation 


## Lessons Learned

- Lesson learned, first understanding the project at its core its crusial. I re-buld the whole thing 5 times with almost 5 approaches. Before you switch try to address the issue and then change the algorithm. 
- Linux and MacOs has more differences than you expected. You'll find out (OPEN_MAX (BONUS))
- Practice simple exercises to understand how those new consepts are working.
- Don't rely on online testers, you ll never understand the project. Make your own main, a simple one and start building it block by block. 
Dont be like me, be better.

## Exercises

This way you will get to be more comfortable with functions that opening and reading files.

- Read from Standard Input : Write a simple program to read lines from standard input and print them.
- Use a Buffer: Modify the program to read data into a buffer and process it from there.
- Implement Static Variables: Modify the program to use a static variable to keep track of the buffer between function calls.

## 🛠 Skills
C  , Makefile


# GNL Defence Preparation

## ❓ Questions

1. How does your function handle files with no newline at the end?
2. What happens if `read()` returns an error? How does your function respond?
3. Explain why you need static variables for this implementation.
4. What would happen if `BUFFER_SIZE` is set to a very small or very large value?
5. Describe how you manage memory within GNL and related functions.
6. How does your function handle reading from multiple file descriptors simultaneously?
7. How does your implementation avoid memory leaks?
8. What happens if the buffer contains a newline character at the start?
9. Why is `join` in `ft_free`, and how does it work?
10. What would happen if the file is empty?
11. Why did you choose `calloc` over `malloc` and how does it work?
12. How would you modify GNL to handle extremely large files more efficiently?
13. What would happen if `BUFFER_SIZE` changes during runtime?
14. Why do static variables reset when the file descriptor is invalid or `BUFFER_SIZE` is non-positive?
15. Why did you decide to split the functionality into multiple helper functions?
16. How does your implementation handle very long lines that exceed `BUFFER_SIZE`?

## ✍️ Answers

1. **Handling Files Without a Newline**  
   If the EOF is reached and the file doesn't end with a newline, the function will return whatever is left in the buffer as the last line, even if it doesn't end with a newline.

2. **Handling `read()` Errors**  
   If `read()` returns `-1`, indicating an error, the function will free any allocated memory and return `NULL` to signal the error. This error handling is consistent across the `read_file` function and the main GNL function.

3. **Importance of Static Variables**  
   Static variables in C retain their value across multiple function calls. In GNL, the static variable is crucial as it stores data that hasn't been returned yet. It allows the function to manage data that has been read but not yet processed.

4. **Effect of Small or Large `BUFFER_SIZE`**  
   - **Small `BUFFER_SIZE`**: The function will still work correctly, but it will make many more `read()` calls to gather enough data. This can lead to performance inefficiencies but won’t affect correctness, though excessive calls could potentially cause issues.
   - **Large `BUFFER_SIZE`**: If `BUFFER_SIZE` is very large, the function might read a significant portion of the file in a single `read()` call. This can reduce the number of system calls, but it will use more memory to store the buffer.

5. **Memory Management**  
   Memory is dynamically allocated using `ft_calloc` whenever a new buffer or line is needed. Each time a line is returned by GNL, the buffer is updated by `ft_next`, which creates a new buffer with the remaining data. If an error occurs, all allocated memory is freed, and `NULL` is returned. At EOF or with an invalid file descriptor, memory in the static buffer is also freed.

6. **Handling Multiple File Descriptors**  
   The implementation uses an array of static buffers indexed by the file descriptor (fd). Each time GNL is called with a different fd, it uses the corresponding buffer for that fd, ensuring that the state for each fd is preserved independently.

7. **Avoiding Memory Leaks**  
   Memory is carefully managed, with all allocated memory being freed when an error occurs or when EOF is reached. This ensures that no memory is left allocated unnecessarily.

8. **Buffer Starting with a Newline**  
   If the buffer starts with a newline character, `ft_line` will return a string containing just that newline, as it is considered a valid C line. `ft_next` will then update the buffer and free that newline, allowing the function to continue processing any remaining data.

9. **Why `join` in `ft_free`?**  
   Memory that has been allocated needs to be freed, as a general rule for memory management. The `ft_free` function handles this to prevent memory leaks.

10. **Handling an Empty File**  
    If the file is empty, the first call to GNL will return 0, indicating that EOF has been reached. GNL will immediately return `NULL` since there is no data to return.

11. **Choosing `calloc` over `malloc`**  
    `calloc` is chosen over `malloc` because it initializes the allocated memory to `\0`, ensuring that there is no garbage data. This adds a layer of safety, starting with a known environment of zeros.

12. **Handling Extremely Large Files**  
    More understanding and optimizations might be required to handle very large files efficiently, possibly by adjusting the `BUFFER_SIZE` dynamically or by optimizing memory usage further.

13. **Changing `BUFFER_SIZE` During Runtime**  
    The function might behave unpredictably if `BUFFER_SIZE` is changed between function calls, as the size of the buffer directly impacts how data is read and processed.

14. **Resetting Static Variables**  
    When the file descriptor is invalid or `BUFFER_SIZE` is non-positive, the function cannot perform its tasks. In this case, any allocated memory is freed, and the buffer is reset to avoid any dangling pointers or memory leaks. This is the correct behavior.

15. **Splitting Functionality into Helper Functions**  
    The functionality is split into multiple helper functions to make the code more modular and readable. Each function has a clear responsibility, making the code easier to maintain and debug.

16. **Handling Very Long Lines**  
    The function will keep reading and appending to the buffer until the entire line is read. `ft_line` will then return the entire line, regardless of its length, even if it exceeds `BUFFER_SIZE`.




## 🔗 Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/nikolas-goulios)



## Authors

- [@NikolasGoulios](https://www.github.com/NikolasGoulios)


## Feedback

If you have any feedback, please reach out ngoulios@outlook.com or on Linkedin. 

## 🙏 **Thank you so much! Let's stay connected on GitHub** 🚀👨‍💻✨
```​⬤
