#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

bool query_player_menu() {
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
	case 0: if (query_player_menu()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
}

bool player_info() {
	char entry;
	system("CLS");
	printf("�˶�Ա��Ϣ\n");
	printf("1.����\n");
	printf("2.��ѯ\n");
	printf("3.����\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: if (player_info()) return true; break;
	case 1: break;
	case 2: if (query_player_menu()) if (player_info()) return true; break;
	case 3: return true; break;
	}
	return false;
}

