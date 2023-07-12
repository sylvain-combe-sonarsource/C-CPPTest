#include <stdio.h>

int main() {
    char *a = NULL;
    // ruleid: null-ptr-deref
    putchar(*a);
}

typedef struct Person {
    char *name;
    int age;
} Person;

int main() {
    Person *p = 0;
    // ruleid: null-ptr-deref
    p->age = 12;
}

int main() {
    int a = NULL;
    // ok: null-ptr-deref
    int b = 12 *a;
}

int main() {
    Person *people = NULL;
    // ruleid: null-ptr-deref
    people[12].name = "Denice";
}

int main() {
    const char *a = NULL;
    if(getchar() == 'a') {
        a = "Hello World";
    }

    // todoruleid: null-ptr-deref
    putchar(*a);
}

// This is a partial false-positive. Semgrep
// decides that the lines marked 'todook' are
// null deferences. However, this is kind of 
// fine because if the NULL is removed, the 
// rule works fine 
int main() {
    const char *names[] = {
        "John McClane",
        "Meredith Grey",
        NULL
    };

    // ok: null-ptr-deref
    puts(names[0]);
    // ok: null-ptr-deref
    puts(names[1]);
    // todoruleid: null-ptr-deref
    puts(names[2]);   
}

int main() {
    const char *names[] = {
        "John McClane",
        "Meredith Grey",
        "Serena Williams"
    };

    // ok: null-ptr-deref
    puts(names[0]);
    // ok: null-ptr-deref
    puts(names[1]);
    // ok: null-ptr-deref
    puts(names[2]);   
}

