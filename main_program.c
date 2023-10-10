#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * TODO: see if instead of curl, I can use youtube-dl to grab the audio file in the format that whisper wants it.
 * I can use the "system()" to call the youtube-dl program on my computer. 
 * but then I need to wait() for the system line to finish, and then look for the .wav file in a certain directory
 * and then you use .wav file for my API request to OpenAI.
 * */


// argc is the index of the arguments passed; && argv is an pointer/array of the arguments themselves
int main(void) {
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

  system("echo \"Hello World\"");
  system("ls");
  return EXIT_SUCCESS;
}
/*
  for (int i = 0; i < argc; i++) {
    printf("arg %d - %s\n",i, argv[i]);
  }
  API: http://calapi.inadiutorium.cz/api/v0/en/calendars/general-en/2021/03
  **/

