#include <sys/fcntl.h>
int main()
{
    int fd;
    fd = open("text.txt", O_RDONLY);
}