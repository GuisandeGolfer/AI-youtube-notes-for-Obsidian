#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char formattedString[200];

  const char *video_link_list = argv[1];

  printf("cli arg was: %s\n", video_link_list);

  sprintf(formattedString, "youtube-dl --verbose --extract-audio --audio-format mp3 %s\n", video_link_list);

  printf("downloading youtube audio file");

  system(formattedString);

  printf("\n");

  char output[256];

  // popen == pipe open
  // fopen == file open
  // pclose == pipe close

  // FILE* file = popen("ls", "r"); // Open a pipe to execute the command and read its output
  // if (file == NULL) {
  //     fprintf(stderr, "Failed to open pipe\n");
  //     return 1;
  // }
  //
  // // Read the command output into the output array
  // size_t bytesRead = fread(output, 1, sizeof(output) - 1, file); 
  // output[bytesRead] = '\0'; // Null-terminate the string
  //   
  // pclose(file); // Close the pipe
  //   
  // printf("Output of command:\n%s\n", output);
  //
  // return EXIT_SUCCESS;
  //
}


    
    
