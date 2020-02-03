#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

void playinfo() {
	char entry;
	system("CLS");
	printf("运动员信息\n");
	printf("1.增加\n");
	printf("2.修改\n");
	printf("3.删除\n");
	printf("4.查询\n");

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