# Student Task: Complete the File System

You are given the starter implementation of a CLI in-memory file system. Some functions are intentionally left unimplemented in `functionDefinitions.h`.

## What to do
1. Implement all missing functions in `functionDefinitions.h`:
   - `initFolder`
   - `disPlayContents`
   - `createFolder`
   - `createFile`
   - `searchFolder`
   - `getFolAdress`
   - `removeFolder`
2. Do not change `main.c` or `userInput.h` unless you need minor fixes.
3. Ensure the app supports the commands:
   - `ls`, `mkdir`, `touch`, `cd`, `cd ..`, `cd ~`, `rm`, `--help`, `exit`
4. Run and verify:
   ```bash
   cd student-exercise/starter
   gcc -Wall -Wextra -pedantic main.c -o filesystem.exe
   ./filesystem.exe
   ```

## Optional challenge
- Add `cat <filename>` to print file contents.
- Add `rmfile <filename>` to remove single files.
- Add `pwd` to show the current path.
