#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


typedef struct {
	GameListNode *GameBox[5][30];//0-4是不同场地,储存Game
	//0-2是第一天上午,3-5是第一天下午,6-8是第二天上午......

	int GamePlayer[30][300];//0-29是不同时间段 300是储存运动员id ,可在0储存有多少个id
	int n[5];//0-4是GameBox里Game的数量
}Tbox;





//要求: 把k场地之前的相应的比赛时间中运动员id 放到 相应时间段的GamePlayer[30][300]中
//例如 k=2, 则把0和1场地中的 相应时间的运动员id 放到GamePlayer[30][300];中
//假如时间段为2时, 则把在0和1场地中 时间段为2的比赛中的运动员id 放到GamePlayer[2][]中 ,GamePlayer[2][0]可以储存有多少个运动员.
void addGamePlayer(Tbox &T,int k) {

}

//若两个int数组中有相同的运动员id,则返回相同运动员id 个个数,若没有相同的id,则返回0
int SamePlayer(int *a, int *b, int a_num, int b_num) {

}

//排序, 要求在排序第k个场地,要求后一个比赛与前一个时间段尽量没有相同运动员,调用SamePlayer
//要求同一时间段一定没有相同运动员id(与Tbox里的GamePlayer比较.
//注意时间段,i为3的倍数时不用比较前后比赛是否有相同id
void sortGame(Tbox &T, int k) {
	for (int i = 0; i < T.n[k]; i++) {

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



}
