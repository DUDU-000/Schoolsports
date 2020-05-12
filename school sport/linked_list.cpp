#include<iostream>
#include<stdio.h>
#include "linked_list.h"
#include"method.h"
//������Ŀ��������

//����һ�������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	if (pHeadNode == NULL) {
		printf("��������ʧ��");
		exit(0);
	}
	pHeadNode->game = game;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(GameListNode* pHead, Game game) {
	GameListNode* p = pHead;
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
		p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
	}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p,pHead��ͷ�ڵ�,����ͷ�ڵ�,���ȫɾ���˷���NULL;
GameListNode* deleteNode(GameListNode *pHead, GameListNode *p) {
	if (p->next != NULL) {
		p->game = p->next->game;//����һ���ڵ�����ݷ���p��
		GameListNode *p_next = p->next;//��¼ָ��
		p->next = p->next->next;//����һ���ڵ��next����p��,
								//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
		free(p_next);//�ͷ������ڴ�
		p_next = NULL;
		return pHead;
	}
	else if (longNode(pHead) == 1) {//���ֻ��һ���ڵ�
		free(p);
		return NULL;
	}
	else {//p�����һ���ڵ�
		GameListNode *newp = pHead;
		while (newp->next->next != NULL) {
			newp = newp->next;
		}
		newp->next = NULL;
		free(p);
		return pHead;
	}
}
//����ͷ�ڵ�,�����ж��ٸ��ڵ�
int longNode(GameListNode *pHead) {
	int i=0;
	GameListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//���ļ��ж�ȡ����
GameListNode* readGamelist() {
	FILE *fp;//�ļ�ָ��
	GameListNode* pHead=NULL;
	int line_long;
	Game game;
	/*�ļ��Ĵ�*/
	fp = fopen("game.txt", "rt+");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
	
	std::string file_path = "game.txt";
	if (fp == NULL || file_is_empty(file_path)) {//�ж�����ļ�ָ��Ϊ��
		return NULL;
	}

	fscanf_s(fp, "��Ŀ����:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "ID:%d\n", &game.name.id);//id
		fscanf_s(fp, "����:%s\n", &game.name.name,99);//����
		fscanf_s(fp, "����:%s\n", &game.type,5);//����
		fscanf_s(fp, "�ص�:%s\n", &game.place,7);//�ص�
		fscanf_s(fp, "����:%d\n", &game.number);//����
		fscanf_s(fp, "��ʼʱ��:%d��%d��%d : %d\n", &game.starttime.month, &game.starttime.date, &game.starttime.hour, &game.starttime.minute);//��ʼʱ��
		fscanf_s(fp, "����ʱ��:%d : %d\n", &game.endtime.hour, &game.endtime.minute);//����ʱʱ��
		for (int j = 0; j < game.number; j++) {
			fscanf_s(fp, "������ԱID:%d\n", &game.playerid[j].id);//������Աid
			fscanf_s(fp, "������Ա����:%s\n", &game.playerid[j].name,99);//����������
		}
		fscanf_s(fp, "����״̬(0:������|1:��ֹ):%d\n", & game.status);//����״̬
		if (i == 0) pHead = createpHead(game);
		else addNode(pHead, game);
	}
	fclose(fp);
	return pHead;

}
//����������ļ���
void saveGamelist(GameListNode* pHead) {
	FILE *fp;//�ļ�ָ��
	fp = fopen("game.txt", "w");
	int line_long = longNode(pHead);//�������ж��ٸ��ڵ�
	GameListNode* p = pHead;
	Game game;

	fprintf(fp, "��Ŀ����:%d\n", line_long);//�����ж��ٸ��ڵ�
	for (int i = 0; i < line_long; i++,p=p->next) {
		game = p->game;
		fprintf(fp, "ID:%d\n", game.name.id/*id*/);
		fprintf(fp, "����:%s\n", game.name.name/*����*/);
		fprintf(fp, "����:%s\n", game.type/*����*/);
		fprintf(fp, "�ص�:%s\n", game.place/*�ص�*/);
		fprintf(fp, "����:%d\n", game.number/*��������*/);
		fprintf(fp, "��ʼʱ��:%d��%d��%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/);
		fprintf(fp, "����ʱ��:%d : %d\n",  game.endtime.hour, game.endtime.minute/*����ʱ��*/);
		for (int j = 0; j < game.number; j++){//���汨����Աid
			fprintf(fp, "������ԱID:%d\n", game.playerid[j].id);
			fprintf(fp, "������Ա����:%s\n", game.playerid[j].name);//����������
		}
		fprintf(fp, "����״̬(0:������|1:��ֹ):%d\n", game.status);//����״̬
	}
	fclose(fp);
}
//��ӡ����
void printGamelist(GameListNode* pHead)
{
	int line_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	for (int i = 0; i < line_long; i++, p = p->next)
	{
		game = p->game;
		printf("%d.", i + 1/*���*/);
		printf("����:%s", game.name.name/*����*/);
		printf(" ID:%d",game.name.id /*ID*/);
		printf(" ʱ��:%d��%d��%d : %d - %d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute, game.endtime.hour, game.endtime.minute/*ʱ��*/);
	}
}


//�˶�Ա��������

//����һ�������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
PlayerListNode* createpHead(Player player) {
	PlayerListNode* pHeadNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->player = player;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(PlayerListNode* pHead, Player player) {
	PlayerListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	PlayerListNode* pNewNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->player = player;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(PlayerListNode *p, Player player) {
	PlayerListNode* pNewNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->player = player;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
PlayerListNode* deleteNode(PlayerListNode *pHead, PlayerListNode *p) {
	if (p->next != NULL) {
		p->player = p->next->player;//����һ���ڵ�����ݷ���p��
		PlayerListNode *p_next = p->next;//��¼ָ��
		p->next = p->next->next;//����һ���ڵ��next����p��,
								//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
		free(p_next);//�ͷ������ڴ�
		p_next = NULL;
		return pHead;
	}
	else if (longNode(pHead) == 1) {//���ֻ��һ���ڵ�
		free(p);
		return NULL;
	}
	else {//p�����һ���ڵ�
		PlayerListNode *newp = pHead;
		while (newp->next->next != NULL) {
			newp = newp->next;
		}
		newp->next = NULL;
		free(p);
		return pHead;
	}
}
//����ͷ�ڵ�,�����ж��ٸ��ڵ�
int longNode(PlayerListNode *pHead) {
	int i = 0;
	PlayerListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

PlayerListNode* readPlayerlist() {
	FILE *fp;//�ļ�ָ��
	PlayerListNode* pHead = NULL;
	int line_long;
	Player player;

	/*�ļ��Ĵ�*/
	fp = fopen("player.txt", "rt+");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��

	std::string file_path = "player.txt";
	if (fp == NULL || file_is_empty(file_path)) {//�ж�����ļ�ָ��Ϊ��
		return NULL;
	}

	fscanf_s(fp, "�˶�Ա����:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "ID:%d\n", &player.name.id);//id
		fscanf_s(fp, "����:%s\n", &player.name.name, 99);//����
		fscanf_s(fp, "�Ա�:%s\n", &player.gender, 3);//�Ա�
		fscanf_s(fp, "����:%d\n", &player.year);//����
		fscanf_s(fp, "С��ID:%d\n", &player.group_id);//С��ID
		fscanf_s(fp, "�ܷ���:%d\n", &player.fullscore);//�ܷ���
		fscanf_s(fp, "������:%d\n", &player.game_number);//������
		for (int j = 0; j < player.game_number; j++) {
			fscanf_s(fp, "��ĿID:%d\n", &player.score->name.id);//��Ŀid
			fscanf_s(fp, "��Ŀ����:%s\n", &player.score->name.name, 99);//��Ŀ����
			fscanf_s(fp, "��Ŀ�ɼ�:%1f\n", &player.score->score);//��Ŀ�ɼ�
			fscanf_s(fp, "��Ŀ�÷�:%d\n", &player.score->point);//��Ŀ�ɼ�
		}
		if (i == 0) pHead = createpHead(player);
		else addNode(pHead, player);
	}
	fclose(fp);
	return pHead;
}
//����������ļ���
void savePlayerlist(PlayerListNode* pHead) {
	FILE *fp;//�ļ�ָ��
	fp = fopen("player.txt", "w");
	int line_long = longNode(pHead);//�������ж��ٸ��ڵ�
	PlayerListNode* p = pHead;
	Player player;

	fprintf(fp, "�˶�Ա����:%d\n", line_long);
	for (int i = 0; i < line_long; i++, p = p->next) {
		player = p->player;
		fprintf(fp, "ID:%d\n", player.name.id);//id
		fprintf(fp, "����:%s\n", player.name.name);//����
		fprintf(fp, "�Ա�:%s\n", player.gender);//�Ա�
		fprintf(fp, "����:%d\n", player.year);//id
		fprintf(fp, "С��ID:%d\n", player.group_id);//С��ID
		fprintf(fp, "�ܷ���:%d\n", player.fullscore);//�ܷ���
		fprintf(fp, "������:%d\n", player.game_number);//������
		for (int j = 0; j < player.game_number; j++) {
			fprintf(fp, "��ĿID:%d\n", player.score->name.id);//��Ŀid
			fprintf(fp, "��Ŀ����:%s\n", player.score->name.name);//��Ŀ����
			fprintf(fp, "��Ŀ�ɼ�:%lf\n", player.score->score);//��Ŀ�ɼ�
			fprintf(fp, "��Ŀ�÷�:%d\n", player.score->point);//��Ŀ�ɼ�
		}
	}
	fclose(fp);
}
//��ӡ����
void printPlayerlist(PlayerListNode* pHead)
{
	int line_long = longNode(pHead);
	PlayerListNode* p = pHead;
	Player player;
	for (int i = 0; i < line_long; i++, p = p->next){
		player = p->player;
		printf("%d.", i + 1/*���*/);
		printf(" ID:%d ", player.name.id);
		printf("����:%s ", player.name.name/*����*/);
		printf(" �Ա�:%s ", player.gender);
		printf(" �μ���Ŀ:");
		if (player.game_number == 0) printf("��");
		else for (int j = 0; j < player.game_number; j++) printf("%s ", &player.score->name.name);//��Ŀ����
		printf("\n");
	}
	
}

//���������

//����һ�������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GroupListNode* createpHead(Group group) {
	GroupListNode* pHeadNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->group = group;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(GroupListNode* pHead, Group group) {
	GroupListNode* p = pHead;
	GroupListNode* pNewNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->group = group;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(GroupListNode *p, Group group) {
	GroupListNode* pNewNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->group = group;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
void deleteNode(GroupListNode *p) {
	p->group = p->next->group;//����һ���ڵ�����ݷ���p��
	GroupListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
							//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
}
//����ͷ�ڵ㣬�����ж��ٸ��ڵ�
int longNode(GroupListNode* pHead) {
	GroupListNode* p = pHead; 
	int x=0;
	if (p == NULL) return 0;
	else x++;
	while (p->next != NULL) {
		p = p->next;
		x++;
	}
	return x;
}
//�����ļ�����������
GroupListNode* readGrouplist() {
	FILE *fp;//�ļ�ָ��
	GroupListNode* pHead = NULL;
	int line_long;
	Group group;
	 /*�ļ���*/
	fp = fopen("group.txt", "rt+");

	std::string file_path = "group.txt";
	if (fp == NULL || file_is_empty(file_path)) {//�ж�����ļ�ָ��Ϊ��
		return NULL;
	}

	fscanf_s(fp, "��λ����:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "��λID:%d\n",& group.name.id);/*id*/
		fscanf_s(fp, "��λ����:%s\n",& group.name.name,99);/*����*/
		fscanf_s(fp, "��λ����������:%d\n", &group.game_number);/*����������*/
		fscanf_s(fp, "��λ�ܵ÷�:%d\n", &group.fullscore);/*�ܵ÷�*/
		fscanf_s(fp, "��λ����:%d\n", &group.member_number);/*����*/
		for (int n = 0; n < group.member_number; n++) {
			fscanf_s(fp, "�˶�ԱID:%d\n", &group.memberid[n]);
		}
		for (int n = 0; n < group.game_number; n++) {
			fscanf_s(fp, "����ID:%d\n", &group.score->name.id);
			fscanf_s(fp, "��������:%s\n", &group.score->name.name,99);
			fscanf_s(fp, "�ñ������û���:%d\n", &group.score->point);
			fscanf_s(fp, "�ñ�����ѳɼ�:%f\n", &group.score->score);
		}
		if (i == 0) pHead = createpHead(group);
		else addNode(pHead, group);
	}
	fclose(fp);
	return pHead;
}
//��������
void saveGrouplist(GroupListNode* pHead) {
	FILE* fp;//�ļ�ָ��
	fp = fopen("group.txt", "w");

	int line_long=longNode(pHead);
	GroupListNode* p = pHead;
	Group group;

	fprintf(fp, "��λ����:%d\n", line_long);
	for (int i = 0; i < line_long; i++,p=p->next) {
		group = p->group;
		fprintf(fp, "��λID:%d\n", group.name.id);/*id*/
		fprintf(fp, "��λ����:%s\n", group.name.name);/*����*/
		fprintf(fp, "��λ����������:%d\n", group.game_number);/*������*/
		fprintf(fp, "��λ�ܵ÷�:%d\n", group.fullscore);/*�ܵ÷�*/
		fprintf(fp, "��λ����:%d\n", group.member_number);/*����*/
	    for (int j = 0; j < group.member_number; j++) {
			fprintf(fp, "�˶�ԱID:%d\n", group.memberid[j]);
		}
		for (int n = 0; n < group.game_number; n++) {
			fprintf(fp, "����ID:%d\n", group.score->name.id);
			fprintf(fp, "��������:%s\n", group.score->name.name);
			fprintf(fp, "�ñ������û���:%d\n", group.score->point);
			fprintf(fp, "�ñ�����ѳɼ�:%f\n", group.score->score);
		}
		

	}
	fclose(fp);
}
//��ӡ����
void printGrouplist(GroupListNode* pHead) {
	int line_long = longNode(pHead);
	GroupListNode* p = pHead;
	Group group;
	for (int i = 0; i < line_long; i++,p=p->next) {
		group = p->group;
		printf("%d.", i+1);/*���*/
		printf("ID:%d ", group.name.id);
		printf("����:%s ", group.name.name);
		printf("����:%d ", group.member_number);
		printf("����������:%d \n", group.game_number);
	}
}