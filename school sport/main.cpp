#include<iostream>
#include<stdio.h>

void esinforma() {
	int a;
	system("CLS");
	printf("1.��λ��Ϣ\n");
	printf("2.�˶�Ա��Ϣ\n");
	printf("3.��Ŀ��Ϣ\n");

	scanf_s("%d", &a);

	switch (a) {
	case 1: break;
	case 2: break;
	case 3: break;
	}
}

void main() {
	int a;
	system("CLS");
	printf("1.������Ϣ����\n");
	printf("2.�ɼ�¼�����\n");
	printf("3.������ѯ����\n");

	scanf_s("%d", &a);

	switch (a) {
	case 1: esinforma(); break;
	case 2: break;
	case 3: break;
	}
}


