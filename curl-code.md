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

```c
// Libcurl implementation for "Content-Type: multipart/form-data"
// which is needed for OpenAI whisper post request.
 curl_mime *multipart = curl_mime_init(handle);
 curl_mimepart *part = curl_mime_addpart(multipart);
 curl_mime_name(part, "name");
 curl_mime_data(part, "daniel", CURL_ZERO_TERMINATED);
 part = curl_mime_addpart(multipart);
 curl_mime_name(part, "project");
 curl_mime_data(part, "curl", CURL_ZERO_TERMINATED);
 part = curl_mime_addpart(multipart);
 curl_mime_name(part, "logotype-image");
 curl_mime_filedata(part, "curl.png");

 /* Set the form info */
 curl_easy_setopt(handle, CURLOPT_MIMEPOST, multipart);

 curl_easy_perform(handle); /* post away! */

 curl_mime_free(multipart); /* free the post data */
```
