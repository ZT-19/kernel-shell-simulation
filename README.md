# Operating System Kernel and Shell Simulator

A command-line program written in C that simulates an OS kernel and shell along with paging and CPU scheduling.

### Overview
Once the program is executed from a Bash command-line shell, it will display a simulated shell that accepts the following commands from the user:

```
help				            Displays all available commands

quit				            Exits the shell or the script with "Bye!"

clearmem			            Clears the shell memory

set VAR STRING			            Assigns STRING to variable VAR in shell memory

print VAR			            Displays the value assigned to variable VAR

run SCRIPT.TXT			            Executes the file SCRIPT.TXT

exec S1.TXT S2.TXT S3.TXT	            Executes up to three files concurrently
```

The user can enter a command into the program's shell, and it will display the output.

### Running text files
The program can run text files inside its working directory by entering the name of the file with the 'run' or 'exec' command. The program's working directory where it can open files is the directory where the program was executed from the Bash shell, which is not necessarily the directory where the program is located. Sample text files that can be executed by the program are available in the *tests* directory of this repository.

It is possible to execute a text file without the program's 'run' or 'exec' command by redirecting the output of the file to the program. If the name of the program is *mykernel* and the name of the text file is *script.txt*, then you can redirect the output of the file to the program with this command: `./mykernel < script.txt`. The program will start, execute the file line by line until redirection is finished, and then reopen its standard input to allow the user to enter commands.

### How files are executed using paging and CPU scheduling

If a file is executed from the program's shell with the 'run' command, the program will simply execute it line by line until it reaches the end of the file without using paging or CPU scheduling. If one or more files are executed with the 'exec' command, the program will simulate paging and CPU scheduling to execute the files concurrently. 

## How to compile and run the program

### Requirements

- A Linux or macOS operating system is recommended. The program may not run correctly on Windows.
- A C compiler using the C11 / gnu11 standard, or similar
    - For Linux, you can use *gcc* from the GNU Project
    - For macOS, you can use the default compiler *Clang* from the LLVM Project (with alias gcc) or *gcc* from the GNU Project
    - For Windows, you can use *gcc* from MinGW
- A Bash command-line shell
    - For Linux and macOS, you can use the *Terminal*
    - For Windows, you can use *Git Bash*

### Downloading this repository

To compile the program, you need a local copy of this repository on your computer. In the directory where you would like this repository to be located, clone this repository with `git clone https://github.com/ZT-19/kernel-shell-simulation.git`, or alternatively, download and extract the ZIP archive.

### <ins>Compiling and running the program with GNU Make</ins>

#### Directory structure

- The *`src`* directory contains the C source files with *.c* and *.h* extensions.

- The *`tests`* directory contains text files that can be executed by the program. This is the working directory of the program.

- The *`obj`* directory is made by the Makefile to store the object files with the *.o* extension compiled by gcc. This directory is not tracked by git.

- The *`bin`* directory is made by the Makefile to store the target binary program named *mykernel* compiled by gcc. This directory is not tracked by git.

#### Make commands

The Makefile defines the following commands. Open the root directory of this repository in a Bash shell to execute these commands.

###### `make`
This will compile the program if any changes have occurred to the source or object files. It will create the target program *mykernel* in the *bin* directory.

###### `make run`
This will run the program *mykernel* from the *bin* directory and set its working directory to the *tests* directory. If the program was not already compiled, it will compile it before running it.

###### `make clean`
This will remove all files from the *obj* and *bin* directories.
