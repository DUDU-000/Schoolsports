#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"linked_list.h"
#include"basic_info.h"


void addGameNode() {//type����������,�ֱ���������basic_info.h��ĳ���,��Ӧ�������

	Game newGame;
	GameListNode* pHead, *p;
	int entry_int = 0;
	char entry_s[99];


	//��дnewPlayer������
	system("CLS");
	printf("��Ŀ���ƣ�");
	scanf_s("%s", &newGame.name.name, 99);
	rewind(stdin);

	printf("��������(1.����  2.����)��");

	entry_int = 0;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 2);//����һ������,�򷵻�int,����,����0
		switch (entry_int)
		{
		case 0:printf("��������,����������:"); break;
		case 1:strcpy(newGame.type, Tian); break;
		case 2:strcpy(newGame.type, Jing); break;
		}
	}//�������

	printf("�����ص�(1.�ܵ�  2.����  3.��ǹ��  4.��Զ��  5.Ǧ����  6.������)��");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 6);
		switch (entry_int)
		{
		case 0:printf("��������,����������:"); break;
		case 1:strcpy(newGame.place, Runway); break;
		case 2:strcpy(newGame.place, Football); break;
		case 3:strcpy(newGame.place, ShotPut); break;
		case 4:strcpy(newGame.place, LongJump); break;
		case 5:strcpy(newGame.place, Discus); break;
		case 6:strcpy(newGame.place, HighJump); break;
		}
	}

	printf("�·ݣ�");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 12);
		newGame.starttime.month = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}

	printf("���ڣ�");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 31);
		newGame.starttime.date = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}


	printf("��ʼʱ�䣺\n");
	printf("���㣺");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 24);
		newGame.starttime.hour = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}

	printf("���֣�");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 60);
		newGame.starttime.minute = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}

	printf("����ʱ�䣺\n");
	printf("���㣺");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 24);
		newGame.endtime.hour = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}
	printf("���֣�");
	entry_int = 0;
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 60);
		newGame.endtime.minute = entry_int;
		if (entry_int == 0)printf("��������,����������:");
	}
	newGame.number = 0;

	pHead = readGamelist();	//��ȡ�ļ��е�����pHead
	p = pHead;
	if (pHead == NULL) { //���ļ���������,���½�һ������
		newGame.name.id = 1;
		pHead = createpHead(newGame);
	}
	else { //��������,����pHead�����������һ���ڵ�
		while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
			p = p->next;
		}
		newGame.name.id = p->game.name.id + 1;//��id,idΪ�����˳��
		addNode(pHead, newGame);
	}
	saveGamelist(pHead);//��������
	printf("\n\n�������\n");
	system("pause");
}

void addPlayerNode() {
	Player newPlayer;
	PlayerListNode* pHead, *p;
	int entry_int = 0;
	char entry_s[99];


	//��дnewPlayer������
	system("CLS");
	printf("���ƣ�");
	scanf_s("%s", &newPlayer.name.name, 99);
	rewind(stdin);

	printf("����:");//����
	entry_int = 0;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
		if(entry_int==0) printf("��������,����������:");
		else newPlayer.year = entry_int;

	}//�������

	printf("�Ա�(1.��  2.Ů)��");//�Ա�
	entry_int = 0;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 2);//����һ������,�򷵻�int,����,����0
		switch (entry_int)
		{
		case 0:printf("��������,����������:"); break;
		case 1:strcpy(newPlayer.gender, "��"); break;
		case 2:strcpy(newPlayer.gender, "Ů"); break;
		}
	}//�������

	printf("С��ID:");//С��id
	entry_int = 0;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
		if (entry_int == 0) printf("��������,����������:");
		else newPlayer.group_id = entry_int;

	}//�������

	newPlayer.fullscore = 0;
	newPlayer.game_number = 0;


	pHead = readPlayerlist();	//��ȡ�ļ��е�����pHead
	p = pHead;
	if (pHead == NULL) { //���ļ���������,���½�һ������
		newPlayer.name.id = 1;
		pHead = createpHead(newPlayer);
	}
	else { //��������,����pHead�����������һ���ڵ�
		while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
			p = p->next;
		}
		newPlayer.name.id = p->player.name.id + 1;//��id,idΪ�����˳��
		addNode(pHead, newPlayer);
	}
	savePlayerlist(pHead);//��������
	printf("\n\n�������\n");
	system("pause");
}