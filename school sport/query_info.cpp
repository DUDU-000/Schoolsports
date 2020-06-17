#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"

void searchGamelist_name() {//���������¹���,����������ܴ�ҳ���˺ͷ����� , ���漸����һ��

	GameListNode* pHead = readGamelist();
	GameListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99] = {0};
	system("CLS");
	printf("������ؼ��֣�");
	gets_s(entry_s, 99);
	rewind(stdin);
	GameListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->game.name.name, entry_s)) {//strstr���ж���ǰһ���ַ������Ƿ��к�һ���ַ���
			if (i == 0||input==NULL) input = createpHead(p->game);
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
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
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
	x = -1;
	while (x == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 2);
		if (x == -1)printf("��������,����������:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input = NULL;//�������
	Game newGame;//�µĽṹ��
	for (int i = 0; i < list_long; i++, p = p->next) {
		game = p->game;
		if ((strcmp(game.type, "����") == 0 && x == 1) || (strcmp(game.type, "����") == 0 && x == 2)) {
			newGame = game;
			if (i == 0||input==NULL)input = createpHead(newGame);
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
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}

void searchGamelist_time() {
	system("CLS");
	GameListNode* pHead = readGamelist();
	printf("�������ѯ�ڼ���:");
	int x = 0;
	char entry_s[99];
	while (x==0)
	{
		gets_s(entry_s,99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 31);
		if (x == -1)printf("��������,����������:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//�������
	Game newGame;//�µĽṹ��
	for (int i = 0; i < list_long; i++,p= p->next) {
		game = p->game;
		if (x == game.starttime.day) {
			newGame = game;
			if (i == 0||input==NULL)input = createpHead(newGame);
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
			if (swi == -1)printf("��������,����������:");
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
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}

void searchPlayerlist_name() {
	PlayerListNode* pHead = readPlayerlist();
	PlayerListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99] = { 0 };
	system("CLS");
	printf("���������ƣ�");
	gets_s(entry_s, 99);
	rewind(stdin);
	PlayerListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->player.name.name, entry_s)) {//strstr���ж���ǰһ���ַ������Ƿ��к�һ���ַ���
			if (i == 0 || input == NULL) input = createpHead(p->player);
			else addNode(input, p->player);
		}
	}

	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {//��Ҫ������,
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printPlayerlist(input);
		printf("%d.����\n", input_long + 1);//���ӷ���ѡ��
		int swi = 0;
		char entry_s[99];
		while (swi == 0)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {//������Ĳ��Ƿ���ѡ��,����������ϸҳ��
			information_player(input, swi);
		}
	}
}

void searchPlayerlist_group() {
	PlayerListNode* pHead = readPlayerlist();
	PlayerListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99] = { 0 };
	system("CLS");
	printf("������С��ID��");
	
	int entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//С��id��Χ
		if (entry_int == -1) printf("��������,����������:");
	}//�������

	PlayerListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {//���
		if (entry_int==p->player.group_id) {//���id��ͬ.�������������
			if (i == 0 || input == NULL) input = createpHead(p->player);
			else addNode(input, p->player);
		}
	}
	
	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {//��Ҫ������,
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printPlayerlist(input);
		printf("%d.����\n", input_long + 1);//���ӷ���ѡ��
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {//������Ĳ��Ƿ���ѡ��,����������ϸҳ��
			information_player(input, swi);
		}
	}

}

void searchPlayer_all() {
	system("CLS");
	PlayerListNode* input = readPlayerlist();

	if (input == NULL) {
		printf("�Ҳ�����Ŀ\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("������Ŀ:\n");
		printPlayerlist(input);
		printf("%d.����\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_player(input, swi);
		}
	}
}

void searchGroup_name() {
	GroupListNode* pHead = readGrouplist();
	GroupListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_str[99] = {0};
	system("CLS");
	printf("�����뵥λ����:");
	gets_s(entry_str, 99);
	rewind(stdin);
	GroupListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->group.name.name, entry_str)) {
			if (i == 0 || input == NULL)input = createpHead(p->group);
			else addNode(input, p->group);
		}

	}
	if (input == NULL) {
		printf("\n\n\n�Ҳ�������Ŀ\n");
		system("pause");
	}
	else {//��Ҫ������,
		int input_long = longNode(input);
		printf("\n\n\n���������Ŀ:\n");
		printGrouplist(input);
		printf("%d.����\n", input_long + 1);//���ӷ���ѡ��
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {//������Ĳ��Ƿ���ѡ��,����������ϸҳ��
			information_group(input, swi);
		}
	}
}

void searchGroup_all() {
	system("CLS");
	GroupListNode* input = readGrouplist();
	if(input==NULL) {
		printf("�Ҳ���С��\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("����С��:\n");
		printGrouplist(input);
		printf("%d.����\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("��������,����������:");
		}
		if (swi != input_long + 1) {
			information_group(input, swi);
		}
	}
}

void searchGroup_palyer(GroupListNode* p ,int a) {
	Group group = p->group;
	printf("\n�õ�λ�ĳ�Ա:\n");
	for (int i = group.member_number-1; i >=0; i--) {
		printf("%d.", i + 1);
		printf("��ԱID:%-3d", group.memberid[i].id);
		printf("��Ա����:%-9s ", group.memberid[i].name);
		if (a) printf("�÷�:%d", group.point[i]);
		printf("\n");
	}
	system("pause");
}