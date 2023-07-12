#include <stdio.h>
#include <string.h>
#include "constants.h"

#define AS_STRING "%99s"
#define BUF_SIZE 100
#define VALID_STRING "Test"

// Standard constant use for format
int main() {
    char *buffer = VALID_STRING;
    // ok: variable-format-err
    warn("%s", buffer);
    // ok: variable-format-err
    vwarnx(_T("%s"), buffer);
}

// Use of propagated constant in format
int main() {
    char *buffer = VALID_STRING;
    char *format = "%s";
    // ok: variable-format-err
    warnx(format, buffer);
    // ok: variable-format-err
    vwarn(_T(format), buffer);
}

// Use of macro in format
// Second case currently detects as false positive
int main() {
    char *buffer = VALID_STRING;
    // ok: variable-format-err
    warn(AS_STRING, buffer);
    // todook: variable-format-err
    warn(_T(AS_STRING), buffer);
}

// Use of macro in format, imported from another file
// Currently detects as false positive
int main() {
    char *buffer = VALID_STRING;
    // todook: variable-format-err
    warn(IMPORT_AS_STRING, buffer);
    // todook: variable-format-err
    warn(_T(IMPORT_AS_STRING), buffer);
}

// Use of constant returned from a function
// Currently detects as false positive
char *getFormat();
int main() {
    char *buffer = VALID_STRING;
    char *format = getFormat();
    // todook: variable-format-err
    warn(format, buffer);
    // todook: variable-format-err
    warn(_T(format), buffer);
}
char *getFormat() {
    return "%s";
}

// User input string as a format (first parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer = VALID_STRING;
    // ruleid: variable-format-err
    warn(userInput, buffer);
    // ruleid: variable-format-err
    warn(_T(userInput), buffer);
}

// User input string as a format (second parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer = VALID_STRING;
    // ruleid: variable-format-err
    err(stdin, userInput, buffer);
    // ruleid: variable-format-err
    vwarnc(stdin, T(userInput), buffer);
}

// User input string as a format (third parameter)
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    char *buffer = VALID_STRING;
    // ruleid: variable-format-err
    errc(1, 1, userInput, buffer);
    // ruleid: variable-format-err
    verrc(1, 1, userInput, buffer);
}
