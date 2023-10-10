# Staging Area for libcurl implementation

```c

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
```
