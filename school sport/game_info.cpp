#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

bool game_info() {
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
	case 0: if (game_info()) return true; break;
	case 1:add_info(3); break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
}