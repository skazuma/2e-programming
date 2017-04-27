#include <stdio.h>
#include <stdint.h>


int main(int argc, char **argv)
{
  printf("signed char型:%zuバイト\n",sizeof(signed char));
  printf("int型:%zuバイト\n",sizeof(int));
  printf("short型:%zuバイト\n",sizeof(short));
  printf("long型:%zuバイト\n",sizeof(long));
  printf("long long型:%zuバイト\n",sizeof(long long));
  printf("_Bool型:%zuバイト\n",sizeof(_Bool));
  printf("unsigned char型:%zuバイト\n",sizeof(unsigned char));
  printf("unsigned int型:%zuバイト\n",sizeof(unsigned int));
  printf("unsigned short型:%zuバイト\n",sizeof(unsigned short));
  printf("unsigned long型:%zuバイト\n",sizeof(unsigned long));
  printf("unsigned long long型:%zuバイト\n",sizeof(unsigned long long));
  printf("char型:%zuバイト\n",sizeof(char));
  printf("intmax_t型:%zuバイト\n",sizeof(intmax_t));
  printf("uintmax_t型:%zuバイト\n",sizeof(uintmax_t));
  printf("intptr_t型:%zuバイト\n",sizeof(intptr_t));
  printf("uintptr_t型:%zuバイト\n",sizeof(uintptr_t));
  printf("float型:%zuバイト\n",sizeof(float));
  printf("double型:%zuバイト\n",sizeof(double));
  printf("long double型:%zuバイト\n",sizeof(long double));
  /*
  下記の型の場合は、自分の環境ではコンパイルできないようです。
  printf("intN_t型:%zuバイト\n",sizeof(intN_t));
  printf("uintN_t型:%zuバイト\n",sizeof(uintN_t));
  printf("int_leastN_t型:%zuバイト\n",sizeof(int_leastN_t));
  printf("uint_leastN_t型:%zuバイト\n",sizeof(uint_leastN_t));
  printf("int_fastN_t型:%zuバイト\n",sizeof(int_fastN_t));
  printf("uint_fastN_t型:%zuバイト\n",sizeof(uint_fastN_t));
  */

  return 0;
}
