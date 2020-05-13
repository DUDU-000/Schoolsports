#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"
#include"count_query.h"

int main() 
{
	char entry[99];
	system("CLS");
	printf("主菜单\n");
	printf("1.基本信息管理\n");
	printf("2.停止报名\n");
	printf("3.统计查询管理\n");
	printf("4.退出系统\n");

	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 4);

	switch (swi) {
	case -1: main();  break;
	case 1: basic_info(); main(); break;
	case 2: { 
		GameListNode* pHead_game = readGamelist();
		GameListNode* p = pHead_game;
		while (p->next!=NULL) {
			p->game.status = 1;
			p = p->next;
		}
		p->game.status = 1;
		saveGamelist(pHead_game);
		printf("\n\n报名已截止\n");
		system("pause");


		main();  
	}break;
	case 3: count_query(); main();  break;
	case 4: system("pause"); break;
	}
	return 0;
}


