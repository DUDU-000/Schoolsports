#pragma once
#include<string>

int entrycheck(char entry[], int mix, int max);

int entrycheckandreinput(int mix, int max);

bool file_is_empty(std::string & file_path);

void savesituation(int a);

int readsituation();
