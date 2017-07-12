#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define BOMB '*'
#define GRASS '.'
#define KITA '0'
#define HIGASHI '1'
#define MINAMI '2'
#define NISHI '3'

char map[20][20]; // マップを保持する二次元配列
int muki;

void make_map(void)
{
	int i, j,r1,r2;
  srand(18);

	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if(i == 1 && j == 0)
				map[i][j] = START; // スタートの設置
			else if(i == 18 && j == 19)
				map[i][j] = GOAL; // ゴールの設置
			else if(i == 0 || i == 19)
				map[i][j] = KABE;
			else if(j == 0 || j == 19)
				map[i][j] = KABE;
			else
				map[i][j] = GRASS;
		}
	}

  for(i=0;i<3;i++)
  {
    r1=(rand()%18)+1;
    r2=(rand()%18)+1;
    if(map[r1][r2]==GRASS)
    {
      map[r1][r2]=TREASURE;

    }
    else{
      i--;
    }
  }
  for(i=0;i<10;i++)
  {
    r1=(rand()%18)+1;
    r2=(rand()%18)+1;
    if(map[r1][r2]==GRASS)
    {
      map[r1][r2]=KABE;
    }
    else{
      i--;
    }
  }
  for(i=0;i<5;i++)
  {
    r1=(rand()%18)+1;
    r2=(rand()%18)+1;
    if(map[r1][r2]==GRASS)
    {
      map[r1][r2]=BOMB;
    }
    else{
      i--;
    }
  }


  for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
      if(map[i][j]==START)
      {
        printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す

      }
      else if(map[i][j]==GOAL)
      {
        printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
      else if(map[i][j]==TREASURE)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[33m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
      else if(map[i][j]==KABE)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[30m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
			else if(map[i][j]==BOMB)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
			else if(map[i][j]==PLAYER)
			{
				printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[34m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
			}
      else
      {
        printf("\x1b[42m"); // 背景色の設定
  			printf("\x1b[32m"); // 文字色の設定
  			printf("%c", map[i][j]);
  			printf("\x1b[49m"); // 背景色をデフォルトに戻す
  			printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
		}
		printf("\n");
	}

	printf("\n");
}

void play_game(char command[])
{
	int i;
	for(i=0;i<strlen(command);i++)
	{
		if(command[i]=='F')
		{
			if(muki==KITA)
			{

			}
		}
	}

}

void display_map()
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(map[i][j]==START)
      {
        printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す

      }
      else if(map[i][j]==GOAL)
      {
        printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
      else if(map[i][j]==TREASURE)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[33m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
      else if(map[i][j]==KABE)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[30m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
			else if(map[i][j]==BOMB)
      {
        printf("\x1b[47m"); // 背景色の設定
        printf("\x1b[31m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
			else if(map[i][j]==PLAYER)
			{
				printf("\x1b[40m"); // 背景色の設定
        printf("\x1b[34m"); // 文字色の設定
        printf("%c", map[i][j]);
        printf("\x1b[49m"); // 背景色をデフォルトに戻す
        printf("\x1b[39m"); // 文字色をデフォルトに戻す
			}
      else
      {
        printf("\x1b[42m"); // 背景色の設定
  			printf("\x1b[32m"); // 文字色の設定
  			printf("%c", map[i][j]);
  			printf("\x1b[49m"); // 背景色をデフォルトに戻す
  			printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	char command[20];
	make_map(); // マップの設定
	map[1][0]=PLAYER;
	for(;;)
	{
		printf("コマンドを入力してください\n");
		fgets(command,sizeof(command),stdin);
		play_game(command);
		if(map[18][19]==PLAYER){
			printf("ゲームクリア！おめでとうございます！！\n");
			break;
		}

	}
	return 0;
}
