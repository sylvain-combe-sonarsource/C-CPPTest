#include <stdio.h>
#include <string.h>
#include "constants.h"

#define AS_STRING "%99s"
#define BUF_SIZE 100

// Standard constant use for format
int main() {
    char buffer[BUF_SIZE];
    // ok: variable-format-scanf
    scanf("%99s", &buffer);
    // ok: variable-format-scanf
    _tscanf(_T("%99s"), &buffer);
}

// Use of propagated constant in format
int main() {
    char buffer[BUF_SIZE];
    char *format = "%99s";
    // ok: variable-format-scanf
    scanf(format, &buffer);
    // ok: variable-format-scanf
    _tscanf(_T(format), &buffer);
}

// Use of macro in format
// Second case currently detects as false positive
int main() {
    char buffer[BUF_SIZE];
    // ok: variable-format-scanf
    scanf(AS_STRING, &buffer);
    // todook: variable-format-scanf
    _tscanf(_T(AS_STRING), &buffer); // False positive
}

// Use of macro in format, imported from another file
// Currently detects as false positive
int main() {
    char buffer[BUF_SIZE];
    // todook: variable-format-scanf
    scanf(IMPORT_AS_STRING, &buffer);
    // todook: variable-format-scanf
    _tscanf(_T(IMPORT_AS_STRING), &buffer);
}

// Use of constant returned from a function
// Currently detects as false positive
char *getFormat();
int main() {
    char buffer[BUF_SIZE];
    char *format = getFormat();
    // todook: variable-format-scanf
    scanf(format, &buffer);
    // todook: variable-format-scanf
    _tscanf(_T(format), &buffer);
}
char *getFormat() {
    return "%99s";
}

// User input string as a format (first parameter)
int main() {
    char userInput[BUF_SIZE];
    // ok: variable-format-scanf
    scanf(AS_STRING, &userInput);
    char buffer[BUF_SIZE];
    // ruleid: variable-format-scanf
    scanf(userInput, &buffer);
    // ruleid: variable-format-scanf
    _tscanf(_T(userInput), &buffer);
}

// User input string as a format (second parameter)
int main() {
    char userInput[BUF_SIZE];
    // ok: variable-format-scanf
    scanf(AS_STRING, &userInput);
    char buffer[BUF_SIZE];
    // ruleid: variable-format-scanf
    fscanf(stdin, userInput, &buffer);
    // ruleid: variable-format-scanf
    _ftscanf(stdin, _T(userInput), &buffer);
}

// User input string as a format (third parameter)
int main() {
    char userInput[BUF_SIZE];
    // ok: variable-format-scanf
    scanf(AS_STRING, &userInput);
    char  str1[] = "15 12 14...";
    wchar_t  str2[] = L"15 12 14...";
    char  s1[3];
    wchar_t  s2[3];
    float fp;
    // ruleid: variable-format-scanf
    int ret = _snscanf( str1, 6,  userInput, s1, &fp);
    // ruleid: variable-format-scanf
    ret = _snwscanf( str2, 6,  userInput, s2, &fp);
}