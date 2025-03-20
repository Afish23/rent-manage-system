//实用方法类
#include "auth.h"
#include "admin.h"
#include "agent.h"
#include "tenant.h"
#include "store.h"
#include "models.h"

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