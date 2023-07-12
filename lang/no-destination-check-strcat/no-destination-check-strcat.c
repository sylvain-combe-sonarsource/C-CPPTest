#include <string.h>

#define BUF_SIZE 100
#define SMALL_BUF_SIZE 5

// Use of strcat when dest buffer is sufficiently large
// This should actually fail, because there is no pre-check that the current string length of dest plus the current string length of src plus 1 (for the final null character) is as large or larger than the size of the buffer pointed to by src
int main() {
    char str1[BUF_SIZE] = "C programming";
    char str2[BUF_SIZE];
    // ruleid: no-destination-check-strcat
    strcat(str2, str1);
}

// Use of strcat when dest buffer is insufficiently large
int main() {
    char str1[BUF_SIZE] = "C programming";
    char str2[SMALL_BUF_SIZE];
    // ruleid: no-destination-check-strcat
    strcat(str2, str1);
}

// Use of strcat when src may not be null-terminated
int main() {
    char str1 = "C";
    char str2[BUF_SIZE];
    // ruleid: no-destination-check-strcat
    strcat(str2, &str1);
}

// Example from: https://rules.sonarsource.com/c/RSPEC-5814
int f(char *src) {
  char dest[256];
  strcpy(dest, "Result: ");
  // ruleid: no-destination-check-strcat
  strcat(dest, src);
  return doSomethingWith(dest);
}

// Example from: https://rules.sonarsource.com/c/RSPEC-5814
int preCheckDestLenViaSizeofCombinedWithStrlen(char *src) {
  // Syntactic sugar for const char appendToMe[] = {'R','e','s','u','l','t',' ','\0'};
  char appendToMe[] = "Result: ";
  char *dest = malloc(sizeof(appendToMe) + strlen(src));
  strcpy(dest, appendToMe);
  // ok: no-destination-check-strcat
  strcat(dest, src); // Compliant: the buffer size was carefully crafted
  int result = doSomethingWith(dest);
  free(dest);
  return result;
}

// Example from: https://github.com/guardrails-test/guardrails-test-c/blob/ce087e2ece13323511b063666040ae66beebf4d9/lang/NIST/TestSuites/SARDSuites/Asterisk_10.2.0/TestCases/148808-v1.0.0/apps/app_voicemail.c#L4327-#L4379
static void prep_email_sub_vars()
{
  char fromfile[256];  
  if (strlen(fromfile) < sizeof(fromfile) - 5) {
    // ok: no-destination-check-strcat
    strcat(fromfile, ".txt");
  }
}

// Example from: https://github.com/guardrails-test/guardrails-test-c/blob/ce087e2ece13323511b063666040ae66beebf4d9/lang/NIST/TestSuites/SARDSuites/Asterisk_10.2.0/TestCases/148808-v1.0.0/apps/app_voicemail.c#L8036-#L8052
static int vm_play_folder_name_gr(struct ast_channel *chan, char *box)
{
	char *buf;
	buf = alloca(strlen(box) + 2);
	strcpy(buf, box);
  // ok: no-destination-check-strcat
	strcat(buf, "s");
}

// Example from: https://github.com/guardrails-test/guardrails-test-c/blob/ce087e2ece13323511b063666040ae66beebf4d9/lang/NIST/TestSuites/SARDSuites/Asterisk_10.2.0/TestCases/148808-v1.0.0/apps/app_voicemail.c#L10725-#L10780
// Example from: https://github.com/guardrails-test/guardrails-test-c/blob/ce087e2ece13323511b063666040ae66beebf4d9/lang/NIST/TestSuites/SARDSuites/Asterisk_10.2.0/TestCases/148808-v1.0.0/apps/app_voicemail.c#L10725-#L10780
static int append_mailbox(const char *context, const char *box, const char *data)
{
  char *mailbox_full;
  mailbox_full = alloca(strlen(box) + strlen(context) + 1);
  strcpy(mailbox_full, box);
  // ok: no-destination-check-strcat
  strcat(mailbox_full, "@");
  // ok: no-destination-check-strcat
  strcat(mailbox_full, context);
}