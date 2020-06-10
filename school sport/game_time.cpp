#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


typedef struct {
	GameListNode *GameBox[8][30];
	int GamePlayer[30][300];
}Tbox;


void Game_time() {
	GameListNode * GHead = readGamelist();

}
