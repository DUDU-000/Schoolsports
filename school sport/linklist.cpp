#include<iostream>
#include<stdio.h>
#include"structure.h"

//������Ŀ��������

//����һ�������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->game = game;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊgame,pHeadΪ����������һָ��ڵ�.
void createList(GameListNode* pHead ,Game game) {
	GameListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪgame�Ľڵ�
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

//ɾ���ڵ�p
void deleteNode(PlayerListNode *p) {
	p->player = p->next->player;//����һ���ڵ�����ݷ���p��
	PlayerListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
							//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
}