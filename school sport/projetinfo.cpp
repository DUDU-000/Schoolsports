#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

bool projetinfo() {
	char entry;
	system("CLS");
	printf("��Ŀ��Ϣ\n");
	printf("1.����\n");
	printf("2.�޸�\n");
	printf("3.ɾ��\n");
	printf("4.��ѯ\n");
	printf("5.����\n");
	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: if (projetinfo()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
}