#include <string.h>

int buffer_to_buffer() {
    char src[] = "This is a test";
    char dest[10];

    if(sizeof(src) <= sizeof(dest)) {
    }

    // todoruleid: no-destination-check-strcpy
    strcpy(dest, src);
}

int safe_strcpy(char* dest, const char* src) {
    if(strlen(dest) >= strlen(src)) {
        // ok: no-destination-check-strcpy
        strcpy(dest, src);
    }
}

int malloc_first() {
    const char *src = "This is a source";
    char *dest = malloc(strlen(src) + 1);

    // ok: no-destination-check-strcpy
    strcpy(dest, src);
}

void unsafe(const char *src) {
    char *dest = malloc(5 * sizeof(char));

    // ruleid: no-destination-check-strcpy
    strcpy(dest, src);
}

void ok1(const char *src) {
    char *dest = malloc(strlen(src) + 1);

    // ok: no-destination-check-strcpy
    strcpy(dest, src);
}

void ok2(const char *src) {
    char *dest = malloc(100);

	if(strlen(src) < 100) {
		// todook: no-destination-check-strcpy
		strcpy(dest, src);
	}

}
