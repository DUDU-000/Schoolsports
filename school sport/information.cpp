#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"


void information_game(GameListNode* pnewHead,int situation) {//����ͷ�ڵ�Ͷ�Ӧ��λ��(�ڼ���)
	int i = 1;
	GameListNode* p=pnewHead;
	Game game;
	

	while (i != situation) {//�ҵ���ѡ��Ľڵ�
		p = p->next;
		i++;
	}

	system("CLS");
	game = p->game;
	printf( "��Ŀ��Ϣ:\n");//��ӡ��Ŀ������Ϣ
	printf("����:%s\n", game.name.name/*����*/);
	printf("����:%s\n", game.type/*����*/);
	printf("�ص�:%s\n", game.place/*�ص�*/);
	printf("����:%d\n", game.number/*��������*/);
	printf("ʱ��:%d��%d��%d : %d-%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/, game.endtime.hour, game.endtime.minute/*����ʱ��*/);
	printf("������ԱID:");
	if (game.playerid[0] == NULL|| game.playerid[0]<=0) printf("��");
	else for (int j = 0; j < game.number; j++) printf("%d   ", game.playerid[j]);//������Աid
	printf("\n\n\n");


	printf("����:\n");//����
	printf("1.�޸�\n2.ɾ��\n3.����\n");//ѡ��

	int x=0;
	char entry_s[99] = {0};
	while (x == 0)//������
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 3);
		if (x == 0)printf("��������,����������:");
	}
	switch (x)
	{
	case 1: reviseGame(game); break;//�޸�
	case 2:
	{
		GameListNode* pHead = readGamelist();
		p = pHead;
		while (p->game.name.id!=game.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
			p = p->next;
		}
		pHead = deleteNode(pHead, p);
		saveGamelist(pHead);
		printf("\n\nɾ�����\n");
		system("pause");
	}
		break;//ɾ��
	case 3:break;//����
	}
}

void information_player(PlayerListNode* pnewHead, int situation) {
	int i = 1;
	PlayerListNode* p = pnewHead;
	Player player;
	

	while (i != situation) {//�ҵ���ѡ��Ľڵ�
		p = p->next;
		i++;
	}

	system("CLS");
	player = p->player;
	printf("�˶�Ա��Ϣ:\n");//��ӡ��Ŀ������Ϣ
	printf("ID:%d\n", player.name.id);//id
	printf("����:%s\n", player.name.name);//����
	printf("�Ա�:%s\n", player.gender);//�Ա�
	printf("����:%d\n", player.year);//id
	printf("С��ID:%d\n", player.group_id);//С��ID
	printf("�ܷ���:%d\n", player.fullscore);//�ܷ���
	printf("������:%d\n", player.game_number);//������

	printf("������Ŀ:%d\n", player.game_number);//������
	if (player.game_number == 0) printf("��\n");
	else 
	for (int j = 0; j < player.game_number; j++) {
		printf("��Ŀ����:%s ", player.score->name.name);//��Ŀ����
		printf("��Ŀ�ɼ�:%f ", player.score->score);//��Ŀ�ɼ�
		printf("��Ŀ�÷�:%d \n", player.score->point);//��Ŀ�ɼ�
	}


	printf("\n\n\n");
	printf("����:\n");//����
	printf("1.�޸�\n2.ɾ��\n3.����\n");//ѡ��

	int x = 0;
	char entry_s[99];
	while (x == 0)//������
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 3);
		if (x == 0)printf("��������,����������:");
	}
	switch (x)
	{
	case 1: revisePlayer(player); break;//�޸�
	case 2:
	{
		PlayerListNode* pHead = readPlayerlist();
		p = pHead;
		while (p->player.name.id != player.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
			p = p->next;
		}
		pHead = deleteNode(pHead, p);
		savePlayerlist(pHead);
		printf("\n\nɾ�����\n");
		system("pause");
	}//ɾ��
	break;
	case 3:break;//����
	}
}

void information_group(GroupListNode* pnewHead, int situation) {
	int i = 1;
	GroupListNode* p = pnewHead;
	Group group;
	while (i != situation) {
		p = p->next;
	}
	system("CLS");
	printf("��λ����:%s\n", group.name.name);
	printf("��λ����:%d\n", group.member_number);
	printf("��λ�ܵ÷�:%d\n", group.fullscore);
	printf("��λ����������:%d\n", group.game_number);
	int swi=0;
	char entry_str[99] = {0};
	printf("\n\n\n");
	printf("����:\n");//����
	printf("1.��ѯ�����ɼ�\n2.��ѯ��λ��Ա\n3.�޸�\n4.ɾ��\n5.����\n");//ѡ��
	while (swi == 0) {
		gets_s(entry_str, 99);
		rewind(stdin);
		swi = entrycheck(entry_str, 1, 5);
		if (swi == 0)printf("��������,����������:");
	}

	switch (swi)
	{
	case 1:searchGroup_game(p);break;
	case 2:searchGroup_palyer(p); break;
	case 3:break;
	case 4: {
		GroupListNode* pHead = readGrouplist();
		p = pHead;
		while (p->group.name.id != group.name.id) {
			p=p->next;
		}
	    deleteNode(p);
		saveGrouplist(pHead);
		printf("\n\nɾ�����\n");
		system("pause");
	}
	case 5:break;//����
	}
}