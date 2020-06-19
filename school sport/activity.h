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
void searchGroup_palyer(GroupListNode * p, int a);

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
BriefGame_2 game_score_rank(int GameID);
void game_socre_print(Game game);
void single_player_scorerevise(Game game);

//Group中的得分的排序
void sortGroup();

//下个阶段
void enter_sit_1();
void enter_sit_2();


void Game_time();

void PrintGameTime();
