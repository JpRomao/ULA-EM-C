// Função que faz a soma de dois números binários
int binarySum(int binary1, int binary2)
{
  int sum = 0;
  int i = 0;
  int house = 0;
  int end = 0;

  while (!end)
  {
    int bit1 = binary1 % 10;
    int bit2 = binary2 % 10;

    int result = bit1 + bit2 + house;

    if (result > 1)
    {
      house = 1;
    }
    else
    {
      house = 0;
    }

    if (result >= 0 && (result == 1 || result == 3))
    {
      sum += pow(10, i);
    }

    if (binary1 == 0 && binary2 == 0)
    {
      end = 1;
    }

    binary1 /= 10;
    binary2 /= 10;

    i++;
  }

  return sum;
}

// Função que faz complemento de dois do segundo parâmetro
int c2(int binary1, int binary2)
{
  int binary1HousesNumber = 0;

  if (binary1)
  {
    binary1HousesNumber = getHousesNumber(binary1);
  }

  int binary2Inverted = invertBinary(binary2, binary1HousesNumber);

  binary2 = binarySum(binary2Inverted, 1);

  return binary2;
}

// Função que opera a subtração de dois números binários
int binarySub(int binary1, int binary2)
{
  int subtraction;

  binary2 = c2(binary1, binary2);

  subtraction = binarySum(binary1, binary2);

  int housesNumber = getHousesNumber(subtraction);

  subtraction = subtraction - pow(10, housesNumber - 1);

  return subtraction;
}

// Função que opera a divisão de dois números binários
int binaryDivision(int binary1, int binary2)
{
  int quocient = 0;
  int i = 0;
  int housesNumber = getHousesNumber(binary1);
  int end = 0;

  while (!end)
  {
    int dividend = binary1 / pow(10, housesNumber - 1);

    if (dividend >= binary2)
    {
      quocient += pow(10, housesNumber - 1);
      binary1 = binarySub(dividend, binary2);
    }

    if (housesNumber == 1)
    {
      end = 1;
    }

    housesNumber--;
  }

  return quocient;
}

// Função que opera a multiplicação de dois números binários
int binaryMultiplication(int binary1, int binary2)
{
  int multiplication = 0;
  int i = 0;
  int housesNumber = getHousesNumber(binary2);
  int end = 0;

  while (!end)
  {
    int bit = binary2 % 10;

    if (bit == 1)
    {
      multiplication = binarySum(multiplication, binary1 * pow(10, i));
    }

    if (housesNumber == 1)
    {
      end = 1;
    }

    binary2 /= 10;
    housesNumber--;
    i++;
  }

  return multiplication;
}
