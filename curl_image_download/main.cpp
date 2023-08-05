#include <stdio.h>
#include <curl/curl.h>
using namespace std;

int main(int argc, char *argv[]) {
    CURL *easy = curl_easy_init();
    FILE *file;
    char url1[58] = "https://setare.com/files/fa/news/1399/4/15/369369_458.jpg";
    
    file = fopen("image.jpg", "w");
    curl_easy_setopt(easy, CURLOPT_URL, url1);
    curl_easy_setopt(easy, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(easy, CURLOPT_WRITEDATA, file);
    curl_easy_perform(easy);
    curl_easy_cleanup(easy);
    fclose(file);
    return 0;
}