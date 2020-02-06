#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"




void add_info(int type) {//type有三种类型,分别是三个在basic_info.h里的常数,对应三种情况
	
	switch (type) {
	case type_game: //增加一个比赛项目
		Game newGame;
		GameListNode* pHead;
		int place_selection,type_selection;

		//填写newGame的数据
		system("CLS");
		printf("项目名称：");
		scanf_s("%s", &newGame.name.name,99);

		printf("比赛类型(1.田赛  2.竞赛)：");
		scanf_s("%d", &type_selection);//这是我网上搜到的枚举类型输入方式
		if(type_selection==1) strcpy(newGame.type, Tian);
		else strcpy(newGame.type, Jing);

		printf("比赛地点(1.跑道  2.足球场  3.标枪区  4.跳远区  5.铅球区  6.跳高区)：");
		scanf_s("%d", &place_selection);
		switch (place_selection)
		{
		case 1:strcpy(newGame.place, Runway); break;
		case 2:strcpy(newGame.place, Football); break;
		case 3:strcpy(newGame.place, ShotPut); break;
		case 4:strcpy(newGame.place, LongJump); break;
		case 5:strcpy(newGame.place, Discus); break;
		case 6:strcpy(newGame.place, HighJump); break;
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

		printf("结束时间：\n");
		printf("几点：");
		scanf_s("%d", &newGame.endtime.hour);
		printf("几分：");
		scanf_s("%d", &newGame.endtime.minute);
		newGame.number = 0;




	
		pHead = readGamelist();	//读取文件中的链表到pHead
		if (pHead == NULL) { //若文件中无数据,则新建一个链表
			newGame.name.id = 1;
			pHead = createpHead(newGame);
		}
		else { //若有数据,则在pHead链表最后新增一个节点
			newGame.name.id = longNode(pHead) + 1;//设id,id为链表的顺序
			addNode(pHead, newGame);
		}
		saveGamelist(pHead);//储存链表

		break;

	case type_group: //增加一个组
		system("CLS");

		break;

	case type_player: //增加一个运动员
		system("CLS");

		break;

	}
	printf("\n\n新增完成\n");
	system("pause");
}