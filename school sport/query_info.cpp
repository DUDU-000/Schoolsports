#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"

void searchGamelist_name() {//我修缮了下功能,有输入检测和能打开页面了和返回了 , 下面几个都一样

	GameListNode* pHead = readGamelist();
	GameListNode* input = NULL;
	int line_long = longNode(pHead);
	char entry_s[99] = {0};
	system("CLS");
	printf("请输入关键字：");
	gets_s(entry_s, 99);
	rewind(stdin);
	GameListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->game.name.name, entry_s)) {//strstr能判断在前一个字符串中是否有后一个字符串
			if (i == 0||input==NULL) input = createpHead(p->game);
			else addNode(input, p->game);
		}
	}
	
	if (input == NULL) {
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {//主要是这里,
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
		printf("%d.返回\n", input_long + 1);//增加返回选项
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//输入检测
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {//如果按的不是返回选项,则进入相关详细页面
			information_game(input, swi);
		}
	}
}

void searchGamelist_type()
{
	system("CLS");
	GameListNode* pHead = readGamelist();

	printf("请选择比赛类型(1.田赛 2.竞赛):");
	int x;
	char entry_s[99];
	x = -1;
	while (x == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 2);
		if (x == -1)printf("输入有误,请重新输入:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input = NULL;//输出链表
	Game newGame;//新的结构体
	for (int i = 0; i < list_long; i++, p = p->next) {
		game = p->game;
		if ((strcmp(game.type, "田赛") == 0 && x == 1) || (strcmp(game.type, "竞赛") == 0 && x == 2)) {
			newGame = game;
			if (i == 0||input==NULL)input = createpHead(newGame);
			else addNode(input, newGame);
		}
	}

	if (input == NULL) {
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
		printf("%d.返回\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {
			information_game(input, swi);
		}
	}
}

void searchGamelist_time() {
	system("CLS");
	GameListNode* pHead = readGamelist();
	printf("请输入查询第几天:");
	int x = 0;
	char entry_s[99];
	while (x==0)
	{
		gets_s(entry_s,99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 31);
		if (x == -1)printf("输入有误,请重新输入:");
	}

	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input=NULL;//输出链表
	Game newGame;//新的结构体
	for (int i = 0; i < list_long; i++,p= p->next) {
		game = p->game;
		if (x == game.starttime.day) {
			newGame = game;
			if (i == 0||input==NULL)input = createpHead(newGame);
			else addNode(input, newGame);
		}
	}

	if (input == NULL) {
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printGamelist(input);
		printf("%d.返回\n", input_long + 1);
		int swi = 0;
		char entry_s[99];
		while (swi == 0)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
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
		printf("找不到项目\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("所有项目:\n");
		printGamelist(input);
		printf("%d.返回\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
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
	printf("请输入名称：");
	gets_s(entry_s, 99);
	rewind(stdin);
	PlayerListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {
		if (strstr(p->player.name.name, entry_s)) {//strstr能判断在前一个字符串中是否有后一个字符串
			if (i == 0 || input == NULL) input = createpHead(p->player);
			else addNode(input, p->player);
		}
	}

	if (input == NULL) {
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {//主要是这里,
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printPlayerlist(input);
		printf("%d.返回\n", input_long + 1);//增加返回选项
		int swi = 0;
		char entry_s[99];
		while (swi == 0)//输入检测
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {//如果按的不是返回选项,则进入相关详细页面
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
	printf("请输入小组ID：");
	
	int entry_int = -1;
	while (entry_int == -1)
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		entry_int = entrycheck(entry_s, 1, 99);//小组id范围
		if (entry_int == -1) printf("输入有误,请重新输入:");
	}//结束检测

	PlayerListNode* p = pHead;
	for (int i = 0; i < line_long; i++, p = p->next) {//检测
		if (entry_int==p->player.group_id) {//如果id相同.则放入新链表中
			if (i == 0 || input == NULL) input = createpHead(p->player);
			else addNode(input, p->player);
		}
	}
	
	if (input == NULL) {
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {//主要是这里,
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printPlayerlist(input);
		printf("%d.返回\n", input_long + 1);//增加返回选项
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//输入检测
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {//如果按的不是返回选项,则进入相关详细页面
			information_player(input, swi);
		}
	}

}

void searchPlayer_all() {
	system("CLS");
	PlayerListNode* input = readPlayerlist();

	if (input == NULL) {
		printf("找不到项目\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("所有项目:\n");
		printPlayerlist(input);
		printf("%d.返回\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
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
	printf("请输入单位名称:");
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
		printf("\n\n\n找不到该项目\n");
		system("pause");
	}
	else {//主要是这里,
		int input_long = longNode(input);
		printf("\n\n\n查得以下项目:\n");
		printGrouplist(input);
		printf("%d.返回\n", input_long + 1);//增加返回选项
		int swi = -1;
		char entry_s[99];
		while (swi == -1)//输入检测
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {//如果按的不是返回选项,则进入相关详细页面
			information_group(input, swi);
		}
	}
}

void searchGroup_all() {
	system("CLS");
	GroupListNode* input = readGrouplist();
	if(input==NULL) {
		printf("找不到小组\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("所有小组:\n");
		printGrouplist(input);
		printf("%d.返回\n", input_long + 1);
		int swi = -1;
		char entry_s[99];
		while (swi == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			swi = entrycheck(entry_s, 1, input_long + 1);
			if (swi == -1)printf("输入有误,请重新输入:");
		}
		if (swi != input_long + 1) {
			information_group(input, swi);
		}
	}
}

void searchGroup_palyer(GroupListNode* p ,int a) {
	Group group = p->group;
	printf("\n该单位的成员:\n");
	for (int i = group.member_number-1; i >=0; i--) {
		printf("%d.", i + 1);
		printf("成员ID:%-3d", group.memberid[i].id);
		printf("成员姓名:%-9s ", group.memberid[i].name);
		if (a) printf("得分:%d", group.point[i]);
		printf("\n");
	}
	system("pause");
}