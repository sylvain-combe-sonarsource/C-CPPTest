#include <curl/curl.h>

CURL *curl;
curl_global_init(CURL_GLOBAL_DEFAULT);

curl = curl_easy_init();
curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/");
// ruleid: insecure-certificate-verification-in-SSL-TLS
curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); 

// ok: insecure-certificate-verification-in-SSL-TLS
curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); 

//Perform the request
curl_easy_perform(curl);