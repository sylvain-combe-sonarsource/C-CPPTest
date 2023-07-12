#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "constants.h"

#define AS_STRING "%99s"
#define BUF_SIZE 100
#define VALID_STRING "Test"

// Standard constant use for format
int main() {
    char *buffer = VALID_STRING;
    // ok: variable-format-printf
    printf("%s", buffer);
    // ok: variable-format-printf
    _tprintf(_T("%s"), &buffer);
}

// Use of propagated constant in format
int main() {
    char *buffer = VALID_STRING;
    char *format = "%s";
    // ok: variable-format-printf
    printf(format, buffer);
    // ok: variable-format-printf
    _tprintf(_T(format), &buffer);
}

// Use of macro in format
// Second case currently detects as false positive
int main() {
    char *buffer = VALID_STRING;
    // ok: variable-format-printf
    printf(AS_STRING, buffer);
    // todook: variable-format-printf
    _tprintf(_T(AS_STRING), &buffer);
}

// Use of macro in format, imported from another file
// Currently detects as false positive
int main() {
    char *buffer = VALID_STRING;
    // todook: variable-format-printf
    printf(IMPORT_AS_STRING, buffer);
    // todook: variable-format-printf
    _tprintf(_T(IMPORT_AS_STRING), &buffer);
}

// Use of constant returned from a function
// Currently detects as false positive
char *getFormat();
int main() {
    char *buffer = VALID_STRING;
    char *format = getFormat();
    // todook: variable-format-printf
    printf(format, buffer);
    // todook: variable-format-printf
    _tprintf(_T(format), &buffer);
}
char *getFormat() {
    return "%s";
}

// User input string as a format (first parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer = VALID_STRING;
    // ruleid: variable-format-printf
    printf(userInput, buffer);
    // ruleid: variable-format-printf
    _tprintf(_T(userInput), buffer);
}

// User input string as a format (second parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer = VALID_STRING;
    // ruleid: variable-format-printf
    fprintf(stdin, userInput, buffer);
    // ruleid: variable-format-printf
    _ftprintf(stdin, T(userInput), buffer);
}

// User input string as a format (thrid parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer;
    _locale_t locale = _create_locale(LC_ALL, "de-CH");
    // ruleid: variable-format-printf
    int ret = snprintf(buffer, 10, userInput, VALID_STRING);
    // ruleid: variable-format-printf
    ret = _sprintf_p_l(buffer, 10, userInput, locale, VALID_STRING);
}