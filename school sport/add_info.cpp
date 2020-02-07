#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"

void add_info(int type) {//type有三种类型,分别是三个在basic_info.h里的常数,对应三种情况

	switch (type) {
	case type_game: //增加一个比赛项目
	{
		Game newGame;
		GameListNode* pHead, *p;
		int entry_int = 0;
		char entry_s[99];


		//填写newGame的数据
		system("CLS");
		printf("项目名称：");
		scanf_s("%s", &newGame.name.name, 99);
		rewind(stdin);

		printf("比赛类型(1.田赛  2.竞赛)：");

		entry_int = 0;//开始输入检测是否是数字,我改了一下entrycheck,参数是一个char数组
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 2);//若是一个数字,则返回int,否则,返回0
			switch (entry_int)
			{
			case 0:printf("输入有误,请重新输入:"); break;
			case 1:strcpy(newGame.type, Tian); break;
			case 2:strcpy(newGame.type, Jing); break;
			}
		}//结束检测

		printf("比赛地点(1.跑道  2.足球场  3.标枪区  4.跳远区  5.铅球区  6.跳高区)：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 6);
			switch (entry_int)
			{
			case 0:printf("输入有误,请重新输入:"); break;
			case 1:strcpy(newGame.place, Runway); break;
			case 2:strcpy(newGame.place, Football); break;
			case 3:strcpy(newGame.place, ShotPut); break;
			case 4:strcpy(newGame.place, LongJump); break;
			case 5:strcpy(newGame.place, Discus); break;
			case 6:strcpy(newGame.place, HighJump); break;
			}
		}

		printf("月份：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 12);
			newGame.starttime.month = entry_int;
			if(entry_int == 0)printf("输入有误,请重新输入:");
		}

		printf("日期：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 31);
			newGame.starttime.date = entry_int;
			if (entry_int == 0)printf("输入有误,请重新输入:");
		}


		printf("开始时间：\n");
		printf("几点：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 0, 24);
			newGame.starttime.hour = entry_int;
			if (entry_int == 0)printf("输入有误,请重新输入:");
		}

		printf("几分：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 0, 60);
			newGame.starttime.minute = entry_int;
			if (entry_int == 0)printf("输入有误,请重新输入:");
		}

		printf("结束时间：\n");
		printf("几点：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 0, 24);
			newGame.endtime.hour = entry_int;
			if (entry_int == 0)printf("输入有误,请重新输入:");
		}
		printf("几分：");
		entry_int = 0;
		while (entry_int == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 0, 60);
			newGame.endtime.minute = entry_int;
			if (entry_int == 0)printf("输入有误,请重新输入:");
		}
		newGame.number = 0;

		pHead = readGamelist();	//读取文件中的链表到pHead
		p = pHead;
		if (pHead == NULL) { //若文件中无数据,则新建一个链表
			newGame.name.id = 1;
			pHead = createpHead(newGame);
		}
		else { //若有数据,则在pHead链表最后新增一个节点
			while (p->next != NULL) {//找到最后的节点指针
				p = p->next;
			}
			newGame.name.id = p->game.name.id + 1;//设id,id为链表的顺序
			addNode(pHead, newGame);
		}
		saveGamelist(pHead);//储存链表


	}break;//结束该case

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