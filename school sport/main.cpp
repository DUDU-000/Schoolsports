#include<iostream>
#include<stdio.h>
#include"scorentry.h"
#include"method.h"
#include"basicinfo.h"
#include"countquery.h"

void main() {
	char entry;
	system("CLS");
	printf("���˵�\n");
	printf("1.������Ϣ����\n");
	printf("2.�ɼ�¼�����\n");
	printf("3.ͳ�Ʋ�ѯ����\n");

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


