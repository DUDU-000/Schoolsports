#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


typedef struct {
	GameListNode *GameBox[5][30];//0-4�ǲ�ͬ����,����Game
	//0-2�ǵ�һ������,3-5�ǵ�һ������,6-8�ǵڶ�������......

	int GamePlayer[30][300];//0-29�ǲ�ͬʱ��� 300�Ǵ����˶�Աid ,����0�����ж��ٸ�id
	int n[5];//0-4��GameBox��Game������
}Tbox;





//Ҫ��: ��k����֮ǰ����Ӧ�ı���ʱ�����˶�Աid �ŵ� ��Ӧʱ��ε�GamePlayer[30][300]��
//���� k=2, ���0��1�����е� ��Ӧʱ����˶�Աid �ŵ�GamePlayer[30][300];��
//����ʱ���Ϊ2ʱ, �����0��1������ ʱ���Ϊ2�ı����е��˶�Աid �ŵ�GamePlayer[2][]�� ,GamePlayer[2][0]���Դ����ж��ٸ��˶�Ա.
void addGamePlayer(Tbox &T,int k) {

}

//������int����������ͬ���˶�Աid,�򷵻���ͬ�˶�Աid ������,��û����ͬ��id,�򷵻�0
int SamePlayer(int *a, int *b, int a_num, int b_num) {

}

//����, Ҫ���������k������,Ҫ���һ��������ǰһ��ʱ��ξ���û����ͬ�˶�Ա,����SamePlayer
//Ҫ��ͬһʱ���һ��û����ͬ�˶�Աid(��Tbox���GamePlayer�Ƚ�.
//ע��ʱ���,iΪ3�ı���ʱ���ñȽ�ǰ������Ƿ�����ͬid
void sortGame(Tbox &T, int k) {
	for (int i = 0; i < T.n[k]; i++) {

	}

}

void Game_time() {
	GameListNode * GHead = readGamelist();
	GameListNode * p = GHead;
	Tbox T;

	while (p != NULL) {//��Game���浽Box��
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
	//����sortGame



}
