#simple_shell

A shell application built in the C programming course 0x17. The application was written entirely in vim and compiled on Ubuntu 20.04 LTS using gcc 4.8.4 given the use of Vagrant.

### Installation
```
git clone git@github.com:bashthat/simple_shell.git
compiled gcc -Wall -Werror -Wextra -pedantic -g *.c -o hsh
./hsh
===============
This will execute the program and give you the prompt to work from hense the "$".

Current builtin commands:

1. help - prints list of avaialable builtin commands.
2. cd - changes the current working directory.
3. env - prints out the current shell varriables.
4. exit - exits the shell.

Example of a command: env => this command will list the environment and essential shell information.

This is a list of functions available to use to achieve the over all goal of writing a shell.

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

============================

thanks for reading the README!
