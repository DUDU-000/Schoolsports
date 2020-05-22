#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"



void game_score_entry(Game game) {
	printf("\n\n");
	printf("成绩录入\n");
	printf("田赛输入米, 竞赛输入秒\n");

	PlayerListNode *pHead_player = readPlayerlist();
	PlayerListNode *p_player;
	for (int j = 0; j < game.number; j++) {
		printf("第%d个人: ID:%d ", j+1,game.playerid[j].id);//报名人员id
		printf("名称:%s \n", game.playerid[j].name);//报名人员名称

		p_player = pHead_player;

		while (p_player->player.name.id != game.playerid[j].id) {//找到该运动员
			p_player = p_player->next;
		}

		int i=0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}
		printf("成绩(秒/米):");
		scanf("%lf", &p_player->player.score[i].score);
	}
	savePlayerlist(pHead_player);
	game_score_rank(game);

	printf("成绩录入完成");
	system("pause");
}

BriefGame_2 sortBriefGame(BriefGame_2 briefgame) {
	for (int i = 0; i < briefgame.number - 1; i++) {
		for (int j = 0; j < briefgame.number - 1 - i; j++) {
			if (briefgame.score[j] > briefgame.score[j + 1]) {
				double score = briefgame.score[j];
				briefgame.score[j] = briefgame.score[j + 1];
				briefgame.score[j + 1] = score;

				Name name = briefgame.playername[j];
				briefgame.playername[j] = briefgame.playername[j + 1];
				briefgame.playername[j + 1] = name;
			}
		}
	}
	return briefgame;
}

//获取game 的比赛的运动员排名信息,并排名和给得分
BriefGame_2 game_score_rank(Game game) {

	BriefGame_2 briefgame;
	PlayerListNode *pHead_player = readPlayerlist();
	briefgame.name = game.name;
	briefgame.number = game.number;

	for (int j = 0; j < game.number; j++) {
		
		PlayerListNode *p_player = pHead_player;
		while (p_player->player.name.id != game.playerid[j].id) {//找到该运动员
			p_player = p_player->next;
		}
		int i = 0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}
		briefgame.playername[j] = p_player->player.name;
		briefgame.score[j] = p_player->player.score[i].score;
	}
	briefgame = sortBriefGame(briefgame);
	for (int j = 0; j < game.number; j++) {
		PlayerListNode *p_player = pHead_player;
		while (p_player->player.name.id != game.playerid[j].id) {//找到该运动员
			p_player = p_player->next;
		}
		int i = 0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}

		if (game.type == "田赛") {
			briefgame.rank[j] = game.number - j;
			p_player->player.score[i].rank= game.number - j;

			if (game.number - j <= 10) briefgame.point[j] = 10 - (game.number - j) + 1;
			else briefgame.point[j] = 0;
			p_player->player.score[i].point = briefgame.point[j];
		}
		else{
			briefgame.rank[j] = j+1;
			p_player->player.score[i].rank = j + 1;

			if (j + 1 <= 10) briefgame.point[j] = 10 - (j + 1)+1;
			else briefgame.point[j] = 0;
			p_player->player.score[i].point = briefgame.point[j];
		}
	}
	savePlayerlist(pHead_player);
	return briefgame;
}

void game_socre_print(Game game) {
	BriefGame_2 game_score = game_score_rank(game);
	printf("\n\n\n");
	printf("比赛成绩:");
	if (game.type == "田赛") {
		for (int i = game_score.number - 1; i >= 0; i--) {
			printf("ID:%-10d ", game_score.playername[i].id);
			printf("姓名:%-10s ", game_score.playername[i].name);
			printf("成绩:%-7.2f米 ", game_score.score[i]);
			printf("排名:%-5d ", game_score.rank[i]);
			printf("得分:%-5d \n", game_score.point[i]);
		}
	}
	else{
		for (int i = 0; i < game_score.number; i++) {
			printf("ID:%-10d ", game_score.playername[i].id);
			printf("姓名:%-10s ", game_score.playername[i].name);
			printf("成绩:%-7.2f秒   ", game_score.score[i]);
			printf("排名:%-5d ", game_score.rank[i]);
			printf("得分:%-5d \n", game_score.point[i]);
		}
	}
	system("pause");
}








