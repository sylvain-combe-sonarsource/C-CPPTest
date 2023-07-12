#define BUF_SIZE 100

int main() {
	int a = 12;
	int b = 16;

	// todoruleid: pointer-subtraction
	int size = &b - &a;
}

int main() {
	char buf1[BUF_SIZE];
	char *p = buf1 + 1;

	// ok: pointer-subtraction
	int size = p - buf1;
}

int mystrlen(const char *str) {
	
	const char *end = str;
	for(; *end; end++) {}

	// todook: pointer-subtraction
	return end - str;
}

// Standard pointer subtraction
int main() {
    char buffer1[BUF_SIZE];
    char buffer2[BUF_SIZE];
    // ruleid: pointer-subtraction
    int sizeOfBuffer1 = buffer2 - buffer1;
}

void dummyFn();

// Standard pointer subtraction but buffers not initialised one after another
// Somehow semgrep does not allow for "..." between the 2 initialisations, not sure why
int main() {
    char buffer1[BUF_SIZE];
    dummyFn();
    char buffer2[BUF_SIZE];
    // ruleid: pointer-subtraction
    int sizeOfBuffer1 = buffer2 - buffer1;
}

void dummyFn() {
    return;
}

void pointerSub(char *, char*);

// Standard pointer subtraction but buffers initialised in another stack frame
// Would be best if semgrep can auto detect datatype, but that's not the case
int main() {
    char buffer1[BUF_SIZE];
    char buffer2[BUF_SIZE];
    pointerSub(buffer1, buffer2);
}

void pointerSub(char *buffer1, char *buffer2) {
    // ruleid: pointer-subtraction
    int sizeOfBuffer1 = buffer2 - buffer1;
}
