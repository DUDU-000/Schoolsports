#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"
#include "score_entry.h"




void game_score_entry(Game game) {
	printf("\n\n");
	printf("成绩录入\n");
	printf("田赛输入米, 竞赛输入秒\n");

	PlayerListNode *pHead_player = readPlayerlist();
	double *score = (double *)malloc(sizeof(double)*game.number);

	for (int j = 0; j < game.number; j++) {
		printf("第%d个人: ID:%d ", j+1,game.playerid[j].id);//报名人员id
		printf("名称:%s \n", game.playerid[j].name);//报名人员名称

		PlayerListNode *p_player = pHead_player;
		while (p_player->player.name.id != game.playerid[j].id) {//找到该运动员
			p_player = p_player->next;
		}
		int i=0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}
		printf("成绩(秒/米):");
		scanf("%d", &p_player->player.score[i].score);
	}
	savePlayerlist(pHead_player);

	printf("成绩录入完成");
	system("pause");
}


