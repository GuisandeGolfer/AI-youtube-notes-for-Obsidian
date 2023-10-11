#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// argc is the index of the arguments passed; && argv is an pointer/array of the arguments themselves
int main(int argc, char *argv[]) {

  const char openAI[] = "https://api.openai.com/v1/audio/transcriptions";

  CURL *curl = curl_easy_init(); // pointer to the curl struct; servers as a handle for curl request
  
  if (!curl) {
    fprintf(stderr, "init failed\n");
    return EXIT_FAILURE;
  }

  curl_easy_setopt(curl, CURLOPT_URL, openAI);

  struct curl_httppost *formpost = NULL, *lastptr = NULL;

  const char *file_path = "./The right way to define a C function with no arguments-VsRs0H4hXEE.mp3";

  FILE *file = fopen(file_path, "rb"); // Open the file in binary mode for reading
  
  if (file) {
      // File exists and can be opened
      fclose(file); // Close the file
      // Now you can add it to your curl_formadd
      curl_formadd(&formpost, &lastptr,
                   CURLFORM_COPYNAME, "file",
                   CURLFORM_FILE, file_path,
                   CURLFORM_CONTENTTYPE, "audio/mpeg",
                   CURLFORM_END);
  } else {
      // File does not exist or could not be opened
      fprintf(stderr, "Failed to open file: %s\n", file_path);
  }

  curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Content-Type: multipart/form-data");

  // set API token here
  const char *api_token = "API_TOKEN";
  char auth_header[100];
  snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_token);
  headers = curl_slist_append(headers, auth_header);

  /* set custom headers */
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
 
  // perform action based off set options
  CURLcode result = curl_easy_perform(curl);

  if (result != CURLE_OK) {
   fprintf(stderr, "download error: %s\n", curl_easy_strerror(result));
  } else {

    printf("API results: %i\n", result);

  }

  curl_easy_cleanup(curl);
  curl_formfree(formpost);
  curl_slist_free_all(headers);

  return EXIT_SUCCESS;

}
