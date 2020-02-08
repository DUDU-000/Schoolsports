#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"

void searchGamelist_name() {//���������¹���,����������ܴ�ҳ���˺ͷ����� , ���漸����һ��

	GameListNode* pHead = readGamelist();
	GameListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99];
	system("CLS");
	printf("������ؼ��֣�");
	scanf_s("%s", entry_s, 99);
	rewind(stdin);
	GameListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->game.name.name, entry_s)) {//strstr���ж���ǰһ���ַ������Ƿ��к�һ���ַ���
			if (i == 0) input = createpHead(p->game);
			else addNode(input, p->game);
		}
	}
	
	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {//��Ҫ������,
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
		printf("%d.����\n", input_long + 1);//���ӷ���ѡ��
		int swi = 0;
		char entry_s[99];
		while (swi == 0)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == 0)printf("��������,����������:");
		}
		if (swi != input_long + 1) {//������Ĳ��Ƿ���ѡ��,����������ϸҳ��
			information_game(input, swi);
		}
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
	GameListNode* input = NULL;//�������
	Game newGame;//�µĽṹ��
	for (int i = 0; i < list_long; i++, p = p->next) {
		game = p->game;
		if ((strcmp(game.type, "����") == 0 && x == 1) || (strcmp(game.type, "����") == 0 && x == 0)) {
			newGame = game;
			if (i == 0)input = createpHead(newGame);
			else addNode(input, newGame);
		}
	}

	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
		printf("%d.����\n", input_long + 1);
		int swi = 0;
		char entry_s[99];
		while (swi == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == 0)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}

void searchGamelist_time() {
	system("CLS");
	GameListNode* pHead = readGamelist();
	printf("�������ѯ���ڣ��ţ�:");
	int x = 0;
	char entry_s[99];
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

	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printGamelist(input);
		printf("%d.����\n", input_long + 1);
		int swi = 0;
		char entry_s[99];
		while (swi == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == 0)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}

void searchGamelist_all(){
	system("CLS");
	GameListNode* input = readGamelist();

	if (input == NULL) {
		printf("�Ҳ�����Ŀ\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("������Ŀ:\n");
		printGamelist(input);
		printf("%d.����\n", input_long + 1);
		int swi = 0;
		char entry_s[99];
		while (swi == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == 0)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}