#include <syslog.h>
#include <string.h>
#include "constants.h"

#define AS_STRING "%99s"
#define PRIO 1
#define BUF_SIZE 100
#define LOGS "Logs"

// Standard constant use for format
int main() {
    // ok: variable-format-syslog
    syslog(PRIO, "%99s", LOGS);
}

// Use of propagated constant in format
int main() {
    char *format = "%99s";
    // ok: variable-format-syslog
    syslog(PRIO, format, LOGS);
}

// Use of macro in format
int main() {
    // ok: variable-format-syslog
    syslog(PRIO, AS_STRING, LOGS);
}

// Use of macro in format, imported from another file
// Currently detects as false positive
int main() {
    // todook: variable-format-syslog
    syslog(PRIO, IMPORT_AS_STRING, LOGS);
}

// Use of constant returned from a function
// Currently detects as false positive
char *getFormat();
int main() {
    char *format = getFormat();
    // todook: variable-format-syslog
    syslog(PRIO, format, LOGS);
}
char *getFormat() {
    return "%99s";
}

// User input string as a format
int main() {
    char userInput[BUF_SIZE];
    scanf(AS_STRING, &userInput);
    // ruleid: variable-format-syslog
    syslog(PRIO, userInput, LOGS);
}