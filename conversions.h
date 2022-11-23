// Função que transforma um número decimal em binário. É necessário passar o número decimal como parâmetro.
int decimalToBinary(int dec)
{
  int bin = 0;

  int i = 1;

  while (dec != 0)
  {
    bin += (dec % 2) * i;

    dec /= 2;

    i *= 10;
  }

  return bin;
}

// Função que inverte um binário. O segundo parâmetro é o binário a ser invertido.
int invertBinary(int binary1, int binary2)
{
  int inverted = 0;
  int end = 0;
  int i = 0;
  int housesNumber = getHousesNumber(binary1);

  while (!end)
  {
    if (binary2 % 10 == 0)
    {
      inverted += pow(10, i);
    }

    binary2 /= 10;

    i++;

    if (binary2 == 0)
    {
      if (inverted == 0)
      {
        inverted = pow(10, housesNumber);
      }

      end = 1;
    }
  }

  return inverted;
}

// Função que transforma binário para decimal. É necessário passar o binário como parâmetro
int binaryToDecimal(int bin)
{
  int dec = 0;
  int i = 0;

  while (bin != 0)
  {
    dec += (bin % 10) * pow(2, i);
    bin /= 10;
    i++;
  }

  return dec;
}
