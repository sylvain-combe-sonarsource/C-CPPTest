#include <openssl/ssl.h>

static int verify_callback(int preverify_ok, X509_STORE_CTX *ctx) {
    return 1; 
} // This callback always validate the certificate

static int verify_callback2(int preverify_ok, X509_STORE_CTX *ctx);

int main() {
    // Bad code
    const SSL_METHOD *method = TLS_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    // ruleid: insecure-certificate-verification-in-SSL-TLS
    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL); // Noncompliant SSL_VERIFY_NONE means no automatic certificate verification
    SSL *ssl = SSL_new(ctx);
    SSL_connect(ssl);

    // Bad code 2
    const SSL_METHOD *method2 = TLS_method();
    SSL_CTX *ctx2 = SSL_CTX_new(method);
    // ruleid: insecure-certificate-verification-in-SSL-TLS
    SSL_CTX_set_verify(ctx2, CURLOPT_SSL_VERIFYPEER, verify_callback); // Noncompliant; the verify callback result overrides OpenSSL built-in verification enabled by CURLOPT_SSL_VERIFYPEER option.

    // todoruleid: insecure-certificate-verification-in-SSL-TLS
    SSL_CTX_set_verify(ctx2, CURLOPT_SSL_VERIFYPEER, verify_callback2);
    SSL *ssl2 = SSL_new(ctx2);
    SSL_connect(ssl2);

    // Good code 
    const SSL_METHOD *method3 = TLS_method();
    SSL_CTX *ctx3 = SSL_CTX_new(method);

    SSL_CTX_set_verify(ctx3, SSL_VERIFY_PEER, NULL); // Compliant; CURLOPT_SSL_VERIFYPEER enable OpenSSL's built-in verification of the peer certificate.
    SSL *ssl3 = SSL_new(ctx3);
    SSL_connect(ssl3);
}

static int verify_callback2(int preverify_ok, X509_STORE_CTX *ctx) {
    return 1; 
}
