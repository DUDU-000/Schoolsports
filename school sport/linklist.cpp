#include<iostream>
#include<stdio.h>
#include"structure.h"

//比赛项目的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//创建一个新的指针节点并分配空间
	pHeadNode->game = game;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为game,pHead为该链表中任一指针节点.
void createList(GameListNode* pHead ,Game game) {
	GameListNode* p = pHead;
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为game的节点
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
void deleteNode(GameListNode *p) {
	p->game = p->next->game;//将下一个节点的内容放入p中
	GameListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
	//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}


//运动员的链表函数

//删除节点p
void deleteNode(PlayerListNode *p) {
	p->player = p->next->player;//将下一个节点的内容放入p中
	PlayerListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
							//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}