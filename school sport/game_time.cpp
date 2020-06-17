#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


typedef struct Tbox{
	int n[5];//0-4��GameBox���Ӧ���ص�Game������
	GameListNode *GameBox[5][30];//0-4�ǲ�ͬ����,����Game
	//0-2�ǵ�һ������,3-5�ǵ�һ������,6-8�ǵڶ�������......
	int GamePlayer[30][300];//0-29�ǲ�ͬʱ��� 300�Ǵ����˶�Աid ,����0�����ж��ٸ�id
	
}Tbox;

//Ҫ��: ��k����֮ǰ����Ӧ�ı���ʱ�����˶�Աid �ŵ� ��Ӧʱ��ε�GamePlayer[30][300]��
//���� k=2, ���0��1�����е� ��Ӧʱ����˶�Աid �ŵ�GamePlayer[30][300];��
//����ʱ���Ϊ2ʱ, �����0��1������ ʱ���Ϊ2�ı����е��˶�Աid �ŵ�GamePlayer[2][]�� ,GamePlayer[2][0]���Դ����ж��ٸ��˶�Ա.
void addGamePlayer(Tbox &T,int k) {
	for (int i = 0; i < 30; i++) {
		T.GamePlayer[i][0] = 0;
		for (int j = 0; j < k; j++) {
			if (T.GameBox[j][i] == NULL) continue;
			else {
				for (int l = 0; l < T.GameBox[j][i]->game.number; l++) {
					T.GamePlayer[i][0]++;
					T.GamePlayer[i][T.GamePlayer[i][0]] = T.GameBox[j][i]->game.playerid[l].id;
				}
			}
		}
	}
	//for (int before_k = 0; before_k < k; before_k++) {
	//	for (int i = 0; i < T.n[before_k]; i++) {
	//		if (i != 0) x = T.GamePlayer[i][0];
	//		for (int j = x + 1; j < T.GameBox[before_k][i]->game.number + x + 1; j++) {
	//			T.GamePlayer[i][j] = T.GameBox[before_k][i]->game.playerid[j - x - 1].id;
	//			T.GamePlayer[i][0]=j;
	//		}
	//	}
	//}
}

//������int����������ͬ���˶�Աid,�򷵻���ͬ�˶�Աid ������,��û����ͬ��id,�򷵻�0
int SamePlayer(Name *a, Name *b, int a_num, int b_num) {
	int count = 0;
	for (int i = 0; i <a_num; i++) {
		for (int j = 0; j < b_num; j++) {
			if (b[j].id == a[i].id)count++;
		}
	}
	return count;
}

int SamePlayer(int* a, Name* b, int a_num, int b_num) {//���ڶԱ�gamebox��gameplayer
	int count = 0;
	for (int i = 1; i < a_num; i++) {//gameplayer[i][0]Ϊ������ʱa��gameplayer[j]
		for (int j = 0; j < b_num; j++) {
			if (b[j].id == a[i])count++;
		}
	}
	return count;
}

//����, Ҫ���������k������,Ҫ���һ��������ǰһ��game ʱ��ξ���û����ͬ�˶�Ա,����SamePlayer
//Ҫ��ͬһʱ���һ��û����ͬ�˶�Աid(��Tbox���GamePlayer�Ƚ�.
//ע��ʱ���,iΪ3�ı���ʱ���ñȽ�ǰ������Ƿ�����ͬid
void sortGame(Tbox &T, int k) {

	for (int i = 0; i < T.n[k]; i++) {//��һ��������ǰһ��������ʱ��ξ���û����ͬ�˶�Ա
		if (i % 3 == 0);
		else {
			if (T.GameBox[k][i - 1] != NULL&&SamePlayer(T.GameBox[k][i]->game.playerid, T.GameBox[k][i - 1]->game.playerid, T.GameBox[k][i]->game.number, T.GameBox[k][i - 1]->game.number) != 0) {//ǰ��ʱ������ͬ�˶�Ա
				int j = i + 1;
				while (j < 30) {
					if (T.GameBox[k][i - 1]!=NULL&&T.GameBox[k][j]!=NULL&&SamePlayer(T.GameBox[k][j]->game.playerid, T.GameBox[k][i - 1]->game.playerid, T.GameBox[k][j]->game.number, T.GameBox[k][i - 1]->game.number) == 0) {
						GameListNode *Game = T.GameBox[k][j];
						T.GameBox[k][j] = T.GameBox[k][i];
						T.GameBox[k][i] = Game;
						break;
					}
					j++;
				}
				if (j == 30) {
					printf("���ˣ�");
				}
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		addGamePlayer(T, i);
		for (int j = 0; j < 30; j++) {//����0-29��gameplayer
			if (T.GameBox[i][j] != NULL&&SamePlayer(T.GamePlayer[j], T.GameBox[i][j]->game.playerid, T.GamePlayer[j][0], T.GameBox[i][j]->game.number) != 0) {//gamebox[1][j]���˶�Ա��gameplayer������˶�Ա���Ƚ�
				int x = j + 1;//i����jʱ��εĺ���һ��ʱ��εı���
				while (x < 30) {//����û�л���GamePlayer[j]�ظ���GameBox[i][x]��������λ��	
					if (T.GameBox[i][x] != NULL&&SamePlayer(T.GamePlayer[j], T.GameBox[i][x]->game.playerid, T.GamePlayer[j][0], T.GameBox[i][x]->game.number) == 0) {//�ҵ�û���ظ���GameBox[i][x]
						GameListNode* Game = T.GameBox[i][x];
						T.GameBox[i][x] = T.GameBox[i][j];
						T.GameBox[i][j] = Game;
						break;
					}
					x++;
					if (x == 29) {
						for (; x != j; x--) {
							T.GameBox[i][x] = T.GameBox[i][x - 1];
						}
						T.GameBox[i][j] = NULL;
						break;
					}
				}
			}

		}
	}
}

void Givetime(Tbox &T) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 5; j++) {
			if (T.GameBox[j][i] == NULL) continue;
			else {
				int k = i % 6;
				T.GameBox[j][i]->game.starttime.day = i / 6 + 1;
				switch (k)
				{
				case 0:
					T.GameBox[j][i]->game.starttime.hour = 8;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 8;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				case 1:
					T.GameBox[j][i]->game.starttime.hour = 9;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 9;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				case 2:
					T.GameBox[j][i]->game.starttime.hour = 10;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 10;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				case 3:
					T.GameBox[j][i]->game.starttime.hour = 14;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 14;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				case 4:
					T.GameBox[j][i]->game.starttime.hour = 15;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 15;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				case 5:
					T.GameBox[j][i]->game.starttime.hour = 16;
					T.GameBox[j][i]->game.starttime.minute = 0;
					T.GameBox[j][i]->game.endtime.hour = 16;
					T.GameBox[j][i]->game.endtime.minute = 45;
					break;
				}

			}
		}
	}
}



void Game_time() {
	GameListNode * GHead = readGamelist();
	GameListNode * p = GHead;
	Tbox T;
	memset(T.n, 0, sizeof(int)*5);
	memset(T.GameBox, NULL, sizeof(GameListNode *) *30*5);
	memset(T.GamePlayer, 0, sizeof(int) * 30*300);

	while (p != NULL) {//��Game���浽Box��
		if (strcmp(p->game.place,Runway)==0) {
			T.GameBox[0][T.n[0]] = p;
			T.n[0]++;
		}
		else if (strcmp(p->game.place, Football) == 0) {
			T.GameBox[1][T.n[1]] = p;
			T.n[1]++;
		}
		else if (strcmp(p->game.place, LongJump)==0) {
			T.GameBox[2][T.n[2]] = p;
			T.n[2]++;
		}
		else if (strcmp(p->game.place, Discus) ==0){
			T.GameBox[3][T.n[3]] = p;
			T.n[3]++;
		}
		else if (strcmp(p->game.place, HighJump) == 0) {
			T.GameBox[4][T.n[4]] = p;
			T.n[4]++;
		}
		p = p->next;
	}
	//����sortGame
	for (int i = 0; i < 5; i++) {
		sortGame(T, i);
	}
	Givetime(T);
	saveGamelist(GHead);
}
