#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int countChar(char file[]);
int countWord(char file[]);

int main(int argc, char* argv[]) {
	// 从控制台获取参数和需读取文件的路径
	char* parameter = argv[1];
	char* input_file_name = argv[2];

	//由参数判断统计量
	if (parameter[1] == 'c')
		printf("字符数：%d\n", countChar(input_file_name));
	if (parameter[1] == 'w')
		printf("单词数：%d\n", countWord(input_file_name));

	return 0;
}

// 统计字符数
int countChar(char file[]) {
	FILE* f = fopen(file, "r");

	int count = 0;
	char c = fgetc(f);
	while (c != EOF) {
		// 要求1：仅考虑纯英文文本文件，空格，水平制表符，换行符均算字符
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
			|| c == ' ' || c == '\t' || c == '\n')
			count++;
		c = fgetc(f);
	}
	fclose(f);

	return count;
}

// 统计单词数
int countWord(char file[]) {
	FILE* f = fopen(file, "r");

	int count = 0;
	int line = 0;
	char c = fgetc(f);
	while (c != EOF) {
		if (c == '\n')
			line++;
		if (c == ' ' || c == ',') {
			// 要求2：不做单词的有效性校验
			count++;
		}
		c = fgetc(f);
	}

	/*
	若仅有单行（无回车），则需加上行尾的最后一个单词；
	否则，多行只需累加行数，是为每行最后一个单词累加之和
	*/
	if (!line)
		count += 1;
	fclose(f);

	return count + line;
}