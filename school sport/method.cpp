#include<iostream>
#include<stdio.h>
#include"method.h"


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

bool file_is_empty(std::string &file_path) {//�������ļ�·��
	struct stat buf;

	stat(file_path.c_str(), &buf);

	size_t size = buf.st_size;

	if (size == 0)//���ļ�Ϊ�� ,����true
		return true;
	else
		return false;
}
