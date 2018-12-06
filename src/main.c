#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <Windows.h>
#include "function.h"

/* 가사를 저장할 배열이다.
   notepad++로 가사파일을 열어보면 줄번호가 보이는데,
   해당 줄번호에 맞게 바로 코딩할 수 있게 0번 행을 버린다. */
char lyrics[100][50];


int main(void)
{
	SetConsoleTitle("Want You Gone"); //CMD 제목
	system("mode con cols=100 lines=40");	//콘솔 창 크기
	timeBeginPeriod(1);		//주기를 1ms로 설정
	Sleep(500);		//창이 설정된 것이 확실히 보일 때까지 대기

	//가사파일 불러오기
	int eof = readFile_lyrics("./res/lyrics.txt", lyrics, 100);
	if (eof == -1)
	{
		printf("파일 열기 실패! \n");
		system("pause");
		return 1;
	}

	textcolor(YELLOW);	//글자색 -> 노란색
	for (int i = 1; i <= eof; i++)
	{
		if (strcmp(lyrics[i], "----------------------------------\n") == 0)
		{
			system("cls");
			continue;
		}
		typeSimulation(lyrics[i], 70, 300);
	}
	

	//-----------------------------------------------
	//노래 종료
	system("cls");
	textcolor(RESET);	//글자색 초기화
	timeEndPeriod(1);	//설정된 주기를 해제
	system("pause");
	return 0;
}

/*  제작자: Lulin Pollux */
/*  MIT License
	해당 C코드파일(.c)은 MIT License에 따라 이용할 수 있습니다. */