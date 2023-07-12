#include <curl/curl.h>

/***************** bad code 1 *****************/
CURL *curl;
curl_global_init(CURL_GLOBAL_DEFAULT);

// CURL_SSLVERSION_DEFAULT is the default option for CURLOPT_SSLVERSION
// It means legacy version TLSv1 and TLSv1.1 are enabled
curl = curl_easy_init(); // Noncompliant
curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");

// Perform the request
// ruleid: weak-SSL-TLS-protocol
curl_easy_perform(curl);

/***************** bad code 2 *****************/
CURL *curl2;
curl_global_init(CURL_GLOBAL_DEFAULT);

curl2 = curl_easy_init();
curl_easy_setopt(curl2, CURLOPT_URL, "https://example.com/");

curl_easy_setopt(curl2, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1); // Noncompliant;  legacy version TLSv1 and TLSv1.1 are enabled

//Perform the request
// ruleid: weak-SSL-TLS-protocol
curl_easy_perform(curl2);

/***************** good code *****************/
CURL *curl3;
curl_global_init(CURL_GLOBAL_DEFAULT);

curl3 = curl_easy_init();
curl_easy_setopt(curl3, CURLOPT_URL, "https://example.com/");

curl_easy_setopt(curl3, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2); // Compliant; enables TLSv1.2 / TLSv1.3 version only

// Perform the request
// ok: weak-SSL-TLS-protocol
curl_easy_perform(curl3);