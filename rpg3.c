#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct status{
  char name[20];
  int hp;
  int atk;
  int def;
};
int damage(struct status,struct status);
void kougeki(struct status,struct status,int);

int main(int argc,char **argv)
{
  struct status p1={"まかろに。",100,100,100};
  struct status p2={"かぺりーに。",100,100,100};
  struct status e1={"フォカッチャ",100,100,100};
  struct status e2={"パニーニ",100,100,100};
  int command;
  int dmg;

  printf("ゲームスタート\n");
  printf("%s,%sが現れた！\n",e1.name,e2.name);
  while((p1.hp>0 || p2.hp>0) && (e1.hp>0 || e2.hp>0))
  {
    printf("%s(hp:%d)はどの敵を攻撃しますか？\n",p1.name,p1.hp);
    printf("1.%s(hp:%d)  2.%s(hp:%d)\n",e1.name,e1.hp,e2.name,e2.hp);
    scanf("%d",&command);
    if(command==1)
    {
      if(e1.hp==0)
      {
        printf("%sは既に倒れている…\n",e1.name);
      }
      else
      {
        dmg=damage(p1,e1);
        kougeki(p1,e1,dmg);
        e1.hp-=dmg;
        if(e1.hp<=0)
        {
          printf("%sは倒れた！\n",e1.name);
          e1.hp=0;
        }
      }
    }
    else if(command==2)
    {
      if(e2.hp==0)
      {
        printf("%sは既に倒れている…\n",e2.name);
      }
      else
      {
        dmg=damage(p1,e2);
        kougeki(p1,e2,dmg);
        e2.hp-=dmg;
        if(e2.hp<=0)
        {
          printf("%sは倒れた！\n",e2.name);
          e2.hp=0;
        }
      }
    }

    printf("%s(hp:%d)はどの敵を攻撃しますか？\n",p2.name,p2.hp);
    printf("1.%s(hp:%d)  2.%s(hp:%d)\n",e1.name,e1.hp,e2.name,e2.hp);
    scanf("%d",&command);
    if(command==1)
    {
      if(e1.hp==0)
      {
        printf("%sは既に倒れている…\n",e1.name);
      }
      else
      {
        dmg=damage(p2,e1);
        kougeki(p2,e1,dmg);
        e1.hp-=dmg;
        if(e1.hp<=0)
        {
          printf("%sは倒れた！\n",e1.name);
          e1.hp=0;
        }
      }
    }
    else if(command==2)
    {
      if(e2.hp==0)
      {
        printf("%sは既に倒れている…\n",e2.name);
      }
      else
      {
        dmg=damage(p2,e2);
        kougeki(p2,e2,dmg);
        e2.hp-=dmg;
        if(e2.hp<=0)
        {
          printf("%sは倒れた！\n",e2.name);
          e2.hp=0;
        }
      }
    }

    printf("%sの攻撃！\n",e1.name);
    command=rand()%2+1;
    if(command==1)
    {
      dmg=damage(e1,p1);
      kougeki(e1,p1,dmg);
      p1.hp-=dmg;
    }
    else if(command==2)
    {
      dmg=damage(e1,p2);
      kougeki(e1,p2,dmg);
      p2.hp-=dmg;
    }

    printf("%sの攻撃！\n",e2.name);
    command=rand()%2+1;
    if(command==1)
    {
      dmg=damage(e2,p1);
      kougeki(e2,p1,dmg);
      p1.hp-=dmg;
    }
    else if(command==2)
    {
      dmg=damage(e2,p2);
      kougeki(e2,p2,dmg);
      p2.hp-=dmg;
    }
  }
  printf("ゲーム終了\n");
  return 0;
}

int damage(struct status x,struct status y)
{
  int dmg,a,b,c;
  a=x.atk-y.def/2;
  b=a/16+1;
  c=(rand()%(2*b+1))-b;
  dmg=a+c;
  return dmg;
}
void kougeki(struct status x,struct status y,int d)
{
  printf("%sは%sに攻撃した！\n",x.name,y.name);
  printf("%sに%dのダメージ！\n",y.name,d);
}
