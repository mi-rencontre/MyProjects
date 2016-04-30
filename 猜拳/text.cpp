#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_SIZE 20
#define PASSWD_SIZE 20
#define NAME "huangmi"
#define PASSWD "123"
#define TRUE    1
#define NFLISH {int ch = 0;\
                 while((ch = getchar()) != '\n'\
                    && ch != EOF}
#define CONTINUE(X)  {printf("%s",X);getchar();}

typedef struct player{
	char name[NAME_SIZE];
	char passwd[PASSWD_SIZE];
	int total;
	int victory;
}player_t;

player_t* player;

player_t *creat_player(void)
{
	player = (player_t *)malloc(sizeof(player_t)*1);
	if(NULL == player)
	{
		return NULL;
	}
	memset(player,0,sizeof(player_t));
	strcpy(player->name,NAME);
	strcpy(player->passwd,PASSWD);
	player->total = 0;
	player->victory = 0;
}

void destory_player()
{
	if(NULL != player)
	{
		free(player);
		player = NULL;
	}
}

void menu()
{
//	system("cls");              \\清屏
	printf("欢迎进入游戏:\n");
	printf("1.石头 2.剪刀 3.布 0.退出\n");
	printf("请出拳:\n");
}

int myrand()
{
	int choose = 0;
	srand(time(NULL));
	choose = rand()%3;
	return choose;
}

void out_win(int player_choose,int computer_choose)
{
	if(player_choose == 1)
	{
		if(computer_choose == 2)
		{
		printf("玩家出的是石头，电脑出的是剪刀\n");
		}
		else if(computer_choose == 1)
		{
			printf("玩家出的是石头，电脑出的是石头\n");
		}
		else if(computer_choose == 3)
		{
			printf("玩家出的是石头，电脑出的是布\n");
		}
	}
	else if(player_choose == 2)
	{
		if(computer_choose == 3)
		{
		    printf("玩家出的是剪刀，电脑出的是布\n");
		}
		else if(computer_choose == 2)
		{
			printf("玩家出的是剪刀，电脑出的是剪刀\n");
		}
		else if(computer_choose == 1)
		{
			printf("玩家出的是剪刀，电脑出的是石头\n");
		}
	}
	else if(player_choose == 3)
	{
		if(computer_choose == 3)
		{
		    printf("玩家出的是布，电脑出的是布\n");
		}
		else if(computer_choose == 2)
		{
			printf("玩家出的是布，电脑出的是剪刀\n");
		}
		else if(computer_choose == 1)
		{
			printf("玩家出的是布，电脑出的是石头\n");
		}
	}
}

void menu_str()
{
	int player_choose = 0;
	int computer_choose = 0;
	int win = 0;
	while(true)
	{
		do
		{
			menu();
			scanf("%d",&player_choose);
//			NFLISH;
		}while(player_choose > 3 || player_choose < 0);

		if(0 == player_choose)
		{
			return;
		}
		computer_choose = myrand();
		out_win(player_choose,computer_choose);
		win = player_choose - computer_choose;
		player->total++;
		switch(win)
		{
		case -1 :
			printf("恭喜，你赢了\n");
			player->victory++;
			break;
		case 2:
			printf("恭喜，你赢了\n");
			player->victory++;
			break;
		case 0:
			printf("平局\n");
			break;
		default:
			printf("很遗憾，你输了\n");
			break;
		}
	}
}

void victory_display()
{
	double win = 0.0;
	printf("\n\n\t\t  排行榜\n");
	printf("*********************************************\n");
	printf("%10s  %10s %10s %10s\n","姓名","总局数","胜利数","胜算\n");
	printf("*********************************************\n");
	win = (double)player->victory / (double)player->total;
	printf("    %s     %d            %d         %lf\n",player->name,player->total,player->victory,win);
}

int main()
{
	player = creat_player();
	if(NULL == player)
	{
		return 1;
	}
	menu_str();
	victory_display();
	destory_player();
	return 0;
}