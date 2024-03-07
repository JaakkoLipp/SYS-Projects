#include "types.h"
#include "user.h"
#include "fcntl.h"


// user program to test new systemcall getreadcount
int main(void) {
    int count;
    char buf[512];

    // Example read operations
    int fd = open("READTEST", O_RDONLY);
    read(fd, buf, sizeof(buf));
    read(fd, buf, sizeof(buf));
    close(fd);

    // Get and print the read count
    count = getreadcount();
    printf(1, "Total read() calls: %d\n", count);

    exit();
}
