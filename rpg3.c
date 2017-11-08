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
  srand(time(NULL));
  struct status p1,p2,e1,e2;
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
  p1.hp=t1/10;

  t1=sute(f1);
  p1.atk=t1/20;

  t1=sute(f1);
  p1.def=t1/20;

  //player2のステータス設定
  t2=sute(f1);
  p2.hp=t2/10;

  t2=sute(f1);
  p2.atk=t2/20;

  t2=sute(f1);
  p2.def=t2/20;

  fclose(f1);

  //enemy1のステータス設定
  strcpy(e1.name,"スライムくん");

  f2=fopen(argv[2],"r");
  if(f2==NULL)
  {
    printf("開くファイルをもう一つ渡してください。\n");
    exit(-1);
  }

  t3=sute(f2);
  e1.hp=t3/10;

  t3=sute(f2);
  e1.atk=t3/20;

  t3=sute(f2);
  e1.def=t3/20;

  //enemy2のステータス設定
  strcpy(e2.name,"ドラゲナイ");

  t4=sute(f2);
  e2.hp=t4/10;

  t4=sute(f2);
  e2.atk=t4/20;

  t4=sute(f2);
  e2.def=t4/20;
  fclose(f2);

  printf("ゲームスタート\n");
  sleep(1);
  printf("一人目の味方の名前を設定してください。\n");
  fgets(p1.name,sizeof(p1.name),stdin);
  strtok(p1.name,"\n\0");
  if(strcmp(p1.name,"承太郎")==0)
  {
    p1.hp=999;
    p1.atk=300;
    p1.def=300;
    strcpy(e1.name,"DIO");
    e1.hp=999;
    e1.atk=300;
    e1.def=300;
  }
  printf("二人目の味方の名前を設定してください。\n");
  fgets(p2.name,sizeof(p2.name),stdin);
  strtok(p2.name,"\n\0");
  printf("%s,%sが現れた！\n",e1.name,e2.name);
  sleep(2);
  while((p1.hp>0 || p2.hp>0) && (e1.hp>0 || e2.hp>0))
  {
    if(p1.hp==0)
    {
      printf("%sは倒れたまま動かない…\n",p1.name);
      sleep(1);
    }
    else{
      while(1)
      {
        printf("%s(hp:%d)はどの敵を攻撃する？\n",p1.name,p1.hp);
        printf("1.%s(hp:%d)  2.%s(hp:%d)\n",e1.name,e1.hp,e2.name,e2.hp);
        scanf("%d",&command);
        if(command==1)
        {
          if(e1.hp==0)
          {
            printf("%sは既に倒れている…\n",e1.name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage(p1,e1);
            kougeki(p1,e1,dmg);
            e1.hp-=dmg;
            if(e1.hp<=0)
            {
              printf("%sは倒れた！\n",e1.name);
              sleep(2);
              e1.hp=0;
            }
            break;
          }
        }
        else if(command==2)
        {
          if(e2.hp==0)
          {
            printf("%sは既に倒れている…\n",e2.name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage(p1,e2);
            kougeki(p1,e2,dmg);
            e2.hp-=dmg;
            if(e2.hp<=0)
            {
              printf("%sは倒れた！\n",e2.name);
              sleep(2);
              e2.hp=0;
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
    if(e1.hp==0 && e2.hp==0)
    {
      break;
    }

    if(p2.hp==0)
    {
      printf("%sは倒れたまま動かない…\n",p2.name);
      sleep(1);
    }
    else
    {
      while(1)
      {
        printf("%s(hp:%d)はどの敵を攻撃する？\n",p2.name,p2.hp);
        printf("1.%s(hp:%d)  2.%s(hp:%d)\n",e1.name,e1.hp,e2.name,e2.hp);
        scanf("%d",&command);
        if(command==1)
        {
          if(e1.hp==0)
          {
            printf("%sは既に倒れている…\n",e1.name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage(p2,e1);
            kougeki(p2,e1,dmg);
            e1.hp-=dmg;
            if(e1.hp<=0)
            {
              printf("%sは倒れた！\n",e1.name);
              sleep(2);
              e1.hp=0;
            }
            break;
          }
        }
        else if(command==2)
        {
          if(e2.hp==0)
          {
            printf("%sは既に倒れている…\n",e2.name);
            sleep(1);
            continue;
          }
          else
          {
            dmg=damage(p2,e2);
            kougeki(p2,e2,dmg);
            e2.hp-=dmg;
            if(e2.hp<=0)
            {
              printf("%sは倒れた！\n",e2.name);
              sleep(2);
              e2.hp=0;
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


    if(e1.hp!=0)
    {
      printf("敵のターン！\n");
      sleep(2);
      printf("%sの攻撃！\n",e1.name);
      sleep(1);
      if(p1.hp==0)
      {
        command=2;
      }
      else if(p2.hp==0)
      {
        command=1;
      }
      else{
        command=rand()%2+1;
      }
      if(command==1)
      {
        dmg=damage(e1,p1);
        kougeki(e1,p1,dmg);
        p1.hp-=dmg;
        if(p1.hp<=0)
        {
          printf("%sは倒れた！\n",p1.name);
          sleep(2);
          p1.hp=0;
        }
      }
      else if(command==2)
      {
        dmg=damage(e1,p2);
        kougeki(e1,p2,dmg);
        p2.hp-=dmg;
        if(p2.hp<=0)
        {
          printf("%sは倒れた！\n",p2.name);
          sleep(2);
          p2.hp=0;
        }
      }
    }

    if(e2.hp!=0)
    {
      printf("%sの攻撃！\n",e2.name);
      sleep(1);
      if(p1.hp==0)
      {
        command=2;
      }
      else if(p2.hp==0)
      {
        command=1;
      }
      else{
        command=rand()%2+1;
      }
      if(command==1)
      {
        dmg=damage(e2,p1);
        kougeki(e2,p1,dmg);
        p1.hp-=dmg;
        if(p1.hp<=0)
        {
          printf("%sは倒れた！\n",p1.name);
          sleep(2);
          p1.hp=0;
        }
      }
      else if(command==2)
      {
        dmg=damage(e2,p2);
        kougeki(e2,p2,dmg);
        p2.hp-=dmg;
        if(p2.hp<=0)
        {
          printf("%sは倒れた！\n",p2.name);
          sleep(2);
          p2.hp=0;
        }
      }
    }

  }
  if(p1.hp>0 || p2.hp>0)
  {
    if(strcmp(p1.name,"承太郎")==0)
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
    if(strcmp(p1.name,"承太郎")==0)
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
