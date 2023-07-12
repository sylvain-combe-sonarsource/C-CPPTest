#include <openssl/ssl.h>

/*************** bad code ***************/
const SSL_METHOD *method = TLS_method(); // Noncompliant;  legacy version TLSv1 and TLSv1.1 are enabled
SSL_CTX *ctx = SSL_CTX_new(method);

// ruleid: weak-SSL-TLS-protocol
SSL *ssl = SSL_new(ctx);

// ...

SSL_connect(ssl);

/*************** good code ***************/
const SSL_METHOD *method2 = TLS_method();

SSL_CTX *ctx2 = SSL_CTX_new(method2);
SSL_CTX_set_min_proto_version(ctx2, TLS1_3_VERSION); // Compliant; enables TLSv1.2 / TLSv1.3 version only

// ok: weak-SSL-TLS-protocol
SSL *ssl2 = SSL_new(ctx2);

// ...

SSL_connect(ssl2);