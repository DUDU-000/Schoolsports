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
	printf("请输入关键字：");
	scanf_s("%s", entry_s, 99);

	GameListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->game.name.name, entry_s)) {//strstr能判断在前一个字符串中是否有后一个字符串
			if (i == 0) input = createpHead(p->game);
			else addNode(input, p->game);
		}
	}

	if (input == NULL)
		printf("找不到该项目");
	else {
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
	}
}

void searchGamelist_type()
{
	system("CLS");
	GameListNode* pHead = readGamelist();

	printf("请选择比赛类型(1.田赛 2.竞赛):");
	int x;
	char entry_s[99];
	x = 0;
	while (x == 0)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 2);
		if (x == 0)printf("输入有误,请重新输入:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//输出链表
	Game newGame;//新的结构体
	if (x == 1) {
		for (int i = 0; i < list_long; i++, p=p->next) {
			game = p->game;
			if (strcmp(game.type, "田赛") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	else {
		for (int i = 0; i < list_long; i++, p=p->next) {
			game = p->game;
			if (strcmp(game.type, "竞赛") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	if (input == NULL)
		printf("找不到该项目");
	else {
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
	}
}

void searchGamelist_time() {
	system("CLS");
	GameListNode* pHead = readGamelist();
	printf("请输入查询日期（号）:");
	int x;
	char entry_s[99];
	x = 0;
	while (x==0)
	{
		gets_s(entry_s,99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 31);
		if (x == 0)printf("输入有误,请重新输入:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//输出链表
	Game newGame;//新的结构体
	for (int i = 0; i < list_long; i++,p= p->next) {
		game = p->game;
		if (x == game.starttime.date) {
			newGame = game;
			if (i == 0)input = createpHead(newGame);
			else addNode(input, newGame);
		}
	}
	if (input == NULL)
		printf("找不到该项目");
	else {
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
	}
}