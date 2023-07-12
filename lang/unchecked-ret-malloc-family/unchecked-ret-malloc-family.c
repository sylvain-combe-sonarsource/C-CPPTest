#include <stdlib.h>

int main() {
    // todook: unchecked-ret-malloc-family
    int *a = (int*) malloc(sizeof(int) * 10), *b = (int*)malloc(sizeof(int));
    if (a) {
        printf("ok");
    }

    // ruleid: unchecked-ret-malloc-family
    int *c = (int*) malloc(sizeof(int) * 10);

    // ruleid: unchecked-ret-malloc-family
    int *c1 = (int*) pvalloc(sizeof(int) * 10);

    // ok: unchecked-ret-malloc-family
    int *d = memalign(sizeof(int) * 10);
    if (d != NULL && true) {
        printf("ok");
    }

    void *e, *f;
    // ruleid: unchecked-ret-malloc-family
    int ret1 = posix_memalign(&e, 4, 16);
    // ok: unchecked-ret-malloc-family
    int ret2 = posix_memalign(&f, 4, 16);
    if (ret2) {
        printf("ok");
    }
    return 0;
}