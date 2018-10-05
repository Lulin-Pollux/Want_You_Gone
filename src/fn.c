#include <stdio.h>
#include <Windows.h>


//�ܼ��� ���ڻ��� �����Ѵ�.
int textcolor(unsigned short color_number)
{
	int retval = SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
	return retval;
}

//Ŀ���� ��ġ�� �����Ѵ�.
int setCursorPos(short x, short y)
{
	COORD position = { x - 1, y - 1 };
	int retval = SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	return retval;
}

//������ Ÿ�ڸ� ġ�� ��ó�� �ùķ��̼��Ѵ�.
void typeSimulation(char *array_char, unsigned int delay_ms, unsigned int end_delay_ms)
{
	int len = (int)strlen(array_char);

	//�迭 ���Ҹ� 1���� ������Ű�� ����Ѵ�.
	for (int i = 0; i < len; i++)
	{
		printf("%c", array_char[i]);
		Sleep(delay_ms);
	}

	//�� ���� ����� �����ڿ� ����� �ð��̴�.
	if (end_delay_ms != 0)
		Sleep(end_delay_ms);
}

//���Ͽ��� ���縦 �о�´�.
int readFile_lyrics(const char *file_path, char bufferArray[][50], int row)
{
	int eof = 0;
	FILE *lyrics_rfp;
	if (fopen_s(&lyrics_rfp, file_path, "r") != 0)
		return -1;

	for (int i = 1; i < row; i++)
	{
		fgets(bufferArray[i], 50, lyrics_rfp);

		if (feof(lyrics_rfp))
		{
			eof = i;
			break;
		}
	}

	fclose(lyrics_rfp);
	return eof;
}