BRIEF EXPLANATION ON SHELL
The shell is like a program that receives command inputs from the user’s keyboard and sends them to a machine to be executed by the kernel. It also checks to see if the user’s command inputs are correct.
A shell accomplishes three major tasks.
Initialize: In this stage, a typical shell will read as well as execute its set of configuration files. These alter the shell’s behavior.
Interpret: The shell then reads commands from “stdin” and executes them.
Terminate: After the execution of its commands, the shell performs any of the shutdown commands, frees any memory, and terminates.

In this project, we try to create some custom functions to work around the shell.

More to Know..

1. A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. 
Actually, every process comes with an environment. When a new process is created, it inherits a copy of its parent’s environment. 

2. Parsing : Parsing is the breaking up of commands into individual words and strings



