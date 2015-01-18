/*
 * Main entry point of a simple shell program which makes use of process
 * creation functions (fork, execvp, etc).
 *
 * Authors: Seth Hilaski, Gagandeep Singh
 * Date: 01/17/2015
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "sshell.h"

int main(int argc, char* argv[])
{
  quit_shell = false;

  //Display a welcome message for the shell.
  print_shell_str();
  printf("Now running the simple shell\n");

  // Get input from the user until a quit command is issued.
  while(!quit_shell)
  {
    print_shell_str();
    fgets(user_input, sizeof(user_input), stdin);
    fputs(user_input, stdout);
  }

  return 0;
}
