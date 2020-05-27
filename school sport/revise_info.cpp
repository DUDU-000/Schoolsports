#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"
#include"menu.h"

void reviseGame(Game game) {
	system("CLS");
	GameListNode* pHead = readGamelist();
	GameListNode* p = pHead;

	while (p->game.name.id != game.name.id) {
		p = p->next;
	}

	printf("��Ŀ��Ϣ:\n");//��ӡ��Ŀ������Ϣ
	printf("����:%s\n", game.name.name/*����*/);
	printf("����:%s\n", game.type/*����*/);
	printf("�ص�:%s\n", game.place/*�ص�*/);
	printf("����:%d\n", game.number/*��������*/);
	printf("ʱ��:%d��%d��%d : %d-%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/, game.endtime.hour, game.endtime.minute/*����ʱ��*/);
	printf("������Ա:\n");
	if (game.playerid[0].id == NULL || game.playerid[0].id <= 0) printf("��");
	else
		for (int j = 0; j < game.number; j++) {
			printf("ID:%d ", game.playerid[j].id);//������Աid
			printf("����:%s    ", game.playerid[j].name);//������Աid
			if ((j + 1) % 5 == 0) printf("\n");
		}
	printf("\n\n\n");

	printf("�޸�����:\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.�ص�\n");
	printf("4.��ʼʱ��\n");
	printf("5.����ʱ��\n");
	printf("6.����\n");
	
	int x = -1;
	char entry_s[99];
	while (x == -1) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 6);
		if (x == -1)printf("��������,����������:");
	}
	switch (x)
	{
	case 1: {//�޸�����
		system("CLS");
		printf("��ǰǰѡ����Ŀ������Ϊ��%s\n�������޸����ݣ�", p->game.name.name);
		gets_s(p->game.name.name, 99);
		printf("�޸ĳɹ����޸�����Ϊ��%s\n",p->game.name.name);
		saveGamelist(pHead);
		system("pause");
	}break;
	case 2: {//�޸�����
		system("CLS");
		printf("��ǰѡ����Ŀ������Ϊ��%s\n�������޸�����(1.���� 2.����)��", p->game.type);
		int i = 0;
		while (i == 0) {//�ж�����
			int x;
			scanf_s("%d", &x);
			if (x == 1) {
				i = 1;
				strcpy(p->game.type, Tian);
			}
			else if (x == 2) {
				i = 1;
				strcpy(p->game.type, Jing);
			}
			else printf("����������������룺");
		}
		saveGamelist(pHead);
		printf("�޸ĳɹ����޸�����Ϊ��%s\n",p->game.type);
		system("pause");
	}break;
	case 3: {//�޸ĵص�
		system("CLS");
		printf("��ǰѡ����Ŀ�ĵص�Ϊ��%s\n�������޸�����(1.�ܵ�  2.����  3.��ǹ��  4.��Զ��  5.Ǧ����  6.������)��", p->game.place);
		int n = -1;
		char place_selection[99];
		while (n == -1) {
			gets_s(place_selection, 99);
			rewind(stdin);
			n = entrycheck(place_selection, 1, 6);
			if (n == -1)printf("��������,����������:");
		}
		switch (n)
		{
		case 1:strcpy(p->game.place, Runway); break;
		case 2:strcpy(p->game.place, Football); break;
		case 3:strcpy(p->game.place, ShotPut); break;
		case 4:strcpy(p->game.place, LongJump); break;
		case 5:strcpy(p->game.place, Discus); break;
		case 6:strcpy(p->game.place, HighJump); break;
		}
		saveGamelist(pHead);
		printf("�޸ĳɹ�!�޸ĵص�Ϊ��%s\n",p->game.place);
		system("pause");
	}break;
	case 4: {//��ʼʱ��
		system("CLS");
		printf("Ŀǰѡ����Ŀ�Ŀ�ʼʱ��Ϊ��%d��%d��%d : %d\n�������޸����ݣ�\n", p->game.starttime.month, p->game.starttime.date, p->game.starttime.hour, p->game.starttime.minute);
		char month_s[99], date_s[99], hour_s[99], minute_s[99];
		int month= -1, date= -1, hour= -1, minute= -1;
		while (month == -1) {//��
			printf("�£�");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == -1)printf("����������������룺");
		}
		while (date == -1) {//��
			printf("�գ�");
			gets_s(date_s, 99);
			if((month<=7&&month%2!=0)||(month>=8&&month%2==0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month==2)date = entrycheck(date_s, 1, 29);
			if (date == -1)printf("����������������룺");
		}
		while (hour == -1) {//ʱ
			printf("���㣺");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == -1)printf("����������������룺");
		}
		while (minute == -1) {//��
			printf("���㣺");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == -1)printf("����������������룺");
		}
		p->game.starttime.month = month;
		p->game.starttime.date = date;
		p->game.starttime.hour = hour;
		p->game.starttime.minute = minute;
		saveGamelist(pHead);
		printf("�޸ĳɹ�\nĿǰѡ����Ŀ�Ŀ�ʼʱ��Ϊ��%d��%d��%d : %d\n", p->game.starttime.month, p->game.starttime.date, p->game.starttime.hour, p->game.starttime.minute);
		system("pause");
	}break;
	case 5: {//����ʱ��
		system("CLS");
		printf("Ŀǰѡ����Ŀ�Ľ���ʱ��Ϊ��%d��%d��%d : %d\n�������޸����ݣ�\n", p->game.starttime.month, p->game.starttime.date, p->game.endtime.hour, p->game.endtime.minute);
		char month_s[99], date_s[99], hour_s[99], minute_s[99];
		int month = -1, date = -1, hour = -1, minute = -1;
		while (month == -1) {//��
			printf("�£�");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == -1)printf("����������������룺");
		}
		while (date == -1) {//��
			printf("�գ�");
			gets_s(date_s, 99);
			if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month == 2)date = entrycheck(date_s, 1, 29);
			if (date == -1)printf("����������������룺");
		}
		while (hour == -1) {//ʱ
			printf("���㣺");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == -1)printf("����������������룺");
		}
		while (minute == -1) {//��
			printf("���㣺");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == -1)printf("����������������룺");
		}
		p->game.starttime.month = month;
		p->game.starttime.date = date;
		p->game.endtime.hour = hour;
		p->game.endtime.minute = minute;
		saveGamelist(pHead);
		printf("�޸ĳɹ�\nĿǰѡ����Ŀ�Ŀ�ʼʱ��Ϊ��%d��%d��%d : %d\n", p->game.starttime.month, p->game.starttime.date, p->game.endtime.hour, p->game.endtime.minute);
		system("pause");
	}break;
	case 6: query_game_menu(); break;
	}

}

void revisePlayer(Player player) {
	system("CLS");
	PlayerListNode* pHead = readPlayerlist();
	PlayerListNode* p = pHead;

	while (p->player.name.id != player.name.id) {
		p = p->next;
	}

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
			printf("��Ŀ����:%s ", player.score[j].name.name);//��Ŀ����
			printf("��Ŀ�ɼ�:%f ", player.score[j].score);//��Ŀ�ɼ�
			printf("��Ŀ�÷�:%d \n", player.score[j].point);//��Ŀ�ɼ�
		}
	printf("\n\n\n");

	printf("�޸�����:\n");
	printf("1.����\n");
	printf("2.�Ա�\n");
	printf("3.����\n");
	printf("4.С��\n");
	printf("5.����\n");

	int x = -1;
	char entry_s[99];
	while (x == -1) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 5);
		if (x == -1)printf("��������,����������:");
	}
	switch (x)
	{
	case 1: {//�޸�����
		system("CLS");
		printf("��ǰǰѡ���˶�Ա������Ϊ��%s\n", p->player.name.name);
		printf("����:");
		gets_s(p->player.name.name, 99);
		printf("�޸ĳɹ����޸�����Ϊ��%s\n", p->player.name.name);
		system("pause");
	}break;
	case 2: {
		system("CLS");
		printf("��ǰǰѡ���˶�Ա���Ա�Ϊ��%s\n", p->player.gender);

		printf("�Ա�(1.��  2.Ů)��");//�Ա�
		int entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 2);//����һ������,�򷵻�int,����,����0
			switch (entry_int)
			{
			case -1:printf("��������,����������:"); break;
			case 1:strcpy(p->player.gender, "��"); break;
			case 2:strcpy(p->player.gender, "Ů"); break;
			}
		}//�������
		
		printf("�޸ĳɹ����޸��Ա�Ϊ��%s\n", p->player.gender);
		system("pause");
	}break;
	case 3: {
		system("CLS");
		printf("��ǰǰѡ���˶�Ա������Ϊ��%d\n", p->player.year);

		printf("����:");
		int entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
			if (entry_int == -1) printf("��������,����������:");
			else p->player.year = entry_int;

		}//�������

		printf("�޸ĳɹ����޸�����Ϊ��%d\n", p->player.year);
		system("pause");
	}break;
	case 4: {
		system("CLS");
		printf("��ǰǰѡ���˶�Ա��С��IDΪ��%d\n", p->player.group_id);

		printf("С��ID:");
		int entry_int = -1;//��ʼ�������Ƿ�������,�Ҹ���һ��entrycheck,������һ��char����
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 99);//����һ������,�򷵻�int,����,����0
			if (entry_int == -1) printf("��������,����������:");
			else p->player.year = entry_int;

		}//�������

		printf("�޸ĳɹ����޸�����Ϊ��%d\n", p->player.group_id);
		system("pause");
	}break;
	case 5: query_player_menu(); break;
	}
	savePlayerlist(pHead);

}

void reviseGroup(Group group) {
	GroupListNode* pHead = readGrouplist();
	GroupListNode* p = pHead;
	while (p->group.name.id!=group.name.id)
	{
		p = p->next;
	}
	printf("�޸�����Ϊ:");
	gets_s(p->group.name.name, 99);
	rewind(stdin);
	printf("�޸ĳɹ����޸�����Ϊ��%s\n",p->group.name.name);
	system("pause");
	saveGrouplist(pHead);


}