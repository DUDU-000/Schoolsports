#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"
#include"linked_list.h"

void single_player_score() {
	char entry_playerid[99];
	system("CLS");
	printf("个人成绩查询\n");
	printf("请输入运动员ID:");
	gets_s(entry_playerid, 99);
	rewind(stdin);
	int id = entrycheck(entry_playerid, 0, 999);
	PlayerListNode* p = readPlayerlist();//读取运动员链表查询记录
	if (p == NULL) { 
		printf("查询不到相关内容\n");
		goto lable;
	}
	while (p->player.name.id != id) {
		if (p->next == NULL)break;

		p = p->next;
		
	}//查找运动员
	if (p->player.name.id != id)printf("查询不到相关内容\n");
	else {
		system("CLS");
		Player player= p->player;
		printf("所查询运动员\nID : %d\n名称 : %s\n", player.name.id, player.name.name);
		for (int i = 0; i < player.game_number; i++) {
			printf(" %s 比赛的排名 : %d | 成绩 : %f\n", player.score[i].name.name, player.score[i].rank, player.score[i].score);
		}
	}
	lable:
	system("pause");
}

void RankPlayer_in_Game() {
	char entry_gameid[99];
	BriefGame_2ListNode *p = InipHead();
	system("CLS");
	printf("比赛排名查询\n");
	printf("请输入比赛ID:");
	gets_s(entry_gameid, 99);
	rewind(stdin);
	int id = entrycheck(entry_gameid, 0, 999);
	while (p != NULL && p->briefgame_2.name.id == id)p = p->next;
	if (p->briefgame_2.name.id == id) {
		printf("%s比赛的运动员排名为:\n", p->briefgame_2.name.name);
		for (int i = 0; i < p->briefgame_2.number; i++) {
			printf("第%d名:%s\n", i + 1, p->briefgame_2.playername[i]);
		}
	}
	if (p == NULL)printf("查询出错！\n");
	system("pause");
}

void count_query_player() {
	char entry[99];
	system("CLS");
	printf("运动员排名及成绩查询\n");
	printf("1.运动员个人成绩\n");
	printf("2.比赛的所有运动员排名\n");
	printf("3.返回\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case -1: break;
	case 1:single_player_score(); count_query_player(); break;
	case 2: RankPlayer_in_Game(); count_query_player(); break;
	case 3: break;
	}
}