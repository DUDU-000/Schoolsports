#include<iostream>
#include<stdio.h>
#include "linked_list.h"


//������Ŀ��������

//����һ�������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->game = game;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(GameListNode* pHead ,Game game) {
	GameListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
void deleteNode(GameListNode *p) {
	p->game = p->next->game;//����һ���ڵ�����ݷ���p��
	GameListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
	//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
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
void deleteNode(PlayerListNode *p) {
	p->player = p->next->player;//����һ���ڵ�����ݷ���p��
	PlayerListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
							//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
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
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	GroupListNode* pNewNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->group = group;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
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