#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"


void query_game_menu() {
	char entry[99];
	system("CLS");
	printf("��Ŀ��ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.���Ͳ�ѯ\n");
	printf("3.���ڲ�ѯ\n");
	printf("4.������Ŀ\n");
	printf("5.����\n");

	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case -1: query_game_menu(); break;
	case 1: searchGamelist_name(); break;
	case 2: searchGamelist_type(); break;
	case 3: searchGamelist_time(); break;
	case 4: searchGamelist_all(); break;
	case 5: break;
	}
}

void game_info() {
	char entry[99];
	system("CLS");
	printf("��Ŀ��Ϣ\n");
	printf("1.����\n");
	printf("2.��ѯ\n");
	printf("3.����\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case -1: game_info(); break;
	case 1: addGameNode(); game_info(); break;
	case 2: query_game_menu(); game_info(); break;
	case 3: break;
	}
}

