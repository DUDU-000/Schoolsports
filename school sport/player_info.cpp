#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

void query_player_menu() {
	char entry[99];
	system("CLS");
	printf("运动员查询\n");
	printf("1.名称查询\n");
	printf("2.小组查询\n");
	printf("3.所有运动员\n");
	printf("4.返回\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: query_player_menu(); break;
	case 1: searchPlayerlist_name(); break;
	case 2: searchPlayerlist_group(); break;
	case 3: searchPlayer_all(); break;
	case 4: break;
	}
}

void player_info() {
	char entry[99];
	system("CLS");
	printf("运动员信息\n");
	printf("1.增加\n");
	printf("2.查询\n");
	printf("3.返回\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: player_info(); break;
	case 1: addPlayerNode(); player_info(); break;
	case 2: query_player_menu(); player_info(); break;
	case 3: break;
	}
}

