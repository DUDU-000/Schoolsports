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
