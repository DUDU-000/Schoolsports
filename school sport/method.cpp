#include<iostream>
#include<stdio.h>
#include<string>
#include"method.h"
#include"linked_list.h"

//��entry��mix��max֮��,�򷵻�int�͵�entry,����,����0,�������char������
int entrycheck(char entry[] , int mix,int max) {
	int result=0;
	int byte = strlen(entry);
	for (int i = 0; i < strlen(entry); i++) {
		if ('0' <= entry[i] && entry[i] <= '9') result = result * 10 + entry[i] - 48;
		else return -1;
	}
	if(mix<=result&&result<=max) return result;
	else return -1;
}

int entrycheckandreinput(int mix ,int max) {
	int x = -1;
	char entry_s[99] = { 0 };
	printf("\n����:");
	while (x == -1)//������
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, mix, max);
		if (x == -1)printf("\n��������,����������:");
	}
	return x;
}

bool file_is_empty(std::string &file_path) {//�������ļ�·��
	struct stat buf;
	stat(file_path.c_str(), &buf);
	size_t size = buf.st_size;
	if (size == 0)//���ļ�Ϊ�� ,����true
		return true;
	else
		return false;
}

void savesituation(int a) {
	FILE *fp;//�ļ�ָ��
	fp = fopen("setting.txt", "w");
	fprintf(fp, "״̬:%d", a);
	fclose(fp);
}

int readsituation() {
	FILE *fp;//�ļ�ָ��
	int a;
	/*�ļ��Ĵ�*/
	fp = fopen("setting.txt", "rt+");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
	std::string file_path = "setting.txt";

	if (fp == NULL || file_is_empty(file_path)) {//�ж�����ļ�ָ��Ϊ��
		return -1;
	}
	fscanf_s(fp, "״̬:%d", &a);
	fclose(fp);
	return a;
}

