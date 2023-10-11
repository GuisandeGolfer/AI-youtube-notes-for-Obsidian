# Introduction to AI-youtube-notes-for-Obsidian

## TLDR;

> This project was inspired by my workflow for taking notes on youtube videos.
>
> 1. embed youtube link into Obsidian
> 2. create an H1 heading labled "Notes"
> 3. watch the video over time and take notes / summarize and italicize.
>    I am going to be doing this same process but creating an obsidian MD template, and using Whisper + GPT-4 to
>    write my notes for me, and populate the new note automatically to my Obsidian Vault.

## Current Progress

- [x] Create Makefile
- [x] learn how libcurl works with C.
- [x] Realize that I probably need to run a "youtube-dl" process in my program to generate .wav file.
- [x] Realize that I could have probably down this faster with Python3.
- [x] Learn about "system()" functional call.
- [x] run youtube-dl with my program based off inputs inside `argv[]` and generate an mp3
- [x] learn how to send the .mp3 file with OpenAI API token to Whisper and recieve the text output.
- [ ] figure out how to set && load environment variables in C.
- [ ] need to finish adding the remaining forms to the API Request: 1. mode=whisper-1, 2. response_format=text
- [ ] send Whisper output and chat prompt to GPT-4 endpoint, and recieve output
- [ ] save output to a file inside a specific directory inside my iCloud location for Obsidian.

### Optimizations

---

- [ ] create a method that will download "youtube-dl" on a user's system; if it's not found.
- [ ] or just implement the same functionality with C, if not present on the user's system.
- [ ] make a do/while loop or something that can account for "HTTP: 403" errors or etc. until a successful connection.
- [ ] split the main() function up into separate functions or even files.
