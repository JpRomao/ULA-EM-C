// Função que retorna quantas "casas" (111 = 3 casa | 4121 = 4 casas | 4 = 1 casa) há em um número inteiro
int getHousesNumber(int number)
{
  int housesNumber = 0;

  while (number > 0)
  {
    number /= 10;
    housesNumber++;
  }

  return housesNumber;
}
