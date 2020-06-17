#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


typedef struct Tbox{
	int n[5];//0-4是GameBox里对应场地的Game的数量
	GameListNode *GameBox[5][30];//0-4是不同场地,储存Game
	//0-2是第一天上午,3-5是第一天下午,6-8是第二天上午......

	int GamePlayer[30][300];//0-29是不同时间段 300是储存运动员id ,可在0储存有多少个id
	
}Tbox;





//要求: 把k场地之前的相应的比赛时间中运动员id 放到 相应时间段的GamePlayer[30][300]中
//例如 k=2, 则把0和1场地中的 相应时间的运动员id 放到GamePlayer[30][300];中
//假如时间段为2时, 则把在0和1场地中 时间段为2的比赛中的运动员id 放到GamePlayer[2][]中 ,GamePlayer[2][0]可以储存有多少个运动员.
void addGamePlayer(Tbox &T,int k) {
	for (int before_k = 0; before_k < k; before_k++) {
		for (int i = 0; i < 30; i++) {
			int x = T.GamePlayer[i][0];
			for (int j = x + 1; j < T.GameBox[before_k][i]->game.number + x + 1; j++) {
				T.GamePlayer[i][j] = T.GameBox[before_k][i]->game.playerid[j - x - 1].id;
				T.GamePlayer[i][0]++;
			}
		}
	}
	}


//若两个int数组中有相同的运动员id,则返回相同运动员id 个个数,若没有相同的id,则返回0
int SamePlayer(Name *a, Name *b, int a_num, int b_num) {
	int count = 0;
	for (int i = 0; i <a_num; i++) {
		for (int j = 0; j < b_num; j++) {
			if (b[j].id == a[i].id)count++;
		}
	}
	return count;
}
int SamePlayer(int* a, Name* b, int a_num, int b_num) {//用于对比gamebox和gameplayer
	int count = 0;
	for (int i = 1; i < a_num; i++) {//gameplayer[i][0]为人数此时a是gameplayer[j]
		for (int j = 0; j < b_num; j++) {
			if (b[j].id == a[i])count++;
		}
	}
	return count;
}
//排序, 要求在排序第k个场地,要求后一个比赛与前一个game 时间段尽量没有相同运动员,调用SamePlayer
//要求同一时间段一定没有相同运动员id(与Tbox里的GamePlayer比较.
//注意时间段,i为3的倍数时不用比较前后比赛是否有相同id
void sortGame(Tbox &T, int k) {

	for (int i = 0; i < T.n[k]; i++) {//后一个比赛与前一个比赛的时间段尽量没有相同运动员
		if (i % 3 == 0);
		else {
			if (SamePlayer(T.GameBox[k][i]->game.playerid, T.GameBox[k][i - 1]->game.playerid, T.GameBox[k][i]->game.number, T.GameBox[k][i - 1]->game.number) != 0) {//前后时段有相同运动员
				int j = i+1;
				while (j < 30) {
					if (SamePlayer(T.GameBox[k][j]->game.playerid, T.GameBox[k][i - 1]->game.playerid, T.GameBox[k][j]->game.number, T.GameBox[k][i - 1]->game.number) == 0) {
						GameListNode *Game=T.GameBox[k][j];
						T.GameBox[k][j] = T.GameBox[k][i];
						T.GameBox[k][i] = Game;
						break;
					}
					j++;
				}
				if (j == 30) {
					printf("满了！");
				}
			}
		}
	}
	for (int i = 1; i < 5; i++) {
		addGamePlayer(T, i);
		for (int j = 0; j < 30; j++) {//遍历0-29的gameplayer
			if (T.GameBox[i][j] != NULL) {
			if (SamePlayer(T.GamePlayer[j], T.GameBox[i][j]->game.playerid, T.GamePlayer[j][0], T.GameBox[i][j]->game.number) != 0) {//gamebox[1][j]的运动员与gameplayer里面的运动员做比较
				int x = j+1;//i场地j时间段的后面一个时间段的比赛
				while (x < 30) {//查找没有会与GamePlayer[j]重复的GameBox[i][x]，并交换位置
					if (SamePlayer(T.GamePlayer[j], T.GameBox[i][x]->game.playerid, T.GamePlayer[j][0], T.GameBox[i][x]->game.number) == 0) {//找到没有重复的GameBox[i][x]
						GameListNode* Game = T.GameBox[i][x];
						T.GameBox[i][x] = T.GameBox[i][j];
						T.GameBox[i][j] = Game;
						break;
					}
					x++;
				}
				if (x == 30) {
					printf("满了！");
				}
			}
		     }
		}
	}
}

void Game_time() {
	GameListNode * GHead = readGamelist();
	GameListNode * p = GHead;
	Tbox T;

	while (p != NULL) {//将Game储存到Box里
		if (p->game.type == Runway) {
			T.GameBox[0][T.n[0]] = p;
			T.n[0]++;
		}
		else if (p->game.type == Football) {
			T.GameBox[1][T.n[1]] = p;
			T.n[1]++;
		}
		else if (p->game.type == LongJump) {
			T.GameBox[2][T.n[2]] = p;
			T.n[2]++;
		}
		else if (p->game.type == Discus) {
			T.GameBox[3][T.n[3]] = p;
			T.n[3]++;
		}
		else if (p->game.type == HighJump) {
			T.GameBox[4][T.n[4]] = p;
			T.n[4]++;
		}
		p = p->next;
	}
	//调用sortGame
	for (int i = 0; i < 5; i++) {
		sortGame(T, i);
	}



}
