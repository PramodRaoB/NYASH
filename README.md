# NYASH
NYASH: Not Your Average Shell - A simple shell written in C for Linux systems
---

## Usage:

---

## Features:

### `;` separated commands
- Concatenate multiple commands in a single line by separating them with a semicolon `;`

### `&` terminated background processes
- Run processes in background by appending an ampersand `&` at the end of the command
- **NYASH** displays the pid of such processes before executing them in the background
- **Child handling**: **NYASH** displays the exit status of such processes when they are terminated, suspended or continued.

### Prompt
- **NYASH** comes with a sleek prompt displaying the username and the hostname of the machine, and the current working directory

### cd - Change current working directory

Usage: `cd [DIR]`
- Here, `[DIR]` can take on any of the following values
  - `~` Changes directory to the home directory i.e. the directory from which the shell was executed
  - `-` Changes directory to the previous working directory
  - Any relative path from the home directory is valid
  - Any absolute path (i.e. from the root directory) is valid
  - Passing no arguments changes directory to the home directory
  - Note that these are valid as long as the user has the appropriate permissions for the directory passed

### pwd - Display current working directory

Usage: `pwd`

### echo - Echoes the passed string into terminal

Usage: `echo [STRING]`

- Note that quotes and escape characters are not handled. The passed string is tokenized based on whitespace before echoing.

### ls - List files/folders and their information from one or multiple directories

Usage: `ls [OPTIONS]... [FILE]...`

- Here, `[OPTIONS]` can take any of the following values
  - Specifying no options prints only the names of the non-hidden files/folders from the FILEs passed
  - `-a` (all) Behaves similar to no options but additionally prints hidden files
  - `-l` (long format) Prints additional info such as permissions, date modified, size for each non-hidden file
  - Note that multiple options can be used at the same time
- The `[FILE]` argument can be
  - A relative or absolute path to a file or a folder
  - Note that the user is required to have appropriate permissions to read the details/contents of the file/folder

### pinfo - Prints the process related info of a shell program

Usage: `pinfo [pid]`

- Displays the pid, process status, memory consumption and executable path for the specified process
- Passing a valid `pid` displays the info related to the specified `pid`
- If no arguments are passed, instead displays the info related to the current **NYASH** process

### repeat - Repeats a command specified number of times

Usage: `repeat [N >= 0] [command]`

### history: Displays a specific number of most recently used commands

Usage: `history [0 <= N <= 20]`

- If no argument is passed, displays the 10 most recently usde commands
- This data is stored in `/home/user/.nyash_history` to allow for persistent usage, deleting which may lead to **loss of all history data**

### exit: Exits out of the shell

---

## File organization

- The `main` function is contained in `main.c`
- A few global variables used across multiple files are declared as `extern` variables in the file `globals.h`
- The `commands` folder contains the .c and .h files related to the commands implemented in **NYASH** named appropriately as the command which the are used to implement
- The `processor` folder contains the .c and .h files related to the child signal handling, prompt feature and execution of system commands in foreground and background
- The `utils` folder contains the .c and .h files implementing various data-structres and functionality that are used throughout various other files
  - Including a vector of strings, linked list of strings, linked list of `job` struct and a tokenizer

---

| Hope you have an above *average* experience! :D