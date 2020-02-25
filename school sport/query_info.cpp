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
	printf("�������ѯ���ڣ��ţ�:");
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
		if (x == game.starttime.date) {
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
		printf("�Ҳ�����Ŀ\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("������Ŀ:\n");
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



void searchGroup_game(GroupListNode *p) {//��λ�ڵı�����¼����
	Group group=p->group;
	system("CLS");
	printf("�õ�λ�ı�����¼:\n");
	int i = 0;
	for ( i = 0; i < group.game_number; i++) {//��λȫ��������ӡ
		printf("%d.", i+1);
		printf("��������:%s �����ɼ�:%f �����÷�:%d\n", group.score[i].name.name, group.score[i].score, group.score[i].point);
	}
	printf("\n��ѡ�����:\n");
	printf("1.����\n2.�޸�\n3.����\n");
	int swi = -1;
	char entry_str[99];
	while (swi == -1) {
		gets_s(entry_str, 99);
		swi = entrycheck(entry_str, 1, 3);
		if (swi == -1)printf("������������������:");
	}

	//����Ϊ������¼�Ĺ��ܲ���
	switch (swi) {
	case 1: {//��ӱ�����¼
		system("CLS");
		printf("�������������:");
		gets_s(group.score[group.game_number].name.name, 99);
		printf("����������ɼ�:");
		scanf_s("%f", &group.score[group.game_number].score);
		printf("����������÷�:");
		scanf_s("%d", &group.score[group.game_number].point);

		if (group.game_number == 0)group.score[0].name.id = 1;
		else { group.score[group.game_number].name.id = group.score[group.game_number - 1].name.id + 1; }
		group.game_number++;
	}break;
	case 2: {//�޸ı�����¼
		if (group.game_number == 0) {
			printf("�ޱ������޸�");
			system("pause");
		}
		else {
			printf("������������:");
			int  n= -1;
			char entry_str[99];
			while (n == -1) {
				gets_s(entry_str, 99);//ѡ��ڼ������
				rewind(stdin);
				n = entrycheck(entry_str, 1, i + 1);
				if (n == -1)printf("������������������:");
			}
			system("CLS");//��ӡ�ñ���
			printf("�ñ�������Ϊ:%s\n", group.score[n - 1].name.name);
			printf("�ñ����ɼ�Ϊ:%f\n", group.score[n - 1].score);
			printf("�ñ����÷�Ϊ:%d\n", group.score[n - 1].point);
			printf("\n��ѡ�����:\n1.�޸�����\n2.�޸ĳɼ�\n3.�޸ĵ÷�\n4.ɾ��\n5.����");
			//������¼����
			int x = -1;
			while (x == -1) {
				gets_s(entry_str, 99);
				rewind(stdin);
				x= entrycheck(entry_str, 1, 5);
				if (x == -1)printf("������������������:");
			}
			switch (x) {
			case 1: {//�޸ĵ��������¼������
				system("CLS");
				printf("�ñ�������Ϊ:%s\n�������޸�����:", group.score[n - 1].name.name);
				gets_s(group.score[n - 1].name.name, 99);
				rewind(stdin);
				printf("�޸ĳɹ����޸�Ϊ:%s", group.score[n - 1].name.name);
				system("pause");
			}break;
			case 2: {//�޸ĵ��������¼�ɼ�
				system("CLS");
				printf("�ñ����ɼ�Ϊ:%f\n�������޸�����:", group.score[n - 1].score);
				scanf_s("%f", &group.score[n - 1].score);
				printf("�޸ĳɹ����޸�Ϊ:%f", group.score[n - 1].score);
				system("pause");
			}break;
			case 3: {//�޸ĵ��������¼�÷�
				system("CLS");
				printf("�ñ����÷�Ϊ:%d\n�������޸�����:", group.score[n - 1].point);
				scanf_s("%f", &group.score[n - 1].point);
				printf("�޸ĳɹ����޸�Ϊ:%f", group.score[n - 1].point);
				system("pause");
			}break;
			case 4: {//ɾ�����������¼
				if (group.score[n].name.id) {//���һ��
					group.score[n - 1].name.id = 0;
					memset(group.score[n - 1].name.name, 0, sizeof(group.score[n - 1].name.name));
					group.score[n - 1].point = 0;
					group.score[n - 1].score = 0;
					group.game_number--;
					printf("ɾ���ɹ���");
					system("pause");
				}
				else {
					for (; n < group.game_number; n++) {
						group.score[n - 1] = group.score[n];
					}
					printf("ɾ���ɹ���");
					system("pause");
				}

			}break;
			case 5: query_group_menu; break;
			}

		}

	}
	}
	p->group = group;
}

void searchGroup_palyer(GroupListNode* p) {
	Group group = p->group;
	printf("�õ�λ�ĳ�Ա:\n");
	for (int i = 0; i < group.member_number; i++) {
		printf("%d.", i + 1);
		printf("��ԱID:%d\n", group.memberid[i]);
	}
	printf("\n��ѡ�����:\n");
	printf("1.����\n2.�޸�\n3.����\n");

	int swi = -1;
	char entry_str[99] = { 0 };
	while (swi == -1) {
		gets_s(entry_str, 99);
		rewind(stdin);
		swi = entrycheck(entry_str, 1, 3);
		if (swi == -1)printf("������������������:");
	}

	switch (swi) {
	case 1: {//������ԱID
		system("CLS");
		printf("������������ԱID:");
		int newMemberid;
		scanf_s("%d", &newMemberid);
		if (group.member_number == 0)group.memberid[0] = newMemberid;
		else
		{
			group.memberid[group.member_number] = newMemberid;
		}
		printf("�����ɹ���");
		system("pause");

	}break;
	case 2: {
		if (group.member_number == 0) {
			printf("�޳�Ա���޸�");
			system("pause");
		}
		else
		{
			printf("�������޸ĵĳ�Ա���:");
			int n;
			scanf_s("%d", &n);
			system("CLS");
			printf("�ó�ԱIDΪ:%d\n�������޸�����", group.memberid[n - 1]);
			scanf_s("%d", &group.memberid[n - 1]);
			printf("�޸ĳɹ����޸ĸó�ԱIDΪ:%d", group.memberid[n - 1]);
			system("pause");
		}break;
	case 3:break;
	}
	}

}