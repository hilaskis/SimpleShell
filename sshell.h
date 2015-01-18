/*
* Header file for a simple shell program containing function definitions.
*
* Authors: Seth Hilaski, Gagandeep Singh
* Date: 01/17/2015
*
*
*/

#ifndef SSHELL_H
#define SSHELL_H

  #include <stdbool.h>

  #define SHELL_STR "$ "  // String used as the shell prompt string.
  bool quit_shell;        // Flag used to indicate flag termination.
  char user_input[1000];      // Array used to store user input.

  // Used to print the shell prompt string to the beginning of each line.
  void print_shell_str(void);

#endif
