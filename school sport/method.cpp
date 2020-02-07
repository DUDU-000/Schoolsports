#include<iostream>
#include<stdio.h>
#include"method.h"


//若entry在mix与max之间,则返回int型的entry,否则,返回0,传入的是char型数组
int entrycheck(char entry[] , int mix,int max) {
	int result=0;
	int byte = strlen(entry);
	for (int i = 0; i < strlen(entry); i++) {
		if (48 + mix / pow(10, byte - 1) <= entry[i] && entry[i] <= 48 + max / pow(10, byte - 1))
		{
			result = result * 10 + entry[i] - 48;
			byte--;
		}
		else return 0;
	}
	return result;
}
