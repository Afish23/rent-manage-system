//实用方法类
#include "data.h"
#include "models.h"
#include "utils.h"

//用于模糊匹配
int editDistance(const char* str1, const char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	// 动态分配dp数组
	int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
	for (int i = 0; i <= len1; i++) {
		dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
	}

	// 初始化dp数组
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0) {
				dp[i][j] = i;
			}
			else {
				dp[i][j] = (str1[i - 1] == str2[j - 1]) ? dp[i - 1][j - 1] :
					(1 + (dp[i - 1][j - 1] < dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j]) < dp[i][j - 1] ? dp[i - 1][j - 1] : dp[i][j - 1]);
			}
		}
	}

	// 获取最终结果
	int result = dp[len1][len2];

	// 释放dp数组的内存
	for (int i = 0; i <= len1; i++) {
		free(dp[i]);
	}
	free(dp);

	return result;
}

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

//用于打印链表

void printList(struct Rent* head) {
	struct Rent* current = head; 
	while (current != NULL) {
		printf("id: %d\n", current->id);
		printf("contractTime: %d\n", current->contractTime);
		printf("rentStartTime: %d\n", current->rentStartTime);
		printf("rentDuration: %d\n", current->rentDuration);
		printf("statement: %d\n", current->statement);
		printf("------------------------\n");
		//break;
		current = current->next;
	}
}

void printHouseList(struct House* head) {
	struct House* current = head;
	while (current != NULL) {
		printf("房屋 ID: %d\n", current->id);
		printf("房屋编号: %d\n", current->house_id);
		printf("房东: %s\n", current->houseowner);
		printf("房东电话: %s\n", current->number);
		printf("城市: %s\n", current->city);
		printf("所在城区: %s\n", current->urban);
		printf("小区: %s\n", current->community);
		printf("楼层: %d\n", current->floor);

		printf("朝向: ");
		switch (current->toward) {
		case N: printf("北\n"); break;
		case S: printf("南\n"); break;
		case E: printf("东\n"); break;
		case W: printf("西\n"); break;
		case SE: printf("东南\n"); break;
		case NE: printf("东北\n"); break;
		case SW: printf("西南\n"); break;
		case SN: printf("南北\n"); break;
		default: printf("未知\n"); break;
		}

		printf("房间数: %d\n", current->room);
		printf("厅数: %d\n", current->hall);
		printf("面积: %.2f\n", current->Area);
		printf("装修情况: %s\n", current->fitment);
		printf("租金: %.2f\n", current->rent);
		printf("中介费: %.2f\n", current->agency_fee);
		printf("押金: %.2f\n", current->deposit);
		printf("租赁开始时间: %d\n", current->rentStartTime);
		printf("租期: %d\n", current->rentDuration);
		printf("中介姓名: %s\n", current->agentname);
		printf("租客姓名: %s\n", current->tenantname);
		printf("状态: %s\n", current->status == 0 ? "可租" : "已租");
		printf("------------------------\n");

		current = current->next;
	}
	getchar();
	clear();
}
