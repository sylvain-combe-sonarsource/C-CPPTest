#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 10

// Pointer is reinitialised to another value before second free
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    buffer = NULL;
    // ok: double-free
    free(buffer);
}

// Pointer is reinitialised to another value before second free inside a function
void reinitialise(int *);
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    reinitialise(buffer);
    // ok: double-free
    free(buffer);
}
void reinitialise(int *buffer) {
    buffer = NULL;
}

// Pointer is freed again in an unreachable conditional block
// Currently detects as false positive
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    if (false) {
        // todook: double-free
        free(buffer);
    }
}

// Most basic example of double free
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    // ruleid: double-free
    free(buffer);
}

// Freeing the same memory space, but pointed to by different variables
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    int *clone = buffer;
    free(buffer);
    // ruleid: double-free
    free(clone);
}

// Pointer is passed into a function which does not reinitialise nor change its value
void dummyFunction(int *);
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    dummyFunction(buffer);
    // todoruleid: double-free
    free(buffer);
}
void dummyFunction(int *buffer) {
    return;
}

// Pointer is freed again in another function
// Currently false negative
void tryFree(int *);
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    tryFree(buffer);
}
void tryFree(int *buffer) {
    // todoruleid: double-free
    free(buffer);
}

// Pointer is freed again in a conditional block
int main() {
    int *buffer = malloc(BUF_SIZE * sizeof(int));
    free(buffer);
    if (true) {
        // ruleid: double-free
        free(buffer);
    }
}