#include<iostream>
#include<stdio.h>
#include"score_entry.h"
#include"method.h"
#include"basic_info.h"
#include"count_query.h"

int main() {
	char entry;
	system("CLS");
	printf("���˵�\n");
	printf("1.������Ϣ����\n");
	printf("2.�ɼ�¼�����\n");
	printf("3.ͳ�Ʋ�ѯ����\n");
	printf("4.�˳�ϵͳ\n");

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


