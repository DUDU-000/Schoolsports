#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


void score_entry(Game game) {
	printf("\n\n");
	printf("�ɼ�¼��\n");
	printf("����������, ����������\n");

	PlayerListNode *pHead_player = readPlayerlist();

	for (int j = 0; j < game.number; j++) {
		printf("��%d����: ID:%d ", j+1,game.playerid[j].id);//������Աid
		printf("����:%s \n", game.playerid[j].name);//������Աid
		PlayerListNode *p_player = pHead_player;
		while (p_player->player.name.id != game.playerid[j].id) {//�ҵ����˶�Ա
			p_player = p_player->next;
		}
		int i=0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}
		printf("�ɼ�(��/��):");
		scanf("%d", &p_player->player.score[i].score);
		printf("����:");
		scanf("%d", &p_player->player.score[i].rank);
		printf("�÷�:");
		scanf("%d", &p_player->player.score[i].point);
	}
	savePlayerlist(pHead_player);

	printf("�ɼ�¼�����");
	system("pause");
}


