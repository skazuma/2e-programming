#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define KABE '#'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '$'
#define BOMB '*'
#define GRASS '.'
#define MITI ' '
#define KITA 0
#define HIGASHI 1
#define MINAMI 2
#define NISHI 3
#define WARP '?'

char map[20][20]; // マップを保持する二次元配列
int muki=HIGASHI;
int tcount=0;

void make_map(void)
{
	int i, j,r1,r2;
	srand((unsigned)time(NULL));
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
		if(r1==1 || r1==18)
		{
			i--;
			continue;
		}
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
		if(r1==1 || r1==18)
		{
			i--;
			continue;
		}
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
		if(r1==1 || r1==18)
		{
			i--;
			continue;
		}
    if(map[r1][r2]==GRASS)
    {
      map[r1][r2]=BOMB;
    }
    else{
      i--;
    }
  }
	for(i=0;i<2;i++)
	{
		r1=(rand()%18)+1;
    r2=(rand()%18)+1;
		if(r1==1 || r1==18)
		{
			i--;
			continue;
		}
    if(map[r1][r2]==GRASS)
    {
      map[r1][r2]=WARP;
    }
    else{
      i--;
    }
	}
	printf("\n");
}
int seek_x(char s)
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(map[i][j]==s)
			{
				return i;
			}
		}
	}
}
int seek_y(char s)
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(map[i][j]==s)
			{
				return j;
			}
		}
	}
}
void play_game(char command[])
{
	int i,j,x,y;
	x=seek_x(PLAYER);
	y=seek_y(PLAYER);
	for(i=0;i<strlen(command);i++)
	{
		if(command[i]=='F')
		{
			if(muki==KITA)
			{
				if(map[x-1][y]==KABE)
				{
					printf("この方向には進めません。\n");
					break;
				}
				else if(map[x-1][y]==BOMB)
				{
					map[x][y]=MITI;
					map[x-1][y]=BOMB;
					display_map();
					printf("GAME OVER:プレーヤーが爆弾を踏みました。\n");
					exit(0);
				}
				else if(map[x-1][y]==TREASURE)
				{
					tcount++;
				}
				else if(map[x-1][y]==WARP)
				{
					int w1,w2;
					map[x][y]=MITI;
					map[x-1][y]=WARP;
					w1=seek_x(WARP);
					w2=seek_y(WARP);
					map[w1][w2]=PLAYER;
					x=w1;
					y=w2;
					break;
				}
				map[x-1][y]=PLAYER;
				map[x][y]=MITI;
				x--;
			}
			else if(muki==HIGASHI)
			{
				if(map[x][y+1]==KABE)
				{
					printf("この方向には進めません。\n");
					break;
				}
				else if(map[x][y+1]==BOMB)
				{
					map[x][y]=MITI;
					map[x][y+1]=BOMB;
					display_map();
					printf("GAME OVER:プレーヤーが爆弾を踏みました。\n");
					exit(0);
				}
				else if(map[x][y+1]==TREASURE)
				{
					tcount++;
				}
				else if(map[x][y+1]==WARP)
				{
					int w1,w2;
					map[x][y]=MITI;
					map[x][y+1]=MITI;
					w1=seek_x(WARP);
					w2=seek_y(WARP);
					map[w1][w2]=PLAYER;
					x=w1;
					y=w2;
					break;
				}
				map[x][y+1]=PLAYER;
				map[x][y]=MITI;
				y++;
			}
			else if(muki==MINAMI)
			{
				if(map[x+1][y]==KABE)
				{
					printf("この方向には進めません。\n");
					break;
				}
				else if(map[x+1][y]==BOMB)
				{
					map[x][y]=MITI;
					map[x+1][y]=BOMB;
					display_map();
					printf("GAME OVER:プレーヤーが爆弾を踏みました。\n");
					exit(0);
				}
				else if(map[x+1][y]==TREASURE)
				{
					tcount++;
				}
				else if(map[x+1][y]==WARP)
				{
					int w1,w2;
					map[x][y]=MITI;
					map[x+1][y]=MITI;
					w1=seek_x(WARP);
					w2=seek_y(WARP);
					map[w1][w2]=PLAYER;
					x=w1;
					y=w2;
					break;
				}
				map[x+1][y]=PLAYER;
				map[x][y]=MITI;
				x++;
			}
			else if(muki==NISHI)
			{
				if(map[x][y-1]==KABE)
				{
					printf("この方向には進めません。\n");
					break;
				}
				else if(map[x][y-1]==BOMB)
				{
					map[x][y]=MITI;
					map[x][y-1]=BOMB;
					display_map();
					printf("GAME OVER:プレーヤーが爆弾を踏みました。\n");
					exit(0);
				}
				else if(map[x][y-1]==TREASURE)
				{
					tcount++;
				}
				else if(map[x][y-1]==WARP)
				{
					int w1,w2;
					map[x][y]=MITI;
					map[x][y-1]=MITI;
					w1=seek_x(WARP);
					w2=seek_y(WARP);
					map[w1][w2]=PLAYER;
					x=w1;
					y=w2;
					break;
				}
				map[x][y-1]=PLAYER;
				map[x][y]=MITI;
				y--;
			}
		}
		else if(command[i]=='R')
		{
			muki=(muki+1)%4;
		}

		display_map();
	}
}

void display_map()
{
	int i,j;
	printf("\x1b[2J");
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
			else if(map[i][j]==MITI)
			{
				printf("\x1b[40m"); // 背景色の設定
				printf("\x1b[30m"); // 文字色の設定
				printf("%c", map[i][j]);
				printf("\x1b[49m"); // 背景色をデフォルトに戻す
				printf("\x1b[39m"); // 文字色をデフォルトに戻す
			}
			else if(map[i][j]==WARP)
			{
				printf("\x1b[47m"); // 背景色の設定
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

	if(muki==KITA)
	{
		printf("↑\n");
	}
	else if(muki==HIGASHI)
	{
		printf("→\n");
	}
	else if(muki==MINAMI)
	{
		printf("↓\n");
	}
	else if(muki==NISHI)
	{
		printf("←\n");
	}

	printf("\n");
	usleep(500000);
}

int main(int argc, char** argv)
{
	char command[21];
	make_map(); // マップの設定
	display_map();
	map[1][0]=PLAYER;
	for(;;)
	{
		if(muki==KITA)
		{
			printf("北を向いています\n");
		}
		else if(muki==HIGASHI)
		{
			printf("東を向いています\n");
		}
		else if(muki==MINAMI)
		{
			printf("南を向いています\n");
		}
		else if(muki==NISHI)
		{
			printf("西を向いています\n");
		}
		printf("コマンドを入力してください(20文字まで)\n");
		printf("前進：F,右回転(90度)：R\n");
		fgets(command,21,stdin);

		play_game(command);
		if(map[18][19]==PLAYER){
			printf("ゲームクリア！おめでとうございます！！\n");
			if(tcount>0)
			{
				printf("宝箱を%d個見つけました！\n",tcount);
			}
			else
			{
				printf("宝箱を見つけられませんでした。\n");
			}
			break;
		}

	}
	return 0;
}
