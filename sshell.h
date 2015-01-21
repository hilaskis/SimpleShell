/*
 * Header file for a simple shell program containing function definitions.
 *
 * ---* Lab 2 *---
 * Authors: Seth Hilaski, Gagandeep Singh
 * Class: CIS 452 - Operating Systems Concepts
 * Date: 01/17/2015
 *
 */

#ifndef SSHELL_H
#define SSHELL_H

  // String used as the shell prompt string.
  #define SHELL_STR "$ "

  /*
  * Prints the shell prompt string to the terminal
  */
  void print_shell_str(void);

  /*
  * Splits the passed input into tokenized strings using spaces and newline
  * characters as delimiters. The tokenized strings are stored in the passed
  * character array argv, which is null terminated.
  *
  * @param input: string of command arguments.
  * @param argv : string array storing tokenized form of input string
  * @param argv_size: size of the argv array
  * return      : -1 if input is empty, 1 if quit command issued, 0 otherwise.
  */
  int split_input(char *input, char** argv, int argv_size);

  /*
  * Executes the command with specified arguments stored in the argv array. The
  * function makes use of fork() to make a child process for the command.
  *
  * @ param argv: null-terminated, tokenized string array storing a command
  *               and its arguments, if any.
  */
  int exec_cmd(char**);

#endif
