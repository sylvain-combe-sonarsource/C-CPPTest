#include <stdio.h>

#define BUF_SIZE 100
#define FORMAT "Example %s"
#define STRING "string"

void standardSprintfUse() { 
  char buf[BUF_SIZE];
  // ruleid: no-buffer-check-sprintf
  sprintf(buf, FORMAT, STRING);
}

void standardSprintfUseWithStringLiteralFormat() { 
  char buf[BUF_SIZE];
  // ruleid: no-buffer-check-sprintf
  sprintf(buf, "Example %s", STRING);
}

void standardSprintfUseWithStaticStringFormatSpecifierButNoInput() { 
  char buf[BUF_SIZE];
  // ruleid: no-buffer-check-sprintf
  sprintf(buf, "%p %p");
}

void standardSprintfUseWithStaticString() { 
  char buf[BUF_SIZE];
  // ok: no-buffer-check-sprintf
  sprintf(buf, "hello");
}

// https://rules.sonarsource.com/c/RSPEC-6069
void preCheckBufLenViaSnprintf() {
  size_t buflen = snprintf(0, 0, "%s", STRING);
  char* buf = malloc(buflen + 1);
  // ok: no-buffer-check-sprintf
  sprintf(buf, "%s", message);
}

// https://github.com/guardrails-test/guardrails-test-c/blob/master/lang/NIST/TestSuites/StandaloneApplications/Gimp_2.8.8/TestCases/150169-v1.0.0/src/app/core/gimpviewable.c#L74-L103
void stonesoup_setup_printf_context() {
  struct stat st = {0};
  char * ss_tc_root = NULL;
  char * dirpath = NULL;
  int size_dirpath = 0;
  char * filepath = NULL;
  int size_filepath = 0;
  int retval = 0;
  ss_tc_root = getenv("SS_TC_ROOT");
  if (ss_tc_root != NULL) {
    size_dirpath = strlen(ss_tc_root) + strlen("testData") + 2;
    dirpath = (char*) malloc (size_dirpath * sizeof(char));
    if (dirpath != NULL) {
      // ok: no-buffer-check-sprintf
      sprintf(dirpath, "%s/%s", ss_tc_root, "testData");
      retval = 0;
      if (stat(dirpath, &st) == -1) {
        retval = mkdir(dirpath, 0700);
      }
      if (retval == 0) {
        size_filepath = strlen(dirpath) + strlen("logfile.txt") + 2;
        filepath = (char*) malloc (size_filepath * sizeof(char));
        if (filepath != NULL) {
          // ok: no-buffer-check-sprintf
          sprintf(filepath, "%s/%s", dirpath, "logfile.txt");
          stonesoup_printf_context = fopen(filepath, "w");
          free(filepath);
        }
      }
      free(dirpath);
    }
  }
}

// https://github.com/guardrails-test/guardrails-test-c/blob/master/lang/NIST/TestSuites/SARDSuites/C_Test_Suite_for_Source_Code_Analyzer_v2_-_Vulnerable/TestCases/149095-v1.0.0/src/sql_select_bad.c#L52
// Also a potential SQLi
int main(int argc, char *argv[]) 
{
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "thisismygoodpassword";
  char *database = "bank";

  if (argc < 2)
  {
    printf("You should give an entry parameter!\n");
    return 0;		
  }

  conn = mysql_init(NULL);

   /* Connect to database */
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return 0;
  }

  /* send SQL query */
  char query[512];
  char *fmtString = "SELECT * FROM users WHERE firstname LIKE '%s'";

  /* No more buffer overflow */
  if ((strlen(argv[1]) + strlen(fmtString)) > 512){
    printf("The entry is too long...\n");
    return 0;		
  }
  // ok: no-buffer-check-sprintf
  sprintf(query,fmtString,argv[1]);
  if (mysql_query(conn, query)) {
	  fprintf(stderr, "%s\n", mysql_error(conn));
    return 0;
  }
  // ...
  return 0;
}
