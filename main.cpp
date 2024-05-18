#include <stdio.h>

int main()
{
    char str1[]= "UDACITY";
    printf("%s",str1);

    return 0;
}

// Steps to debug
// 1. Compile the code, add -g to indicate that we want to debug
// 2. Run gdb ./a.out to start debug
// 3. Select line to evaluate using break [no. of line]
// 4. Run
// 5. Step to go to the next line of code
// 6. Print variable str1
// 7. Print memory
// 8. What we print is the word of U D A C I T Y
// 9. If we change 7 to 8, the last byte value is 000000000 because UDACITY only consists of 7 words
// 10. Print in hexadecimal