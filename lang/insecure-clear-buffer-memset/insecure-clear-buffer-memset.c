void badcode(char *password, size_t bufferSize) {
  char token[256];
  init(token, password);
  // ruleid: insecure-clear-buffer-memset
  memset(password, ' ', strlen(password));
  free(password);
  // ruleid: insecure-clear-buffer-memset
  memset(token, ' ', strlen(localBuffer));
  free(token);
}

void okcode(char *password, size_t bufferSize) {
  char token[256];
  init(token, password);
  // ok: insecure-clear-buffer-memset
  memset_s(password, bufferSize, ' ', strlen(password));
  // ok: insecure-clear-buffer-memset
  memset_s(token, sizeof(token), ' ', strlen(localBuffer));
  doSth(password, token);
  free(password);
  free(token);
}