# Stack Overflow

## main.cpp
The video below shows the behavior of the stack when a function is called and a local varibles are allocated.

## overflow.cpp
The video below shows a program that allocates so much stack memory that it leads to a stack overflow. This happens because the program utilizes a non-stop recursive function. For each iteration, a new function is called, and the address of a local variable is printed along with the address of a local variable from the main function's initialization. At the end of the video, we can see that the stack size limit of the computer is 8 megabytes.

![Alt text](stack_overflow.gif)
