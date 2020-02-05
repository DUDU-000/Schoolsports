#include<iostream>
#include<stdio.h>
#include"score_entry.h"
#include"method.h"
#include"basic_info.h"
#include"count_query.h"

int main() {
	char entry;
	system("CLS");
	printf("主菜单\n");
	printf("1.基本信息管理\n");
	printf("2.成绩录入管理\n");
	printf("3.统计查询管理\n");
	printf("4.退出系统\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: main();  break;
	case 1: if(basic_info()) main(); break;
	case 2: if (score_entry()) main();  break;
	case 3: if (count_query()) main();  break;
	case 4: system("pause"); break;
	}
	return 0;
}


