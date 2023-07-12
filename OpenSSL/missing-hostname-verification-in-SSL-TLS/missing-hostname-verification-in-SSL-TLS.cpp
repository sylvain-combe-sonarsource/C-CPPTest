#include <openssl/ssl.h>

int main() {
    SSL_CTX *ctx = get_ctx();
    SSL *ssl = SSL_new(ctx);

    // By default hostname validation is disabled
    // `SSL_set1_host` is not called
    SSL_set_verify(ssl, SSL_VERIFY_PEER, NULL);

    // ruleid: missing-hostname-verification-in-SSL-TLS
    SSL_connect(ssl); // Noncompliant

    SSL *ssl2 = SSL_new(ctx);

    SSL_set1_host(ssl2, HOST_NAME);
    SSL_set_verify(ssl2, SSL_VERIFY_PEER, NULL);

    // ok: missing-hostname-verification-in-SSL-TLS
    SSL_connect(ssl2);
}
