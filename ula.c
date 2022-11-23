/*
  João Pedro da Silva Romão - 04722-037
  Maria Eduarda de Souza Garcia - 04722-069
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"
#include "conversions.h"
#include "operations.h"

#define NUMBER_INPUTS 2

int main()
{
  int decimal[NUMBER_INPUTS];

  printf("Enter two numbers in hexadecimal (base 16)\n");

  for (int i = 0; i < NUMBER_INPUTS; i++)
  {
    printf("Enter the %d number: ", i + 1);
    fflush(stdin);
    scanf("%x", &decimal[i]);
    getchar();
  }

  int binary[NUMBER_INPUTS];

  for (int i = 0; i < NUMBER_INPUTS; i++)
  {
    binary[i] = decimalToBinary(decimal[i]);

    printf("The binary equivalent of %x is %d\n", decimal[i], binary[i]);
  }

  int sum = binarySum(binary[0], binary[1]);
  printf("Sum: %x\n", binaryToDecimal(sum));

  int sub = binarySub(binary[0], binary[1]);
  printf("Subtraction: %x\n", binaryToDecimal(sub));

  int div = binaryDivision(binary[0], binary[1]);
  printf("Division: %x\n", binaryToDecimal(div));

  int multi = binaryMultiplication(binary[0], binary[1]);
  printf("Multiplication: %x\n", binaryToDecimal(multi));

  return 0;
}
