#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"

void searchGamelist_type(GameListNode* pHead)
{
	printf("请选择比赛类型(1.田赛 2.竞赛):");
	int x;
	scanf_s("%d", &x);
	int list_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	GameListNode* input;//输出链表
	Game newGame;//新的结构体
	if (x == 1) {
		for (int i = 0; i < list_long; i++, p->next) {
			game = p->game;
			if (strcmp(game.type, "田赛") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	else{
		for (int i = 0; i < list_long; i++, p->next) {
			game = p->game;
			if (strcmp(game.type, "竞赛") == 0) {
				newGame = game;
				if (i == 0)input = createpHead(newGame);
				else addNode(input, newGame);
			}
		}
	}
	printGamelist(input);
}