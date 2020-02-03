#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

bool basicinfo() {
	char entry;
	system("CLS");
	printf("基本信息管理\n");
	printf("1.单位信息\n");
	printf("2.运动员信息\n");
	printf("3.项目信息\n");
	printf("4.返回\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: if (basicinfo()) return true; break;
	case 1: if (groupinfo()) if(basicinfo()) return true; break;
	case 2: if (playinfo()) if (basicinfo()) return true; break;
	case 3: if (projetinfo()) if (basicinfo()) return true; break;
	case 4: return true; break;
	}
	return false;
}