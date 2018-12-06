#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <Windows.h>
#include "function.h"

/* ���縦 ������ �迭�̴�.
   notepad++�� ���������� ����� �ٹ�ȣ�� ���̴µ�,
   �ش� �ٹ�ȣ�� �°� �ٷ� �ڵ��� �� �ְ� 0�� ���� ������. */
char lyrics[100][50];


int main(void)
{
	SetConsoleTitle("Want You Gone"); //CMD ����
	system("mode con cols=100 lines=40");	//�ܼ� â ũ��
	timeBeginPeriod(1);		//�ֱ⸦ 1ms�� ����
	Sleep(500);		//â�� ������ ���� Ȯ���� ���� ������ ���

	//�������� �ҷ�����
	int eof = readFile_lyrics("./res/lyrics.txt", lyrics, 100);
	if (eof == -1)
	{
		printf("���� ���� ����! \n");
		system("pause");
		return 1;
	}

	textcolor(YELLOW);	//���ڻ� -> �����
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
	//�뷡 ����
	system("cls");
	textcolor(RESET);	//���ڻ� �ʱ�ȭ
	timeEndPeriod(1);	//������ �ֱ⸦ ����
	system("pause");
	return 0;
}

/*  ������: Lulin Pollux */
/*  MIT License
	�ش� C�ڵ�����(.c)�� MIT License�� ���� �̿��� �� �ֽ��ϴ�. */