#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

void basicinfo() {
	char entry;
	system("CLS");
	printf("������Ϣ����\n");
	printf("1.��λ��Ϣ\n");
	printf("2.�˶�Ա��Ϣ\n");
	printf("3.��Ŀ��Ϣ\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: basicinfo(); break;
	case 1: groupinfo(); break;
	case 2: playinfo(); break;
	case 3: projetinfo(); break;
	}
}