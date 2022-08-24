/*
*	FileIOクラス
*	作成者：崎山
*/

#pragma once

#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class FileIO{
	private:

	public:
	char read(vector<char>& destination,char* file_path);
	int getSize(char* file_path);
	
};