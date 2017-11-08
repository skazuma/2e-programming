//構造体を使ったソースコード
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct status{
  char name[20];
  int hp;
  int atk;
  int def;
};

int damage(struct status,struct status);
void kougeki(struct status,struct status,int);
int sute(FILE *);


int main(int argc,char **argv)
{
  //srand(time(NULL));
  srand(1);
  struct status player[2];
  struct status *p=player;
  struct status enemy[2];
  struct status *e=enemy;
  FILE *f1,*f2;
  int t1,t2,t3,t4,command,dmg;

  //player1のステータス設定
  f1=fopen(argv[1],"r");
  if(f1==NULL)
  {
    printf("開くファイルを二つ渡してください。\n");
    exit(-1);
  }

  t1=sute(f1);
  (*p).hp=t1/10;

  t1=sute(f1);
  (*p).atk=t1/20;

  t1=sute(f1);
  (*p).def=t1/20;

  //player2のステータス設定
  t2=sute(f1);
  (*(p+1)).hp=t2/10;

  t2=sute(f1);
  (*(p+1)).atk=t2/20;

  t2=sute(f1);
  (*(p+1)).def=t2/20;

  fclose(f1);

  //enemy1のステータス設定
  strcpy((*e).name,"スライムくん");

  f2=fopen(argv[2],"r");
  if(f2==NULL)
  {
    printf("開くファイルをもう一つ渡してください。\n");
    exit(-1);
  }

  t3=sute(f2);
  (*e).hp=t3/10;

  t3=sute(f2);
  (*e).atk=t3/20;

  t3=sute(f2);
  (*e).def=t3/20;

  //enemy2のステータス設定
  strcpy((*(e+1)).name,"ドラゲナイ");

  t4=sute(f2);
  (*(e+1)).hp=t4/10;

  t4=sute(f2);
  (*(e+1)).atk=t4/20;

  t4=sute(f2);
  (*(e+1)).def=t4/20;
  fclose(f2);

  printf("ゲームスタート\n");
  sleep(1);
  printf("一人目の味方の名前を設定してください。\n");
  fgets((*p).name,sizeof((*p).name),stdin);
  strtok((*p).name,"\n\0");
  if(strcmp((*p).name,"承太郎")==0)
  {
    (*p).hp=999;
    (*p).atk=300;
    (*p).def=300;
    strcpy((*e).name,"DIO");
    (*e).hp=999;
    (*e).atk=300;
    (*e).def=300;
  }
  printf("二人目の味方の名前を設定してください。\n");
  fgets((*(p+1)).name,sizeof((*(p+1)).name),stdin);
  strtok((*(p+1)).name,"\n\0");
  printf("%s,%sが現れた！\n",(*e).name,(*(e+1)).name);
  sleep(2);
  while(((*p).hp>0 || (*(p+1)).hp>0) && ((*e).hp>0 || (*(e+1)).hp>0))
  {
    if((*p).hp==0)
    {
      printf("%sは倒れたまま動かない…\n",(*p).name);
      sleep(1);
    }
    else{
      while(1)
      {
        printf("%s(hp:%d)はどの敵を攻撃する？\n",(*p).name,(*p).hp);
        printf("1.%s(hp:%d)  2.%s(hp:%d)\n",(*e).name,(*e).hp,(*(e+1)).name,(*(e+1)).hp);
        scanf("%d",&command);
        if(command==1)
        {
          if((*e).hp==0)
          {
            printf("%sは既に倒れている…\n",(*e).name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage((*p),(*e));
            kougeki((*p),(*e),dmg);
            (*e).hp-=dmg;
            if((*e).hp<=0)
            {
              printf("%sは倒れた！\n",(*e).name);
              sleep(2);
              (*e).hp=0;
            }
            break;
          }
        }
        else if(command==2)
        {
          if((*(e+1)).hp==0)
          {
            printf("%sは既に倒れている…\n",(*(e+1)).name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage((*p),(*(e+1)));
            kougeki((*p),(*(e+1)),dmg);
            (*(e+1)).hp-=dmg;
            if((*(e+1)).hp<=0)
            {
              printf("%sは倒れた！\n",(*(e+1)).name);
              sleep(2);
              (*(e+1)).hp=0;
            }
            break;
          }
        }
        else
        {
          printf("想定外のコマンドだ。\n");
          sleep(1);
        }
      }
    }
    if((*e).hp==0 && (*(e+1)).hp==0)
    {
      break;
    }

    if((*(p+1)).hp==0)
    {
      printf("%sは倒れたまま動かない…\n",(*(p+1)).name);
      sleep(1);
    }
    else
    {
      while(1)
      {
        printf("%s(hp:%d)はどの敵を攻撃する？\n",(*(p+1)).name,(*(p+1)).hp);
        printf("1.%s(hp:%d)  2.%s(hp:%d)\n",(*e).name,(*e).hp,(*(e+1)).name,(*(e+1)).hp);
        scanf("%d",&command);
        if(command==1)
        {
          if((*e).hp==0)
          {
            printf("%sは既に倒れている…\n",(*e).name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage((*(p+1)),(*e));
            kougeki((*(p+1)),(*e),dmg);
            (*e).hp-=dmg;
            if((*e).hp<=0)
            {
              printf("%sは倒れた！\n",(*e).name);
              sleep(2);
              (*e).hp=0;
            }
            break;
          }
        }
        else if(command==2)
        {
          if((*(e+1)).hp==0)
          {
            printf("%sは既に倒れている…\n",(*(e+1)).name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage((*(p+1)),(*(e+1)));
            kougeki((*(p+1)),(*(e+1)),dmg);
            (*(e+1)).hp-=dmg;
            if((*(e+1)).hp<=0)
            {
              printf("%sは倒れた！\n",(*(e+1)).name);
              sleep(2);
              (*(e+1)).hp=0;
            }
            break;
          }
        }
        else{
          printf("想定外のコマンドだ。\n");
          sleep(1);
        }
      }
    }


    if((*e).hp!=0)
    {
      printf("敵のターン！\n");
      sleep(2);
      printf("%sの攻撃！\n",(*e).name);
      sleep(1);
      if((*p).hp==0)
      {
        command=2;
      }
      else if((*(p+1)).hp==0)
      {
        command=1;
      }
      else{
        command=rand()%2+1;
      }
      if(command==1)
      {
        dmg=damage((*e),(*p));
        kougeki((*e),(*p),dmg);
        (*p).hp-=dmg;
        if((*p).hp<=0)
        {
          printf("%sは倒れた！\n",(*p).name);
          sleep(2);
          (*p).hp=0;
        }
      }
      else if(command==2)
      {
        dmg=damage((*e),(*(p+1)));
        kougeki((*e),(*(p+1)),dmg);
        (*(p+1)).hp-=dmg;
        if((*(p+1)).hp<=0)
        {
          printf("%sは倒れた！\n",(*(p+1)).name);
          sleep(2);
          (*(p+1)).hp=0;
        }
      }
    }

    if((*(e+1)).hp!=0)
    {
      printf("%sの攻撃！\n",(*(e+1)).name);
      sleep(1);
      if((*p).hp==0)
      {
        command=2;
      }
      else if((*(p+1)).hp==0)
      {
        command=1;
      }
      else{
        command=rand()%2+1;
      }
      if(command==1)
      {
        dmg=damage((*(e+1)),(*p));
        kougeki((*(e+1)),(*p),dmg);
        (*p).hp-=dmg;
        if((*p).hp<=0)
        {
          printf("%sは倒れた！\n",(*p).name);
          sleep(2);
          (*p).hp=0;
        }
      }
      else if(command==2)
      {
        dmg=damage((*(e+1)),(*(p+1)));
        kougeki((*(e+1)),(*(p+1)),dmg);
        (*(p+1)).hp-=dmg;
        if((*(p+1)).hp<=0)
        {
          printf("%sは倒れた！\n",(*(p+1)).name);
          sleep(2);
          (*(p+1)).hp=0;
        }
      }
    }

  }
  if((*p).hp>0 || (*(p+1)).hp>0)
  {
    if(strcmp((*p).name,"承太郎")==0)
    {
      printf("DIO「ば…ばかなッ！…………こ…このDIOが…………」\n");
      sleep(1);
      printf("DIO「このDIOがァァァァァァ～～～～～～ッ」\n");
      sleep(2);
      printf("承太郎「このまま朝日を待てば ちりになる……」\n");
      sleep(1);
      printf("承太郎「てめーの敗因は…たったひとつだぜ…　…DIO…」\n");
      sleep(1);
      printf("承太郎「たった一つの単純な答えだ………」\n");
      sleep(2);
      printf("承太郎『てめーはおれを怒らせた』\n");
      sleep(1);
      printf("DIO…『世界』ーーーー完全敗北…死亡\n");
    }
    else{
      printf("ゲームクリア！\n");
    }

  }
  else
  {
    if(strcmp((*p).name,"承太郎")==0)
    {
      printf("DIO「貧弱貧弱ゥ…ちょいとでもおれにかなうとでも思ったか！マヌケがァ〜〜！");
    }
    else{
        printf("ゲームオーバー\n");
    }
  }

  return 0;
}

int damage(struct status x,struct status y)
{
  int dmg,a,b,c;
  a=x.atk-y.def/2;
  b=a/16+1;
  c=(rand()%(2*b+1))-b;
  dmg=a+c;
  if(dmg<0)
  {
    dmg=0;
  }
  return dmg;
}
void kougeki(struct status x,struct status y,int d)
{
  printf("%sは%sに攻撃した！\n",x.name,y.name);
  sleep(1);
  if(strcmp(x.name,"承太郎")==0)
  {
    for(int i=0;i<50;i++)
    {
      printf("オラ");
    }
    printf("オラーッ！！！\n");
    sleep(1);
  }
  else if(strcmp(x.name,"DIO")==0)
  {
    for(int i=0;i<50;i++)
    {
      printf("無駄");
    }
    printf("無駄ーッ！！！\n");
    sleep(1);
  }
  printf("%sに%dのダメージ！\n",y.name,d);
  sleep(2);
}

int sute(FILE *f)
{
  int a,total;
  for(int i=0;i<10;i++)
  {
    a=fgetc(f);
    total+=a;
  }
  return total;
}
