#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"

void revise_info(GameListNode* p,Game game) {
	system("CLS");
	GameListNode* pHead = readGamelist();
	p = pHead;
	while (p->game.name.id != game.name.id) {
		p = p->next;
	}
	printf("1.����\n");
	printf("2.����\n");
	printf("3.�ص�\n");
	printf("4.��ʼʱ��\n");
	printf("5.����ʱ��\n");
	printf("6.����\n");
	
	int x = 0;
	char entry_s[99];
	while (x == 0) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 6);
		if (x == 0)printf("��������,����������:");
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
		int n = 0;
		char place_selection[99];
		while (n == 0) {
			gets_s(place_selection, 99);
			rewind(stdin);
			n = entrycheck(place_selection, 1, 6);
			if (n == 0)printf("��������,����������:");
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
		int month=0, date=0, hour=0, minute=0;
		while (month == 0) {//��
			printf("�£�");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == 0)printf("����������������룺");
		}
		while (date == 0) {//��
			printf("�գ�");
			gets_s(date_s, 99);
			if((month<=7&&month%2!=0)||(month>=8&&month%2==0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month==2)date = entrycheck(date_s, 1, 29);
			if (date == 0)printf("����������������룺");
		}
		while (hour == 0) {//ʱ
			printf("���㣺");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == 0)printf("����������������룺");
		}
		while (minute == 0) {//��
			printf("���㣺");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == 0)printf("����������������룺");
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
		int month = 0, date = 0, hour = 0, minute = 0;
		while (month == 0) {//��
			printf("�£�");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == 0)printf("����������������룺");
		}
		while (date == 0) {//��
			printf("�գ�");
			gets_s(date_s, 99);
			if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month == 2)date = entrycheck(date_s, 1, 29);
			if (date == 0)printf("����������������룺");
		}
		while (hour == 0) {//ʱ
			printf("���㣺");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == 0)printf("����������������룺");
		}
		while (minute == 0) {//��
			printf("���㣺");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == 0)printf("����������������룺");
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