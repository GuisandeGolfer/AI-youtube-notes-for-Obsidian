#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char formattedString[200];

  const char *youtube_video = argv[1];

  printf("cli arg was: %s\n", youtube_video);

  sprintf(formattedString, "youtube-dl --verbose --extract-audio --audio-format mp3 %s\n", youtube_video);

  printf("downloading youtube audio file");

  system("ls");
  printf("\n");
  system(formattedString);

  return EXIT_SUCCESS;

}
