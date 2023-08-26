# 0x16. C - Simple Shell project

## ALX simple shell collaboration project for ALX S.E May 2023 Cohort-16

## **AUTHORS**

    - Schandorf Osam-Frimpong
    - Nii Odartey E. Lamptey

### _Allowed functions and system calls for project:_

    - access
    - chdir
    - close
    - closedir
    - execve
    - exit
    - __exit
    - fflush
    - fork
    - free
    - getcwd
    - getline
    - getpid
    - isatty
    - kill
    - malloc
    - open
    - opendir
    - perror
    - read
    - readdir
    - signal
    - stat (__xstat)
    - lstat (__lxstat)
    - fstat (__fxstat)
    - strtok
    - wait
    - waitpid
    - wait3
    - wait4
    - write

### TESTING

    1. Shell should work in interactive mode like this:
    	$ ./hsh
    	($) /bin/ls
    	hsh main.c shell.c
    	($)
    	($) exit
    	$

    2. Shell should also work in non-interactive mode like this:
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

### FILES

    - main.c : Main execution path of program.

    - shell.h : Library that contains all the header files, prototypes and built-in functions.

    - hsh : Shell program (executable file).

    - test :

    - interactive__odam_functions.c - Makes the shell run in interactive mode.

    - non_interactive_odam_functions.c - Makes the shell run in non-interactive mode.

    - odam-built_in_functions.c - Functions that implement built-in commands.

    - odam_get_path.c - Gets the full path of a command.

    - odam_implode.c - Implodes array of strings into one string.

    - odam_readlines.c - Reads lines from a file or a stdin and returns a pointer to lines read as a string.

    - odam_str_tokenizer.c - Splits strings into tokens.

    - parse_command_input.c - Separates inputted commands into an array of strings.

    - perform_actions.c - Contains a function to execute entered commands.

#END
