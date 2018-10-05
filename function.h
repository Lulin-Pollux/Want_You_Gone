/********************************************************************************
*                                                                               *
* function.h -- Custom functions compilation                                    *
*                                                                               *
* Made by Lulin Pollux.          MIT License                                    *
*                                                                               *
********************************************************************************/


//�ܼ��� ���ڻ��� �����Ѵ�.
int textcolor(unsigned short color_number);
//���ڻ� ������ �� ���� ��� ���
#define RESET 7
#define DARK_BLUE 1
#define DARK_GREEN 2
#define BRIGHT_BLUE 3
#define DARK_RED 4
#define DARK_PURPLE 5
#define DARK_YELLOW 6
#define DARK_WHITE 7
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define SKY_BLUE 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15


//Ŀ���� ��ġ�� �����Ѵ�.
int setCursorPos(short x, short y);

//������ Ÿ�ڸ� ġ�� ��ó�� �ùķ��̼��Ѵ�.
void typeSimulation(char *array_char, unsigned int delay_ms, unsigned int end_delay_ms);

//���Ͽ��� ���縦 �о�´�.
int readFile_lyrics(const char *file_path, char bufferArray[][50], int row);