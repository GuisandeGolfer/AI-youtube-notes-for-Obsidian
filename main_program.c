#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// argc is the index of the arguments passed; && argv is an pointer/array of the arguments themselves
int main(int argc, char *argv[]) {

  char formattedString[100];
  /**
  CURL *curl = curl_easy_init(); // pointer to the curl struct; servers as a handle for curl request

  if (!curl) {
    fprintf(stderr, "init failed\n");
    return EXIT_FAILURE;
  }

  // set options
  curl_easy_setopt(curl, CURLOPT_URL, "https://www.youtube.com/watch?v=aAh1cwy7ICM");
  // perform action based off set options
  CURLcode result = curl_easy_perform(curl);

  if (result != CURLE_OK) {
   fprintf(stderr, "download error: %s\n", curl_easy_strerror(result));
  }

  curl_easy_cleanup(curl);
  */

  char *youtube_video = argv[1];

  sprintf(formattedString, "youtube-dl --verbose --extract-audio --audio-format mp3 %s\n", youtube_video);

  printf("trying to download audio file");

  system(formattedString);

  return EXIT_SUCCESS;
}
/*
  for (int i = 0; i < argc; i++) {
    printf("arg %d - %s\n",i, argv[i]);
  }
  API: http://calapi.inadiutorium.cz/api/v0/en/calendars/general-en/2021/03
  **/

