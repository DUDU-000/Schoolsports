#include<stdio.h>
#include<iostream>
#include"count_query.h"
#include"method.h"

bool count_query() {

	char entry;
	system("CLS");
	printf("�ɼ�¼�����\n");
	printf("1.�˶�Ա\n");
	printf("2.�˶���Ŀ\n");
	printf("3.�ɼ�����\n");
	printf("4.����\n");
	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: if (count_query()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: return true; break;
	}
	return false;
}
