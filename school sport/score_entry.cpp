#include<stdio.h>
#include<iostream>
#include"score_entry.h"
#include"method.h"

bool score_entry() {

	char entry;
	system("CLS");
	printf("�ɼ�¼�����\n");
	printf("1.�˶�Ա\n");
	printf("2.�˶���Ŀ\n");
	printf("3.�ɼ�����\n");
	printf("4.����\n");
	printf("5.����\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: if (score_entry()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
	
}
