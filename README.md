# pipex_ll


The "pipex" project at 42 École (or other 42 campuses) typically involves creating a simplified version of \
the shell command pipe in Unix-based operating systems. The goal is to develop a program that takes two commands \
as arguments and executes them in such a way that the output of the first command becomes the input of the second \
command, emulating the behavior of a shell pipeline.

Here's an explanation of the key components and functions in the "pipex" project:

Function Signature:
The main function might have a signature similar to the following:
int main(int argc, char *argv[],char **envp[]);

Command Execution:
The program needs to execute two commands provided as arguments. The standard approach is to use the fork system \
call to create a child process for each command.

Pipes:
The child processes need to communicate using a pipe. The pipe system call is used to create an inter-process \
communication channel, with one end connected to the standard output of the first command and the other end connected \
to the standard input of the second command.

Redirection:
The standard input and output of the child processes should be redirected to the appropriate ends of the pipe. \
This involves using the dup2 system call.

Command Execution and Error Handling:
The child processes execute their respective commands using the execve system call.
Proper error handling should be implemented, and any errors should be reported.

Parent Process:
The parent process needs to wait for the child processes to finish using the waitpid system call.
Ensure proper cleanup and resource management.

Example Command Line:
The program might be invoked from the command line like this:
./pipex file1 cmd1 cmd2 file2

This means that the content of file1 is passed through cmd1, and the output is then passed through cmd2, with \
the final result being written to file2.

Input/Output Redirection:
The program needs to handle input and output file redirection. For example, in the above command line, file1 serves as the input file, and file2 is the output file.
