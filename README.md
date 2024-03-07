Käyttöjärjestelmät ja systeemiohjelmointi

Project 1: Warmup to C and Unix programming

Project 2: Unix Utilities Page

Project 4: Modified XV6 kernel with new syscall getreadcount:
Returns how many times that the read() system call has been called by user processes since the time that the kernel was booted.

Adding getreadcount System Call to xv6

Summary

The getreadcount system call was added to the xv6 kernel to count the number of times the read() system call has been invoked. The implementation involved modifying kernel files to increment a global counter and register a new system call that returns this counter's value.

Steps

    Global Counter: Added a global variable uint readcount to count read() invocations.
    Modifying Read: Incremented readcount within the read() function.
    System Call Implementation: Created the sys_getreadcount function returning the value of readcount.
    System Call Registration: Defined a unique identifier for the new system call and updated the syscall table in syscall.c.
    User Space Accessibility: Declared getreadcount() in user.h for user programs.

Testing

A test program testreadcount was created to perform several read() operations and then call getreadcount(), printing the result to verify the correct increment of the counter.

The project can be compiled with make clean and then make / make qemu-nox (requires qemu)
Tested to be functioning correctly in qemu/ubuntu host.

Screenshots
