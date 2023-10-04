/* read_int.c
 * ENSF 337 Lab 4 Exercise  E
 *
 */

#include "read_input.h"
#include <math.h>

// COMPLETE
int read_real(char* digits,int n, double* num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+') 
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}


//COMPLETE
int is_valid_double(const char* digits)
{
  int valid = 1;
  int i;
  int decimal_count = 0;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
        if(digits[i] == '.'){
            decimal_count += 1;
            i++;
            continue;
        }
        if(digits[i] < '0' ||  digits[i] > '9')
            valid = 0;
        i++;
    }
    if(decimal_count > 1){
        valid = 0;
    }
  return valid;
}

//COMPLETE
double convert_to_double(const char* digits)
{
  double sum = 0;
  int i = 0;
  int decimal_check = 1;
  double n = 1;
  while(digits[i] != '\0') {
    if(digits[i] == '.'){
        decimal_check = 0;
        i++;
        continue;
    }
    if(decimal_check){
        sum = 10 * sum + (digits[i] - '0');
        i++;  
    }
    else{
        sum += ((digits[i] - '0')*pow(10,-n));
        n++;
        i++;
    }
  }
  return sum;
}