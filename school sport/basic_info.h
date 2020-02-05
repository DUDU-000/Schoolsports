#pragma once
//三个不同类型,在activity中使用
const int type_group = 1;
const int type_player = 2;
const int type_game = 3;


bool basic_info();
bool group_info();
bool player_info();
bool game_info();
void add_info(int type);