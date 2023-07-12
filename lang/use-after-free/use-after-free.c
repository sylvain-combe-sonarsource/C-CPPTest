#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 10
#define VALID_INDEX 5
#define VALID_VALUE 2

// Pointer is reinitialised to another value before use
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    buffer = malloc(BUF_SIZE * sizeof(int));
    // ok: use-after-free
    buffer[VALID_INDEX] = NULL;
}

// Pointer is reinitialised to another value before use, in another function
void reinitialise(int *);
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    reinitialise(&buffer);
    // ok: use-after-free
    buffer[VALID_INDEX] = NULL;
}
void reinitialise(int **buffer) {
    *buffer = malloc(BUF_SIZE * sizeof(int));
}

// Standard use after free
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    // ruleid: use-after-free
    buffer[VALID_INDEX] = NULL;
}

// Buffer is used after free, in another function
// Currently a false negative
void storeInt(int *);
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    // ruleid: use-after-free
    storeInt(buffer);
}
void storeInt(int *buffer) {
    buffer[VALID_INDEX] = VALID_VALUE;
}

// Free is enclosed in a condition
// Currently a false negative
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    if (true) {
        free(buffer);
    }
    // todoruleid: use-after-free
    buffer[VALID_INDEX] = NULL;
}

// Variable set to the same pointer is used after free
// Currently a false negative
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    int *clone = buffer;
    // todoruleid: use-after-free
    clone[VALID_INDEX] = NULL;
}
