#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"
#include"menu.h"


void query_game_menu() {
	system("CLS");
	printf("项目查询\n");
	printf("1.名称查询\n");
	printf("2.类型查询\n");
	printf("3.日期查询\n");
	printf("4.所有项目\n");
	printf("5.返回\n");

	int swi = swi = entrycheckandreinput(1, 5);

	switch (swi) {
	case -1: query_game_menu(); break;
	case 1: searchGamelist_name(); break;
	case 2: searchGamelist_type(); break;
	case 3: searchGamelist_time(); break;
	case 4: searchGamelist_all(); break;
	case 5: break;
	}
}
void query_group_menu() {
	
	system("CLS");
	printf("组查询\n");
	printf("1.名称查询\n");
	printf("2.所有单位\n");
	printf("3.返回\n");
	int swi = swi = entrycheckandreinput(1, 3);
	switch (swi) {
	case -1: query_group_menu(); break;
	case 1:searchGroup_name(); break;
	case 2:searchGroup_all(); break;
	case 3:break;
	}
}
void query_player_menu() {

	system("CLS");
	printf("运动员查询\n");
	printf("1.名称查询\n");
	printf("2.小组查询\n");
	printf("3.所有运动员\n");
	printf("4.返回\n");
	
	int swi = swi = entrycheckandreinput(1, 4);
	
	switch (swi) {
	case -1: query_player_menu(); break;
	case 1: searchPlayerlist_name(); break;
	case 2: searchPlayerlist_group(); break;
	case 3: searchPlayer_all(); break;
	case 4: break;
	}
}
void add_menu() {
	system("CLS");
	printf("增加\n");
	printf("1.单位\n");
	printf("2.运动员\n");
	printf("3.项目\n");
	printf("4.返回\n");

	int swi = swi = entrycheckandreinput(1, 4);

	switch (swi) {
	case -1: add_menu(); break;
	case 1: addGroupNode();  add_menu(); break;
	case 2: addPlayerNode();  add_menu(); break;
	case 3: addGameNode(); add_menu(); break;
	case 4: break;
	}
}

void rank_menu() {
	system("CLS");
	printf("排名\n");
	printf("1.单位得分总排名\n");
	printf("2.运动员得分总排名\n");
	printf("3.返回\n");

	int swi = swi = entrycheckandreinput(1, 3);

	switch (swi) {
	case -1: rank_menu(); break;
	case 1:   rank_menu(); break;
	case 2: RankPlayerList();  rank_menu(); break;
	case 3: break;
	}
}