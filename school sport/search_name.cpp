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
