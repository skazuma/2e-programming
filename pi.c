#include <stdio.h>


int main(int argc, char **argv)
{
	float pi = 3.1415;
	float r,c,s;

	printf("円の半径を入力してください（小数点以下を含めて入力）:");
	scanf("%f",&r);
	c=2.0*pi*r;
	s=pi*r*r;


	printf("小数点以下１桁を出力\n");
	printf("円周:%0.1f\n",c);
	printf("面積:%0.1f\n\n",s);
	printf("小数点以下2桁を出力\n");
	printf("円周:%0.2f\n",c);
	printf("面積:%0.2f\n\n",s);
	printf("小数点以下3桁を出力\n");
	printf("円周:%0.3f\n",c);
	printf("面積:%0.3f\n",s);


	return 0;
}
