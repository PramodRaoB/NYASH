# NYASH
NYASH: Not Your Average Shell - A simple shell written in C for Linux systems
---

## Usage:
Run the following commands
1. `make`
2. ./nyash
---

## Features:

### `;` separated commands
- Concatenate multiple commands in a single line by separating them with a semicolon `;`

### `&` terminated background processes
- Run processes in background by appending an ampersand `&` at the end of the command
- **NYASH** displays the pid of such processes before executing them in the background
- **Child handling**: **NYASH** displays the exit status of such processes when they are terminated, suspended or continued.

### File redirection
- `< [FILE]` can be used to redirect input from the specified `[FILE]` for a command
- `> [FILE]` and `>> [FILE]` can be used to redirect the output to the specified `[FILE]` for a command. `>` Overwrites the output file and `>>` appends to the output file
- Both input and output redirections can be used on a single command
  - Example: `cat < input.txt > output.txt`

### Piping commands
- `<command> | <command>` can be used to pipe the output of the command on the left side of the pipe to the command on the right side of the pipe
- Two or more commands can be chained together by piping
- Piping can be used alongside input and output redirections
  - Example: `cat < in.txt | wc -l > lines.txt`
- Note that in case of a conflict between taking input/output from the pipe or through a redirection, the redirection is given higher preference
  - Example: `cat in.txt | sort > out.txt | wc -l`
  - This shall output 0 since the `sort` command redirects the output to `out.txt` and not the pipe

### Signals
- `<ctrl>C` or `SIGINT` does not kill **NYASH**
- `<ctrl>Z` or `SIGTSTP` does not kill **NYASH**
- `<ctrl>D` or an `EOF` safely logs out of the shell (functionally equivalent to the `exit` command)

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

### history - Displays a specific number of most recently used commands

Usage: `history [0 <= N <= 20]`

- If no argument is passed, displays the 10 most recently used commands
- This data is stored in `/home/user/.nyash_history` to allow for persistent usage, deleting which may lead to **loss of all history data**

### jobs - Displays the processes spawned by the shell which are either running or suspended along with a unique job number

Usage: `jobs [OPTIONS]...`

- Here `[OPTIONS]` can take any of the following values
  - Specifying no options prints all spawned processes which are either running or stopped
  - `-r` prints only the currently running spawned processes
  - `-s` prints only the currently stopped spawned processes
- **NYASH** assigns a positive integer which is greater than all the current job numbers in use as the job number to a spawned process. Hence, multiple processes may have the same job number overall (due to the counter resetting by emptying the job list), but they will not share the same job number simultaneously. This feature was implemented in this way to avoid large job numbers through usage of the shell for a longer period.

### sig - Sends a specified signal to the process with the specified job number

Usage: `sig [job_number] [signal_number]`

- The `job_number` can be any of the job numbers listed using the command `jobs`
- The `signal_number` can be any of the signals listed under the manpage signal(7)

### fg - Brings the running or stopped process specified by the job number to the foreground

Usage: `fg [job_number]`

- The `job_number` can be any of the job numbers listed using the command `jobs`


### bg - Sends the running or stopped process specified by the job number to the background

Usage: `bg [job_number]`

- The `job_number` can be any of the job numbers listed using the command `jobs`

### replay - Executes a given command and repeats execution every specified interval of time for a total of a specified time period

Usage: `replay [OPTIONS]...`

- Here, the `[OPTIONS]` must include exactly one instance of the following
  - `-i` (or alternatively, `--interval` and `-interval`) Followed by a positive integer `[N > 0]` which indicates the frequency of the replay command
  - `-p` (or alternatively, `--period` and `-period`) Followed by a positive integer `[N > 0]` which indicates the total time period for which the replay command can be executed
  - `-c` (or alternatively, `--command` and `-command`) Followed by the command to be replayed `<command>`
- An additional feature of the `replay` command is that, it can be suspended via sending a signal `<ctrl>Z` like any other system command and it is displayed as a job via the `jobs` command

### baywatch - Prints a specific system data periodically for a specified period

Usage: `baywatch [OPTION] <command>`

- Here, the `[OPTION]` must include exactly one instance of
  - `-n` followed by a positive integer `[N > 0]` which specifies the interval for printing the command output
- Here, the `<command>` must be exactly one among the following
  - `interrupt` which prints the number of times the CPU(s) has been interrupted by the keyboard-controller
  - `newborn` which prints the PID of the most recently created process on the system
  - `dirty` which prints the size of the part of the memory which is dirty
- A keypress of `q` stops execution of the command 

### exit: Exits out of the shell

---

## File organization

- The `main` function is contained in `main.c`
- A few global variables used across multiple files are declared as `extern` variables in the file `globals.h`
- The `commands` folder contains the .c and .h files related to the commands implemented in **NYASH** named appropriately as the command which they are used in implementing
- The `processor` folder contains the .c and .h files related to the child signal handling, prompt feature and execution of system commands in foreground and background
- The `utils` folder contains the .c and .h files implementing various data-structres and functionality that are used throughout various other files
  - Including a vector of strings, linked list of strings, linked list of `job` struct and a tokenizer

---

| Hope you have an above *average* experience! :D