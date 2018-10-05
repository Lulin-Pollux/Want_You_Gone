/********************************************************************************
*                                                                               *
* function.h -- Custom functions compilation                                    *
*                                                                               *
* Made by Lulin Pollux.          MIT License                                    *
*                                                                               *
********************************************************************************/


//콘솔의 글자색을 변경한다.
int textcolor(unsigned short color_number);
//글자색 변경할 때 숫자 대신 사용
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


//커서의 위치를 변경한다.
int setCursorPos(short x, short y);

//손으로 타자를 치는 것처럼 시뮬레이션한다.
void typeSimulation(char *array_char, unsigned int delay_ms, unsigned int end_delay_ms);

//파일에서 가사를 읽어온다.
int readFile_lyrics(const char *file_path, char bufferArray[][50], int row);