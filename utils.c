//实用方法类
#include "data.h"
#include "models.h"
#include "utils.h"


//用于隐藏密码
void hideInput(char* buffer, int maxLength)
{
	int i = 0;
	char ch;
	while (i < maxLength - 1)
	{
		if (_kbhit())
		{
			ch = _getch();

			if (ch == 13)
			{
				buffer[i] = '\0';
				printf("\n");
				break;
			}
			else if (ch == 8 && i > 0)
			{
				printf("\b \b");
				i--;
			}
			else {
				printf("*");
				buffer[i++] = ch;
			}
		}
		else
		{
			Sleep(5);
		}
	}
	fflush(stdout);
}


//用于清屏
void clear()
{
	char wait;
	scanf("%c", &wait);
	if (wait == '\n')
		system("cls");
	else
		clear();
}