#pragma once
#include"linked_list.h"

//��ѯ
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

//������Ϣ����
void information_game(GameListNode* pHead, int situation);
void information_player(PlayerListNode * pnewHead, int situation);
void information_group(GroupListNode* pnewHead, int situation);

//�޸���Ϣ
void reviseGame(Game game);
void revisePlayer(Player player);
void reviseGroup(Group group);

//����
void addGameNode();
void addPlayerNode();
void addGroupNode();
//�ɼ�¼�����
void game_score_entry(Game game);
BriefGame_2 game_score_rank(Game game);
void game_socre_print(Game game);
