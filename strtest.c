#include <stdio.h>
#include <string.h> // 文字列を扱うために必要


int main(int argc, char **argv)
{
  char s[30],t[30];
  int a,b;


  // 代入
  strcpy(s, "zou");
  strcpy(t, "dazou");

  //　そのまま表示
  printf("s=%s\n",s);
  printf("t=%s\n",t);

  //　文字列の長さ
  a=strlen(s);
  printf("sの長さ=%d\n",a);

  // 比較
  b=strcmp(s,t);
  printf("strcmpの結果=%d\n",b);

  // 結合
  strcat(s,t); // s+t→s
  printf("s=%s\n",s);
  a=strlen(s);
  printf("sの長さ=%d\n",a);

  return 0;

}
