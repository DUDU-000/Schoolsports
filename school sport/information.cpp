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
	char entry[99];

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