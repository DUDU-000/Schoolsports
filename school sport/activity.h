#pragma once
#include"linked_list.h"

//查询
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

//三个信息界面
void information_game(GameListNode* pHead, int situation);
void information_player(PlayerListNode * pnewHead, int situation);
void information_group(GroupListNode* pnewHead, int situation);

//修改信息
void reviseGame(Game game);
void revisePlayer(Player player);
void reviseGroup(Group group);

//增加
void addGameNode();
void addPlayerNode();
void addGroupNode();
//成绩录入相关
void game_score_entry(Game game);
BriefGame_2 game_score_rank(Game game);
void game_socre_print(Game game);
