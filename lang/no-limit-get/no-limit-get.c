#include <stdio.h>

#define BUF_SIZE 100

// Standard use of gets
int main() {
    char buffer[BUF_SIZE];
    // ruleid: no-limit-get
    gets(buffer);
}