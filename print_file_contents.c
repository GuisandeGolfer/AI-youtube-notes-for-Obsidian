#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  char output[256];

  // popen == pipe open
  // fopen == file open
  // pclose == pipe close

  FILE* file = popen("ls", "r"); // Open a pipe to execute the command and read its output
  if (file == NULL) {
      fprintf(stderr, "Failed to open pipe\n");
      return 1;
  }

  // Read the command output into the output array
  size_t bytesRead = fread(output, 1, sizeof(output) - 1, file); 
  output[bytesRead] = '\0'; // Null-terminate the string
    
  pclose(file); // Close the pipe
    
  printf("Output of command:\n%s\n", output);

  return EXIT_SUCCESS;

}

