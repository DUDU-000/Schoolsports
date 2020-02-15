#pragma once
#include"linked_list.h"
//������ͬ����,��activity��ʹ��
const int type_group = 1;
const int type_player = 2;
const int type_game = 3;


void basic_info();
void group_info();
void player_info();
void game_info();

void query_game_menu();
void query_group_menu();
void query_player_menu();

void searchGamelist_type();
void searchGamelist_name();
void searchGamelist_time();
void searchGamelist_all();
void searchPlayerlist_name();
void searchPlayerlist_group();
void searchPlayer_all();



void information_game(GameListNode* pHead, int situation);
void information_player(PlayerListNode * pnewHead, int situation);


void reviseGame(Game game);
void revisePlayer(Player player);


void addGameNode();
void addPlayerNode();