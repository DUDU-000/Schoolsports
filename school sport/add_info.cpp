#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"


char Runway[7] = " 跑道 ";
char Football[7] = "足球场";
char ShotPut[7] = "标枪区";
char LongJump[7] = "跳远区";
char Discus[7] = "铅球区";
char HighJump[7] = "跳高区";

const char* kind[] = { "田赛","竞赛" };

void add_info(int type) {//type有三种类型,分别是三个在basic_info.h里的常数,对应三种情况
	FILE* file = fopen("game.txt", "r");
	int test = 0;//有无数据文件的标志即判断需不需要创建头节点的标志（0需要|1不需要）
	if (file==NULL)//当没有这个文件的时候返回值是NULL
	{
		file = fopen("game.txt", "w");
		test = 1;
		
	}
	switch (type) {
	case type_game: //增加一个比赛项目
		Game newGame;
		int place_selection;
		printf("项目名称：");
		scanf_s("%s", &newGame.name.name,99);

		printf("比赛类型(1.田赛  2.竞赛)：");
		scanf_s("%d", &newGame.type);//这是我网上搜到的枚举类型输入方式
		newGame.type =(Type)( newGame.type - 1);

		printf("比赛地点(1.跑道  2.足球场  3.标枪区  4.跳远区  5.铅球区  6.跳高区)：");
		scanf_s("%d", &place_selection);
		switch (place_selection)
		{
		case 1:strcpy(Runway,newGame.place);break;
		case 2:strcpy(Football,newGame.place); break;
		case 3:strcpy(ShotPut,newGame.place); break;
		case 4:strcpy(LongJump,newGame.place); break;
		case 5:strcpy(Discus,newGame.place); break;
		case 6:strcpy(HighJump,newGame.place); break;
		}

		printf("开始时间：\n");
		printf("月份：");
		scanf_s("%d", &newGame.starttime.month);
		printf("日期：");
		scanf_s("%d", &newGame.starttime.date);
		printf("几点：");
		scanf_s("%d", &newGame.starttime.hour);
		printf("几分：");
		scanf_s("%d", &newGame.starttime.minute);

		printf("报名截止时间：\n");
		printf("月份：");
		scanf_s("%d", &newGame.endtime.month);
		printf("日期：");
		scanf_s("%d", &newGame.endtime.date);
		printf("几点：");
		scanf_s("%d", &newGame.endtime.hour);
		printf("几分：");
		scanf_s("%d", &newGame.endtime.minute);
		
		newGame.number = 0;
		//前面是输入新链表	



		
		if (test == 1) {//没有数据文件
			file = fopen("game.txt", "a");
			newGame.name.id = 0001;
			fprintf(file, "%d\n%s\n%s\n%s\n开始时间:%d月%d日 %d:%d\n报名截止时间:%d月%d日 %d:%d\n报名人数:%d\n", newGame.name.id/*id*/, newGame.name.name/*名称*/, kind[(int)(newGame.type)]/*类型*/, newGame.place/*地点*/, newGame.starttime.month, newGame.starttime.date, newGame.starttime.hour, newGame.starttime.minute/*开始时间*/, newGame.endtime.month, newGame.endtime.date, newGame.endtime.hour, newGame.endtime.minute/*报名截止时间*/,newGame.number/*报名人数*/);
			fclose(file);
		}
		
		//待写 从文件中读取已储存的链表,若是没有数据,则创建头节点,若已有,接入一个节点

		


		break;

	case type_group: //增加一个组
		system("CLS");

		break;

	case type_player: //增加一个运动员
		system("CLS");

		break;

	}
}