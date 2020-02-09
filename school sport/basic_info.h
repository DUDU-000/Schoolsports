#pragma once
#include"linked_list.h"
//三个不同类型,在activity中使用
const int type_group = 1;
const int type_player = 2;
const int type_game = 3;


void basic_info();
void group_info();
void player_info();
void game_info();
void addGameNode();
void query_game_menu();
void searchGamelist_type();
void searchGamelist_name();
void searchGamelist_time();
void searchGamelist_all();
void information_game(GameListNode* pHead, int situation);
void reviseGame(Game game);

void addPlayerNode();