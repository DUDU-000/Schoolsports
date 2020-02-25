#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
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
	printf("请输入查询日期（号）:");
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
		if (x == game.starttime.date) {
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
		printf("找不到项目\n");
		system("pause");
	}
	else {
		int input_long = longNode(input);
		printf("所有项目:\n");
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



void searchGroup_game(GroupListNode *p) {//单位内的比赛记录搜索
	Group group=p->group;
	system("CLS");
	printf("该单位的比赛记录:\n");
	int i = 0;
	for ( i = 0; i < group.game_number; i++) {//单位全部比赛打印
		printf("%d.", i+1);
		printf("比赛名称:%s 比赛成绩:%f 比赛得分:%d\n", group.score[i].name.name, group.score[i].score, group.score[i].point);
	}
	printf("\n请选择操作:\n");
	printf("1.新增\n2.修改\n3.返回\n");
	int swi = -1;
	char entry_str[99];
	while (swi == -1) {
		gets_s(entry_str, 99);
		swi = entrycheck(entry_str, 1, 3);
		if (swi == -1)printf("输入有误，请重新输入:");
	}

	//以下为比赛记录的功能部分
	switch (swi) {
	case 1: {//添加比赛记录
		system("CLS");
		printf("请输入比赛名称:");
		gets_s(group.score[group.game_number].name.name, 99);
		printf("请输入比赛成绩:");
		scanf_s("%f", &group.score[group.game_number].score);
		printf("请输入比赛得分:");
		scanf_s("%d", &group.score[group.game_number].point);

		if (group.game_number == 0)group.score[0].name.id = 1;
		else { group.score[group.game_number].name.id = group.score[group.game_number - 1].name.id + 1; }
		group.game_number++;
	}break;
	case 2: {//修改比赛记录
		if (group.game_number == 0) {
			printf("无比赛可修改");
			system("pause");
		}
		else {
			printf("请输入比赛序号:");
			int  n= -1;
			char entry_str[99];
			while (n == -1) {
				gets_s(entry_str, 99);//选择第几项比赛
				rewind(stdin);
				n = entrycheck(entry_str, 1, i + 1);
				if (n == -1)printf("输入有误，请重新输入:");
			}
			system("CLS");//打印该比赛
			printf("该比赛名称为:%s\n", group.score[n - 1].name.name);
			printf("该比赛成绩为:%f\n", group.score[n - 1].score);
			printf("该比赛得分为:%d\n", group.score[n - 1].point);
			printf("\n请选择操作:\n1.修改名称\n2.修改成绩\n3.修改得分\n4.删除\n5.返回");
			//比赛记录操作
			int x = -1;
			while (x == -1) {
				gets_s(entry_str, 99);
				rewind(stdin);
				x= entrycheck(entry_str, 1, 5);
				if (x == -1)printf("输入有误，请重新输入:");
			}
			switch (x) {
			case 1: {//修改单项比赛记录的名称
				system("CLS");
				printf("该比赛名称为:%s\n请输入修改内容:", group.score[n - 1].name.name);
				gets_s(group.score[n - 1].name.name, 99);
				rewind(stdin);
				printf("修改成功！修改为:%s", group.score[n - 1].name.name);
				system("pause");
			}break;
			case 2: {//修改单项比赛记录成绩
				system("CLS");
				printf("该比赛成绩为:%f\n请输入修改内容:", group.score[n - 1].score);
				scanf_s("%f", &group.score[n - 1].score);
				printf("修改成功！修改为:%f", group.score[n - 1].score);
				system("pause");
			}break;
			case 3: {//修改单项比赛记录得分
				system("CLS");
				printf("该比赛得分为:%d\n请输入修改内容:", group.score[n - 1].point);
				scanf_s("%f", &group.score[n - 1].point);
				printf("修改成功！修改为:%f", group.score[n - 1].point);
				system("pause");
			}break;
			case 4: {//删除单项比赛记录
				if (group.score[n].name.id) {//最后一项
					group.score[n - 1].name.id = 0;
					memset(group.score[n - 1].name.name, 0, sizeof(group.score[n - 1].name.name));
					group.score[n - 1].point = 0;
					group.score[n - 1].score = 0;
					group.game_number--;
					printf("删除成功！");
					system("pause");
				}
				else {
					for (; n < group.game_number; n++) {
						group.score[n - 1] = group.score[n];
					}
					printf("删除成功！");
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
	printf("该单位的成员:\n");
	for (int i = 0; i < group.member_number; i++) {
		printf("%d.", i + 1);
		printf("成员ID:%d\n", group.memberid[i]);
	}
	printf("\n请选择操作:\n");
	printf("1.新增\n2.修改\n3.返回\n");

	int swi = -1;
	char entry_str[99] = { 0 };
	while (swi == -1) {
		gets_s(entry_str, 99);
		rewind(stdin);
		swi = entrycheck(entry_str, 1, 3);
		if (swi == -1)printf("输入有误，请重新输入:");
	}

	switch (swi) {
	case 1: {//新增成员ID
		system("CLS");
		printf("请输入新增成员ID:");
		int newMemberid;
		scanf_s("%d", &newMemberid);
		if (group.member_number == 0)group.memberid[0] = newMemberid;
		else
		{
			group.memberid[group.member_number] = newMemberid;
		}
		printf("新增成功！");
		system("pause");

	}break;
	case 2: {
		if (group.member_number == 0) {
			printf("无成员可修改");
			system("pause");
		}
		else
		{
			printf("请输入修改的成员序号:");
			int n;
			scanf_s("%d", &n);
			system("CLS");
			printf("该成员ID为:%d\n请输入修改内容", group.memberid[n - 1]);
			scanf_s("%d", &group.memberid[n - 1]);
			printf("修改成功！修改该成员ID为:%d", group.memberid[n - 1]);
			system("pause");
		}break;
	case 3:break;
	}
	}

}