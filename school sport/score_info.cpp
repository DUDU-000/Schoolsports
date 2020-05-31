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
	printf("�ɼ�¼��\n");
	printf("����������, ����������\n");

	PlayerListNode *pHead_player = readPlayerlist();
	PlayerListNode *p_player;
	for (int j = 0; j < game.number; j++) {
		printf("��%d����: ID:%d ", j+1,game.playerid[j].id);//������Աid
		printf("����:%s \n", game.playerid[j].name);//������Ա����

		p_player = pHead_player;

		while (p_player->player.name.id != game.playerid[j].id) {//�ҵ����˶�Ա
			p_player = p_player->next;
		}

		int i=0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}
		printf("�ɼ�(��/��):");
		scanf("%lf", &p_player->player.score[i].score);
	}
	savePlayerlist(pHead_player);
	game_score_rank(game.name.id);

	printf("�ɼ�¼�����");
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
//��ȡgame �ı������˶�Ա������Ϣ,�������͸��÷�
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
		while (p_player->player.name.id != game.playerid[j].id) {//�ҵ����˶�Ա
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
		while (p_player->player.name.id != game.playerid[j].id) {//�ҵ����˶�Ա
			p_player = p_player->next;
		}
		int i = 0;
		while (p_player->player.score[i].name.id != game.name.id) {
			i++;
		}

		if (game.type == "����") {
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
	printf("�����ɼ�:");
	if (game.type == "����") {
		for (int i = game_score.number - 1; i >= 0; i--) {
			printf("ID:%-10d ", game_score.playername[i].id);
			printf("����:%-10s ", game_score.playername[i].name);
			printf("�ɼ�:%-7.2f�� ", game_score.score[i]);
			printf("����:%-5d ", game_score.rank[i]);
			printf("�÷�:%-5d \n", game_score.point[i]);
		}
	}
	else{
		for (int i = 0; i < game_score.number; i++) {
			printf("ID:%-10d ", game_score.playername[i].id);
			printf("����:%-10s ", game_score.playername[i].name);
			printf("�ɼ�:%-7.2f��   ", game_score.score[i]);
			printf("����:%-5d ", game_score.rank[i]);
			printf("�÷�:%-5d \n", game_score.point[i]);
		}
	}
	system("pause");
}

void single_player_scorerevise(Game game) {
	system("CLS");
	printf("%s��Ŀ�˶�ԱID:\n",game.name.name);
	for (int i = 0; i < game.number; i++)
	{
		printf("%d\n", game.playerid[i]);
	}
	char entry_playerid[99];
	printf("���˳ɼ��޸�\n");
	printf("�������˶�ԱID:");
	gets_s(entry_playerid, 99);
	rewind(stdin);
	int id = entrycheck(entry_playerid, 0, 999);
	PlayerListNode* p = readPlayerlist();
	while (p->player.name.id != id) {
		if (p->next == NULL)break;

		p = p->next;

	}//�����˶�Ա

	if (p->player.name.id != id)printf("��ѯ�����������\n");

	else {

		Player player = p->player;
		printf("����ѯ�˶�Ա\nID : %d\n���� : %s\n", player.name.id, player.name.name);
		int mark = 0;
		int j;
		for (int n = 0; n < player.game_number; n++) {
			if (player.score[n].name.id == game.name.id) { 
				j = n;
				mark = 1; 
			}
		}

		if (player.game_number == 0||mark==0) {
			printf("û�и��������¼");
		}
		else {


			printf("Ҫ�޸ĵĳɼ�Ϊ%d\n",player.score[j].score);
			printf("�������޸ĺ����Ŀ�ɼ�:\n");
			char score_entry[1];
			gets_s(score_entry, 1);
			int score_e = entrycheck(score_entry, 0, 999);
			player.score[j].score = score_e;


			printf("�޸ĳɹ����޸ĺ�ĳɼ�Ϊ\n", player.score[j].score);

			p->player = player;

			savePlayerlist(p);
			game_score_rank(game.name.id);
		}
	}
	system("pause");

}

void sortGroup() {//�Ե�λ���˶�Ա�ɼ���������
	GroupListNode *GHead = readGrouplist();
	GroupListNode *g = GHead;
	PlayerListNode *PHead = readPlayerlist();
	PlayerListNode *p = PHead;

	while( g != NULL){//��ȡ�˶�Ա�÷�
		Group group = g->group;
		p = PHead;
		g->group.fullscore = 0;
		for (int i = 0; i < group.member_number; i++) {
			while (p->player.name.id != group.memberid[i].id) {
				group.point[i] = p->player.fullscore;
				g->group.fullscore = g->group.fullscore + p->player.fullscore;
			}
		}

		for (int i = 0; i < group.member_number - 1; i++) {//����
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








