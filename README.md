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
- [x] learn how libcurl works with C
- [x] Realize that I probably need to run a "youtube-dl" process in my program to generate .wav file.
- [x] Learn about "system()" functional call
- [ ] run youtube-dl with my program based off inputs inside `argv[]`.
- [ ] create a method that will download "youtube-dl" on a user's system; if it's not found.

  - [ ] or just implement the same functionality with C, if not present on the user's system.

- [ ] learn how to send the .wav file with OpenAI API token to Whisper and recieve the text output
- [ ] send Whisper output and chat prompt to GPT-4 endpoint, and recieve output
- [ ] save output to a file inside a specific directory inside my iCloud location for Obsidian.
