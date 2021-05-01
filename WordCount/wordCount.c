#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int countChar(char file[]);
int countWord(char file[]);

int main(int argc, char* argv[]) {
	// �ӿ���̨��ȡ���������ȡ�ļ���·��
	char* parameter = argv[1];
	char* input_file_name = argv[2];

	//�ɲ����ж�ͳ����
	if (parameter[1] == 'c')
		printf("�ַ�����%d\n", countChar(input_file_name));
	if (parameter[1] == 'w')
		printf("��������%d\n", countWord(input_file_name));

	return 0;
}

// ͳ���ַ���
int countChar(char file[]) {
	FILE* f = fopen(file, "r");

	int count = 0;
	char c = fgetc(f);
	while (c != EOF) {
		// Ҫ��1�������Ǵ�Ӣ���ı��ļ����ո�ˮƽ�Ʊ�������з������ַ�
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
			|| c == ' ' || c == '\t' || c == '\n')
			count++;
		c = fgetc(f);
	}
	fclose(f);

	return count;
}

// ͳ�Ƶ�����
int countWord(char file[]) {
	FILE* f = fopen(file, "r");

	int count = 0;
	int line = 0;
	char c = fgetc(f);
	while (c != EOF) {
		if (c == '\n')
			line++;
		if (c == ' ' || c == ',') {
			// Ҫ��2���������ʵ���Ч��У��
			count++;
		}
		c = fgetc(f);
	}

	/*
	�����е��У��޻س��������������β�����һ�����ʣ�
	���򣬶���ֻ���ۼ���������Ϊÿ�����һ�������ۼ�֮��
	*/
	if (!line)
		count += 1;
	fclose(f);

	return count + line;
}