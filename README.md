# Introduction to AI-youtube-notes-for-Obsidian

## TLDR;

> This project was inspired by my workflow for taking notes on youtube videos.
>
> 1. embed youtube link into [Obsidian](https://obsidian.md/)
> 2. create an H1 heading labled "Notes"
> 3. watch the video over time and take notes / summarize and italicize.

- I am going to be doing this same process but _outsourcing_ this process to [Whisper.cpp](https://github.com/ggerganov/whisper.cpp) for transcribing,
- and sending that transcription over to GPT-4 via RESTful API in C.
- I am aware I could do this very easily with **Python** but I want to learn more about C, after finishing this course:

> [C Programming Full Course for free](https://youtu.be/87SH2Cn0s9A?si=8dMqWGbog66M1ITM)
> from **Bro Code**

## Current Progress

- [x] Create Makefile
- [x] Finish Watching C programming course, and learn about pointers.
- [x] implement libcurl in a C program.
- [x] learn what libcurl is actually doing.
- [x] Realize that I could have probably down this faster with Python3.
- [x] Download youtube mp3 file with C so I can format for [Whisper.cpp](https://github.com/ggerganov/whisper.cpp).
- [x] Learn about "system()" functional call.
- [x] run youtube-dl with my program based off inputs inside `argv[]` and generate an mp3.
- [x] Create a script that can print the lastest mp3 file in the current directory.
- [ ] create a function to use ffmpeg with latest mp3 file to format to _.wav_.
- [ ] create a function to run whisper.cpp with .wav file and save it in the current directory.
- [ ] figure out how to set && load environment variables in C.
- [ ] send Whisper output and chat prompt to GPT-4 API endpoint, and recieve output.
- [ ] save output to a file inside my iCloud location for Obsidian.
- [ ] print a message saying what the file is named and print it's location inside Obsidian.

### Optimizations

---

- [ ] create a method that will download "youtube-dl" on a user's system; if it's not found.
- [ ] make a do/while loop or something that can account for "HTTP: 403" errors or etc. and wait until a successful connection.
- [ ] split the main() function up into separate functions and then files if it gets too long.
