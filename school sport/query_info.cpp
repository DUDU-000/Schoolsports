#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"

void searchGamelist_name() {

	GameListNode* pHead = readGamelist();
	GameListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99];
	system("CLS");
	printf("������ؼ��֣�");
	scanf_s("%s", entry_s, 99);

	GameListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->game.name.name, entry_s)) {//strstr���ж���ǰһ���ַ������Ƿ��к�һ���ַ���
			if (i == 0) input = createpHead(p->game);
			else addNode(input, p->game);
		}
	}

	if (input == NULL)
		printf("�Ҳ�������Ŀ");
	else {
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
	}
}

void searchGamelist_type()
{
	system("CLS");
	GameListNode* pHead = readGamelist();

	printf("��ѡ���������(1.���� 2.����):");
	int x;
	char entry_s[99];
	x = 0;
	while (x == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 2);
		if (x == 0)printf("��������,����������:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//�������
	Game newGame;//�µĽṹ��
	if (x == 1) {
		for (int i = 0; i < list_long; i++, p=p->next) {
			game = p->game;
			if (strcmp(game.type, "����") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	else {
		for (int i = 0; i < list_long; i++, p=p->next) {
			game = p->game;
			if (strcmp(game.type, "����") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	if (input == NULL)
		printf("�Ҳ�������Ŀ");
	else {
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
	}
}

void searchGamelist_time() {
	system("CLS");
	GameListNode* pHead = readGamelist();
	printf("�������ѯ���ڣ��ţ�:");
	int x;
	char entry_s[99];
	x = 0;
	while (x==0)
	{
		gets_s(entry_s,99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 31);
		if (x == 0)printf("��������,����������:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//�������
	Game newGame;//�µĽṹ��
	for (int i = 0; i < list_long; i++,p= p->next) {
		game = p->game;
		if (x == game.starttime.date) {
			newGame = game;
			if (i == 0)input = createpHead(newGame);
			else addNode(input, newGame);
		}
	}
	if (input == NULL)
		printf("�Ҳ�������Ŀ");
	else {
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
	}
}