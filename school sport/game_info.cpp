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
	case 0: query_game_menu(); break;

	case 1: {



	
	}break;

	case 2: {
		system("CLS");
		GameListNode* pHead = readGamelist();
		searchGamelist_type(pHead);
		system("pause");
	}break;

	case 3: break;
	case 4:{
		system("CLS");
		printf("������Ŀ");
		GameListNode* pHead = readGamelist();
		printGamelist(pHead);
		system("pause");
	}break;

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
	case 0: game_info(); break;
	case 1: add_info(type_game); game_info(); break;
	case 2: query_game_menu(); game_info(); break;
	case 3: break;
	}
}

