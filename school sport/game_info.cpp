#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"

bool query_game_menu() {
	char entry;
	system("CLS");
	printf("��Ŀ��ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.���Ͳ�ѯ\n");
	printf("3.���ڲ�ѯ\n");
	printf("4.������Ŀ\n");
	printf("5.����\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: if (query_game_menu()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4:
	{
		system("CLS");
		printf("������Ŀ");
		GameListNode* pHead = readGamelist();
		printGamelist(pHead);
		system("pause");
		break;
	}
	case 5: return true; break;
	}
	return false;
}

bool game_info() {
	char entry;
	system("CLS");
	printf("��Ŀ��Ϣ\n");
	printf("1.����\n");
	printf("2.��ѯ\n");
	printf("3.����\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: if (game_info()) return true; break;
	case 1:add_info(type_game); if (game_info()) return true; break;
	case 2: if (query_game_menu()) if (game_info()) return true; break;
	case 3: return true; break;
	}
	return false;
}

