#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n2=0, n1=1, n0, n;

  printf("Qual o valor de n?: ");
  scanf ("%d", &n);
  printf("%d %d ", n2, n1);
  for(int i=3; i<=n; i++)
  {
    n0 = n1 + n2;
    printf("%d ", n0);
    n2 = n1;
    n1 = n0;
  }
  printf("\n");
  return 0;
}
