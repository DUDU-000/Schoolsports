#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"linked_list.h"
#include"activity.h"


void addGameNode() {

	Game newGame;
	GameListNode* pHead, *p;
	int entry_int = -1;
	char entry_s[99];


	//��дnewPlayer������
	system("CLS");
	printf("��Ŀ���ƣ�");
	scanf_s("%s", &newGame.name.name, 99);
	rewind(stdin);

	printf("��������(1.����  2.����)��");

	entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 2);//����һ������,�򷵻�int,����,����0
		switch (entry_int)
		{
		case -1:printf("��������,����������:"); break;
		case 1:strcpy(newGame.type, Tian); break;
		case 2:strcpy(newGame.type, Jing); break;
		}
	}//�������

	printf("�����ص�(1.�ܵ�  2.����  3.��Զ��  4.Ǧ����  5.������)��");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 5);
		switch (entry_int)
		{
		case -1:printf("��������,����������:"); break;
		case 1:strcpy(newGame.place, Runway); break;
		case 2:strcpy(newGame.place, Football); break;
		case 3:strcpy(newGame.place, LongJump); break;
		case 4:strcpy(newGame.place, Discus); break;
		case 5:strcpy(newGame.place, HighJump); break;
		}
	}

	printf("�·ݣ�");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 12);
		newGame.starttime.month = entry_int;
		if (entry_int == -1)printf("��������,����������:");
	}

	printf("���ڣ�");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 31);
		newGame.starttime.date = entry_int;
		if (entry_int == -1)printf("��������,����������:");
	}


	printf("��ʼʱ�䣺\n");
	printf("���㣺");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 24);
		newGame.starttime.hour = entry_int;
		if (entry_int == -1)printf("��������,����������:");
	}

	printf("���֣�");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 60);
		newGame.starttime.minute = entry_int;
		if (entry_int == -1)printf("��������,����������:");
	}

	printf("����ʱ�䣺\n");
	printf("���㣺");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 24);
		newGame.endtime.hour = entry_int;
		if (entry_int == -1)printf("��������,����������:");
	}
	printf("���֣�");
	entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 0, 60);
		newGame.endtime.minute = entry_int;
		if (entry_int == -1)printf("��������,����������:");
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
	int entry_int = -1;
	char entry_s[99];


	//��дnewPlayer������
	system("CLS");
	printf("���ƣ�");
	scanf_s("%s", &newPlayer.name.name, 99);
	rewind(stdin);

	printf("����:");//����
	entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
		if(entry_int==-1) printf("��������,����������:");
		else newPlayer.year = entry_int;

	}//�������

	printf("�Ա�(1.��  2.Ů)��");//�Ա�
	entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 2);//����һ������,�򷵻�int,����,����0
		switch (entry_int)
		{
		case -1:printf("��������,����������:"); break;
		case 1:strcpy(newPlayer.gender, "��"); break;
		case 2:strcpy(newPlayer.gender, "Ů"); break;
		}
	}//�������

	printf("С��ID:");//С��id
	entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
		if (entry_int == -1) printf("��������,����������:");
		else {
			GroupListNode *GHead = readGrouplist();
			GroupListNode *g = GHead;
			while (g->group.name.id!= entry_int){
				g = g->next;
				if (g == NULL) {
					printf("��С�鲻����,����������:");
					entry_int = -1;
					break;
				}
			}
			if (entry_int == -1) continue;
			newPlayer.group_id = entry_int;
		}

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

	GroupListNode *PHead = readGrouplist();
	GroupListNode *g = PHead;
	while (g->group.name.id != newPlayer.group_id) {
		g = g->next;
		}
	g->group.memberid[g->group.member_number] = newPlayer.name;
	g->group.member_number++;
	saveGrouplist(PHead);

	printf("\n\n�������\n");
	system("pause");
}

void addGroupNode() {
	Group newgroup;
	GroupListNode* pHead, * p;
	int entry_int = -1;
	char entry_s[99];

	//��дnewPlayer������
	system("CLS");
	printf("��λ����:");
	gets_s(newgroup.name.name, 99);
	rewind(stdin);
	/*for (int i = 0; i < newgroup.member_number; i++) {//���������������
		printf("��%d���˶�Ա��ID:", i + 1);
		scanf_s("%d", &newgroup.memberid[i]);
	}*/
	newgroup.member_number = 0;
	newgroup.fullscore = 0;
	/*for (int i = 0; i < newgroup.game_number; i++) {//������¼�����������
		newgroup.score->name.id = i + 1;//ID
		printf("��%d���������:",i+1);//����
		gets_s(newgroup.score->name.name, 99);
		printf("��%d������ɼ�:", i + 1);
		scanf_s("%f", &newgroup.score->score);
		printf("��%d������÷�:", i + 1);
		scanf_s("%d", &newgroup.score->point);
	}*/

	pHead = readGrouplist();
	p = pHead;
	if (pHead == NULL) { 
		newgroup.name.id = 1;
		pHead = createpHead(newgroup);

	}
	else {
		//��������,����pHead�����������һ���ڵ�
		while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
			p = p->next;
		}
		newgroup.name.id = p->group.name.id + 1;
		addNode(pHead, newgroup);
	}
	saveGrouplist(pHead);
	printf("\n\n�������\n");
	system("pause");
}