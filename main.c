#include <sys/fcntl.h>
int main()
{
    int fd;
    fd = open("text1.txt", O_RDONLY);
}