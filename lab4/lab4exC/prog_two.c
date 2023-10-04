/*
 *  File Name: prog_two.c
 *  Assignment: Lab 4 Exercise C
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Oct 4th,2023
 */

#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];  

  int y = EOF;
  
  while (1)
    {
      printf("\n\nEnter an real or press Ctrl-D to quit: ");
      y = read_real(digits, SIZE, &n); 
  
      if(y == 1)
	      printf("\nYour real value is: %lf", n);
      else if(y == EOF){
	      printf("\nGood Bye.\n");
	      break;
      }
      else
	      printf("\n%s is an invalid real number.", digits);
    }  
  return 0;
}