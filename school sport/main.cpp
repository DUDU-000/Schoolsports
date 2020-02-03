#include<iostream>
#include<stdio.h>
#include"scorentry.h"
#include"method.h"
#include"basicinfo.h"
#include"countquery.h"

void main() {
	char entry;
	system("CLS");
	printf("主菜单\n");
	printf("1.基本信息管理\n");
	printf("2.成绩录入管理\n");
	printf("3.统计查询管理\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: main();  break;
	case 1: basicinfo(); break;
	case 2: scorentry(); break;
	case 3: countquery(); break;

	}

}


