#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"

void count_player_fullsocre(PlayerListNode *p) {
	p->player.fullscore = 0;
	for (int i = 0; i < p->player.game_number; i++) {
		p->player.fullscore = p->player.fullscore + p->player.score[i].point;
	}
}

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
	game_score_rank(game.name.id);

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
BriefGame_2 game_score_rank(int GameID) {

	GameListNode *p_game = readGamelist();
	while (p_game->game.name.id != GameID) {
		p_game = p_game->next;
	}
	Game game = p_game->game;
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
			count_player_fullsocre(p_player);
		}
		else{
			briefgame.rank[j] = j+1;
			p_player->player.score[i].rank = j + 1;

			if (j + 1 <= 10) briefgame.point[j] = 10 - (j + 1)+1;
			else briefgame.point[j] = 0;
			p_player->player.score[i].point = briefgame.point[j];
			count_player_fullsocre(p_player);
		}

	}
	savePlayerlist(pHead_player);
	return briefgame;
}

void game_socre_print(Game game) {
	BriefGame_2 game_score = game_score_rank(game.name.id);
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

void single_player_scorerevise(Game game) {
	system("CLS");
	printf("%s项目运动员ID:\n",game.name.name);
	for (int i = 0; i < game.number; i++)
	{
		printf("%d\n", game.playerid[i]);
	}
	char entry_playerid[99];
	printf("个人成绩修改\n");
	printf("请输入运动员ID:");
	gets_s(entry_playerid, 99);
	rewind(stdin);
	int id = entrycheck(entry_playerid, 0, 999);
	PlayerListNode* p = readPlayerlist();
	while (p->player.name.id != id) {
		if (p->next == NULL)break;

		p = p->next;

	}//查找运动员

	if (p->player.name.id != id)printf("查询不到相关内容\n");

	else {

		Player player = p->player;
		printf("所查询运动员\nID : %d\n名称 : %s\n", player.name.id, player.name.name);
		int mark = 0;
		int j;
		for (int n = 0; n < player.game_number; n++) {
			if (player.score[n].name.id == game.name.id) { 
				j = n;
				mark = 1; 
			}
		}

		if (player.game_number == 0||mark==0) {
			printf("没有该项比赛记录");
		}
		else {


			printf("要修改的成绩为%d\n",player.score[j].score);
			printf("请输入修改后的项目成绩:\n");
			char score_entry[1];
			gets_s(score_entry, 1);
			int score_e = entrycheck(score_entry, 0, 999);
			player.score[j].score = score_e;


			printf("修改成功！修改后的成绩为\n", player.score[j].score);

			p->player = player;

			savePlayerlist(p);
			game_score_rank(game.name.id);
		}
	}
	system("pause");

}

void sortGroup() {//对单位内运动员成绩进行排名
	GroupListNode *GHead = readGrouplist();
	GroupListNode *g = GHead;
	PlayerListNode *PHead = readPlayerlist();
	PlayerListNode *p = PHead;

	while( g != NULL){//读取运动员得分
		Group group = g->group;
		p = PHead;
		g->group.fullscore = 0;
		for (int i = 0; i < group.member_number; i++) {
			while (p->player.name.id != group.memberid[i].id) {
				group.point[i] = p->player.fullscore;
				g->group.fullscore = g->group.fullscore + p->player.fullscore;
			}
		}

		for (int i = 0; i < group.member_number - 1; i++) {//排序
			for (int j = 0; j < group.member_number - 1 - i; j++) {
				if (group.point[j]>group.point[j + 1]) {
					int point = group.point[j];
					group.point[j] = group.point[j + 1];
					group.point[j + 1] = point;

					Name id = group.memberid[j];
					group.memberid[j] = group.memberid[j + 1];
					group.memberid[j + 1] = id;
				}
			}
		}
		g->group = group;
		g = g->next;
	}
	saveGrouplist(GHead);
}








