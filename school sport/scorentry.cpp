#include<stdio.h>
#include<iostream>
#include"scorentry.h"
#include"method.h"

void scorentry() {

	char entry;
	system("CLS");
	printf("�ɼ�¼�����\n");
	printf("1.�˶�Ա\n");
	printf("2.�˶���Ŀ\n");
	printf("3.�ɼ�����\n");
	printf("4.����\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);

	switch (swi) {
	case 0: scorentry(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	}
	
}
