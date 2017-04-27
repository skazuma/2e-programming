#include <stdio.h>


int main(int argc, char **argv)
{
  double pi=3.1415;
  double a=pi*2.0;
  printf("小数点以下1桁まで表示\n");
  printf("円周:%0.1fr\n",a);
  printf("円の面積:%0.1fr^2\n",pi);
  printf("小数点以下2桁まで表示\n");
  printf("円周:%0.2fr\n",a);
  printf("円の面積:%0.2fr^2\n",pi);
  printf("小数点以下3桁まで表示\n");
  printf("円周:%0.3fr\n",a);
  printf("円の面積:%0.3fr^2\n",pi);

  return 0;
}
