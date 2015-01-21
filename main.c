/*
 * Main entry point of a simple shell program which makes use of process
 * creation functions (fork, execvp, etc).
 *
 * ---* Lab 2 *---
 * Authors: Seth Hilaski, Gagandeep Singh
 * Class: CIS 452 - Operating Systems Concepts
 * Date: 01/17/2015
 *
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "sshell.h"

#define INPUT_SIZE 255
#define MAX_ARGS 10

int main(void)
{
  char input[INPUT_SIZE];
  char * argv[MAX_ARGS];
  int status = 0;
  struct rusage usage;
  struct timeval start, end;
  long s_con, e_con;
  // Display a welcome message for the shell
  print_shell_str();
  printf("Running simple shell: type \"quit\" to exit.\n");

  // Get input from the user until a quit command is issued
  while(1)
  {
    print_shell_str();
    fgets(input, INPUT_SIZE, stdin);

    // Tokenize the input and store in argv
    status = split_input(input, argv, MAX_ARGS);

    if(status >= 1) // Quit the program if quit is indicated
    {
      break;
    }
    else
    {
      // Get the start user time and context switch value for child process(es)
      getrusage(RUSAGE_CHILDREN, &usage);
      start = usage.ru_utime;
      s_con = usage.ru_nivcsw;
      // Execute the command
      exec_cmd(argv);
      // Get the end user time and context switch value for child process(es)
      getrusage(RUSAGE_CHILDREN, &usage);
      end = usage.ru_utime;
      e_con = usage.ru_nivcsw;
      // Print the timing results to the terminal
      printf("User CPU time: %ld.%06lds\n", end.tv_sec - start.tv_sec,
        end.tv_usec - start.tv_usec);
      printf("Involuntary context switches: %ld\n", e_con - s_con);
    }
  }

  return 0;
}
