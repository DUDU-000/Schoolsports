#include<iostream>
#include<stdio.h>
#include"scorentry.h"
#include"method.h"
#include"basicinfo.h"
#include"countquery.h"

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
	case 1: if(basicinfo()) main(); break;
	case 2: if (scorentry()) main();  break;
	case 3: if (countquery()) main();  break;
	case 4: break;
	}
	system("pause");
	return 0;
}


