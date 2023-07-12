#include <stdio.h>

struct s {
    int a;
    char c;
};

struct s* bad_code1() {
    struct s a;
    struct s b = a;
    // ruleid: return-address-of-stack-variable
    return &b;
}

int* bad_code2() {
    int a = 1;
    // ruleid: return-address-of-stack-variable
    return &a;
}

int* bad_code3() {
    int a[10];
    // ruleid: return-address-of-stack-variable
    return a;
}

int* bad_code4() {
    int a[10];
    int *b = a;
    // ruleid: return-address-of-stack-variable
    return b;
}

int* bad_code5() {
    static int my_ints[] = {1, 2, 3, 4, 5};
    int arr[5];
    int* a = arr;

    // ruleid: return-address-of-stack-variable
    return a; 
}

int* bad_code6() {
    static int my_ints[] = {1, 2, 3, 4, 5};
    int var = 12;

    // ruleid: return-address-of-stack-variable
    return &var; 
}


int* good_code1() {
    static int my_ints[] = {1, 2, 3, 4, 5};
    int arr[5];
    int* a = arr;

    // ok: return-address-of-stack-variable
    return my_ints; 
}

int* good_code2() {
    static int my_ints[] = {1, 2, 3, 4, 5};

    // ok: return-address-of-stack-variable
    return my_ints; 
}

int* good_code3() {
    static thread_local int my_ints[] = {1, 2, 3, 4, 5};

    // ok: return-address-of-stack-variable
    return my_ints; 
}

int* good_code3() {
    thread_local static int my_ints[] = {1, 2, 3, 4, 5};

    // ok: return-address-of-stack-variable
    return my_ints; 
}