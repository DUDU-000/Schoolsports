#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"
#include"linked_list.h"

void single_player_score() {
	char entry_playerid[99];
	system("CLS");
	printf("���˳ɼ���ѯ\n");
	printf("�������˶�ԱID:");
	gets_s(entry_playerid, 99);
	rewind(stdin);
	int id = entrycheck(entry_playerid, 0, 999);
	PlayerListNode* p = readPlayerlist();//��ȡ�˶�Ա�����ѯ��¼
	if (p == NULL) { 
		printf("��ѯ�����������\n");
		goto lable;
	}
	while (p->player.name.id != id) {
		if (p->next == NULL)break;

		p = p->next;
		
	}//�����˶�Ա
	if (p->player.name.id != id)printf("��ѯ�����������\n");
	else {
		system("CLS");
		Player player= p->player;
		printf("����ѯ�˶�Ա\nID : %d\n���� : %s\n", player.name.id, player.name.name);
		for (int i = 0; i < player.game_number; i++) {
			printf(" %s ���������� : %d | �ɼ� : %f\n", player.score[i].name.name, player.score[i].rank, player.score[i].score);
		}
	}
	lable:
	system("pause");
}

void RankPlayer_in_Game() {
	char entry_gameid[99];
	BriefGame_2ListNode *p = InipHead();
	system("CLS");
	printf("����������ѯ\n");
	printf("���������ID:");
	gets_s(entry_gameid, 99);
	rewind(stdin);
	int id = entrycheck(entry_gameid, 0, 999);
	while (p != NULL && p->briefgame_2.name.id == id)p = p->next;
	if (p->briefgame_2.name.id == id) {
		printf("%s�������˶�Ա����Ϊ:\n", p->briefgame_2.name.name);
		for (int i = 0; i < p->briefgame_2.number; i++) {
			printf("��%d��:%s\n", i + 1, p->briefgame_2.playername[i]);
		}
	}
	if (p == NULL)printf("��ѯ����\n");
	system("pause");
}

void count_query_player() {
	char entry[99];
	system("CLS");
	printf("�˶�Ա�������ɼ���ѯ\n");
	printf("1.�˶�Ա���˳ɼ�\n");
	printf("2.�����������˶�Ա����\n");
	printf("3.����\n");
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