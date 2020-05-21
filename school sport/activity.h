#pragma once
#include"linked_list.h"


void query_game_menu();
void query_group_menu();
void query_player_menu();
void add_menu();


void searchGamelist_type();
void searchGamelist_name();
void searchGamelist_time();
void searchGamelist_all();
void searchPlayerlist_name();
void searchPlayerlist_group();
void searchPlayer_all();
void searchGroup_name();
void searchGroup_all();
void searchGroup_game(GroupListNode* p);
void searchGroup_palyer(GroupListNode* p);



void information_game(GameListNode* pHead, int situation);
void information_player(PlayerListNode * pnewHead, int situation);
void information_group(GroupListNode* pnewHead, int situation);


void reviseGame(Game game);
void revisePlayer(Player player);
void reviseGroup(Group group);


void addGameNode();
void addPlayerNode();
void addGroupNode();


void score_entry(Game game);