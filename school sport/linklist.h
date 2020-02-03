#pragma once

void initList(Node ** pNode);

Node * creatList(Node * pHead);

void printList(Node * pHead);

void clearList(Node * pHead);

int sizeList(Node * pHead);

int isEmptyList(Node * pHead);

int getElement(Node * pHead, int pos);

elemType * getElemAddr(Node * pHead, elemType x);

int modifyElem(Node * pNode, int pos, elemType x);

int insertHeadList(Node ** pNode, elemType insertElem);

int insertLastList(Node * pNode, elemType insertElem);

int isAddPos(Node * pNode, int pos, elemType x);

int OrrderList(Node * pNode, elemType x);

int DelHeadList(Node ** pList);

int DelLastList(Node * pNode);

int DelPos(Node * pNode, int pos);

int Delx(Node ** pNode, int x);

int exchange2pos(Node * pNode, int pos1, int pos2);

int swap(int * p1, int * p2);

int Arrange(Node * pNode);
