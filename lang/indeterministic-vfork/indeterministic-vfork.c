#include <unistd.h>

// Use of vfork with immediate exec
int main() {
    char *args[] = {"./filename", NULL};
    // ok: indeterministic-vfork
    vfork();
    execvp(args[0], args);
}

// Use of vfork with intermediate methods before exec
int main() {
    // ruleid: indeterministic-vfork
    vfork();
    char *args[] = {"./filename", NULL};
    execvp(args[0], args);
}