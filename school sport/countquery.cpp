#include<stdio.h>
#include<iostream>
#include"countquery.h"
#include"method.h"

void countquery() {

	char entry;
	system("CLS");
	printf("�ɼ�¼�����\n");
	printf("1.�˶�Ա\n");
	printf("2.�˶���Ŀ\n");
	printf("3.�ɼ�����\n");


	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);

	switch (swi) {
	case 0: countquery(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	}

}
