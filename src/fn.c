#include <stdio.h>
#include <Windows.h>


//콘솔의 글자색을 변경한다.
int textcolor(unsigned short color_number)
{
	int retval = SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
	return retval;
}

//커서의 위치를 변경한다.
int setCursorPos(short x, short y)
{
	COORD position = { x - 1, y - 1 };
	int retval = SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	return retval;
}

//손으로 타자를 치는 것처럼 시뮬레이션한다.
void typeSimulation(char *array_char, unsigned int delay_ms, unsigned int end_delay_ms)
{
	int len = (int)strlen(array_char);

	//배열 원소를 1개씩 지연시키며 출력한다.
	for (int i = 0; i < len; i++)
	{
		printf("%c", array_char[i]);
		Sleep(delay_ms);
	}

	//한 문장 출력이 끝난뒤에 대기할 시간이다.
	if (end_delay_ms != 0)
		Sleep(end_delay_ms);
}

//파일에서 가사를 읽어온다.
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