/*
 * Implementation of functions for the simple shell program.
 *
 * ---* Lab 2 *---
 * Authors: Seth Hilaski, Gagandeep Singh
 * Class: CIS 452 - Operating Systems Concepts
 * Date: 01/17/2015
 *
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "sshell.h"

/*
 * Prints the shell prompt string to the terminal
 */
void print_shell_str(void)
{
  printf("%s", SHELL_STR);
}

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
int split_input(char *input, char** argv, int argv_size)
{
  // Get first argument from input
  char* t_arg = strtok(input, " \n");

  // Return negative number if there was no input
  if(t_arg == NULL) return -1;
  // Return positive number (true) if quit command was issued;
  if(!strcmp(t_arg, "quit")) return 1;

  // Tokenize each parameter into char* array argv
  for(int i = 0; i < argv_size; i++)
  {
    // Fill argv with arguments until none are left or one element position left
    if(t_arg != NULL && i != argv_size - 1)
    {
      argv[i] = t_arg;
      t_arg = strtok(NULL, " \n");
    }
    else    // Null terminate the array and exit the loop
    {
      argv[i] = '\0';
      break;
    }
  }

  return 0;
}

/*
 * Executes the command with specified arguments stored in the argv array. The
 * function makes use of fork() to make a child process for the command.
 *
 * @ param argv: null-terminated, tokenized string array storing a command
 *               and its arguments, if any.
 */
int exec_cmd(char** argv)
{
  pid_t pid;
  int status;

  // Check if error occured during fork
  if((pid = fork()) < 0)
  {
    perror("The fork failed");
    exit(1);
  }
  else if(pid == 0)       // Fork child code
  {
    // Execute the passed command and display error if it occured
    if(execvp(*argv, argv) < 0)
    {
      printf("Error executing command: %s\n", strerror(errno));
      exit(1);
    }
  }
  else      // Parent waits for the child to finish
  {
    pid = wait(&status);
  }

  return 0;
}
