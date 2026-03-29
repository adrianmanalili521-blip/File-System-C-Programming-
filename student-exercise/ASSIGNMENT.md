# File System CLI Exercise

## Objectives
- Implement an in-memory tree-based file system in C.
- Practice pointers, dynamic memory, and data structure traversal.
- Add and remove folders/files, and navigate with shell-like commands.

## Provided starter directories
- `student-exercise/starter` (incomplete functions for students)
- `student-exercise/solution` (complete reference implementation)

### Starter files (to complete)
- `main.c`
- `structs.h`
- `functionPrototypes.h`
- `functionDefinitions.h` (function stubs, TODO)
- `userInput.h`
- `displayCommands.h`
- `myColors.h`
- `README.md` (instructions)

## Required features
1. `mkdir <name>` - create a new directory inside the current folder.
2. `touch <name>` - create a file with text content in the current folder.
3. `ls` - list folders and files in the current folder.
4. `cd <name>` - enter a child folder (or `cd ..` to go up and `cd ~` to go to root).
5. `rm <name>` - delete a child folder (and its subtree).
6. `exit` - quit and clean up all allocated memory.

## Grading
- Correct behavior for all commands (45 pts)
- No memory leaks (25 pts)
- Robust input handling (15 pts)
- Code organization, comments, naming (15 pts)

## Run
```bash
# in student-exercise folder
gcc -Wall -Wextra -pedantic main.c -o filesystem.exe
./filesystem.exe
```
