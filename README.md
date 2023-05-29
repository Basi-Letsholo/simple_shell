 # **Simple Shell Project**
 A simple UNIX command interpreter.
 
 ## Concepts
 * [Everything you need to know to start coding your own shell](https://intranet.alxswe.com/concepts/64)
 * [Approaching a Project](https://intranet.alxswe.com/concepts/350)
 
 Additional Background concepts needed:
* Basics of programming
* Basics of C
* Basics of thinking like an engineer
* Group work
* and Learning how to learn

## Resources
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* **Everything you need to know to start coding your own shell** concept page

## General Requirements
* Allowed editors: vi, vim, emacs
* All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All files should end with a new line
* The code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* The shell should not have any memory leaks
* No more than 5 functions per file
* All header files should be include guarded
* Use system calls only when needed

## Compilation
The shell is compiled using:
` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh `

## Usage
How the Shell works in interactive mode:  
```bash
$ ./hsh
(Shell$) ls
hsh main.c shell.c
(Shell$) 
(Shell$) exit
$
```

How the Shell works in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
