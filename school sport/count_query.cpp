#include<stdio.h>
#include<iostream>
#include"count_query.h"
#include"method.h"

void count_query() {

	char entry[99];
	system("CLS");
	printf("�ɼ�¼�����\n");
	printf("1.�˶�Ա\n");
	printf("2.�˶���Ŀ\n");
	printf("3.�ɼ�����\n");
	printf("4.����\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: count_query(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	}
}
