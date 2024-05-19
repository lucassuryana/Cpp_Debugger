#include <stdio.h>

// Recursive function to cause stack overflow
void recursive_function(int count, int *main_local) {
    int local_variable;
    printf("%d: stack bottom : %p, current : %p\n", count, main_local, &local_variable);
    recursive_function(count + 1, main_local);
}

int main() {
    int main_local_variable;
    printf("Starting stack overflow demonstration...\n");
    recursive_function(1, &main_local_variable);
    return 0;
}
