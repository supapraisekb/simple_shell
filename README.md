SIMPLE SHELL PROJECT..

##INTRODUCTION

This is a group project that integrates all the concepts which have been studied so far in the program in order to
build a shell program which takes an input from the user and delivers it to the Operating sysytem for execution.
Shell programs are commonly used in Unix-based operating systems, but can also be used in other systems.
In the 1960s, Ken Thompson and Dnnis Ritchie developed the first Unix OS which has undergone refinement
and development over the years and has given rise to the development of other Unix-like operating systems.

 The first shell program called the Thompson shell or sh was developed by Ken Thompson in 1971.
 It was a basic shell and did not handle scripting but the feat was a precursor to the development on better and
 improved shells such as the Bash which is in wide use today.

 A shell can  either be in teractive or non-interactive. An interactive shell allows arguments to be
 entered at the prompt and then executed. The Interactive shell mode is invoked using the -i flag.
 A non-interactive shell on the other hand does not allow user interaction.
 It is used to execute shell scripts or to run commands in the background.
 Non-interactive shells do not display a prompt or read commands from standard input.

##EGSHELL
This Project involves the Creation of  a simple shell program  which we have decided to call egshell that works wit
the command line interface (CLI) and allows the users of the shell program to enter commands.
It has the properties of both an interactive and non interactive shell. This shell program has the capability to
handle the executables found in the environmental variable PATH, with or without their full paths.
Some examples of which include ```ls``` (```/bin/ls```), ```pwd```, ```echo```,```mv```, ```cp```.

### Operational Environment:
* Language: C
* OS: Ubuntu 22.04.2 LTS
* Compiler: gcc  11.3.0
* Guidelines and Checks: all checks must meet and comply with the standards set by [Betty](https://github.com/holbertonschool/Betty/wiki)

