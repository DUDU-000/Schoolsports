#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"
#include"menu.h"


void query_game_menu() {
	system("CLS");
	printf("��Ŀ��ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.���Ͳ�ѯ\n");
	printf("3.���ڲ�ѯ\n");
	printf("4.������Ŀ\n");
	printf("5.����\n");

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
	printf("���ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.���е�λ\n");
	printf("3.����\n");
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
	printf("�˶�Ա��ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.С���ѯ\n");
	printf("3.�����˶�Ա\n");
	printf("4.����\n");
	
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
	printf("����\n");
	printf("1.��λ\n");
	printf("2.�˶�Ա\n");
	printf("3.��Ŀ\n");
	printf("4.����\n");

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
	printf("����\n");
	printf("1.��λ�÷�������\n");
	printf("2.�˶�Ա�÷�������\n");
	printf("3.����\n");

	int swi = swi = entrycheckandreinput(1, 3);

	switch (swi) {
	case -1: rank_menu(); break;
	case 1:   rank_menu(); break;
	case 2: RankPlayerList();  rank_menu(); break;
	case 3: break;
	}
}