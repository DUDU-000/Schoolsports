#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

void playinfo() {
	char entry;
	system("CLS");
	printf("�˶�Ա��Ϣ\n");
	printf("1.����\n");
	printf("2.�޸�\n");
	printf("3.ɾ��\n");
	printf("4.��ѯ\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: playinfo(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;

	}
}