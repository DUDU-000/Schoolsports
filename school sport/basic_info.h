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
void addGameNode();
void searchGamelist_type();
void searchGamelist_name();
void searchGamelist_time();