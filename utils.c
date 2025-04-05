//ʵ�÷�����
#include "data.h"
#include "models.h"
#include "utils.h"

//����ģ��ƥ��
int editDistance(const char* str1, const char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	// ��̬����dp����
	int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
	for (int i = 0; i <= len1; i++) {
		dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
	}

	// ��ʼ��dp����
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

	// ��ȡ���ս��
	int result = dp[len1][len2];

	// �ͷ�dp������ڴ�
	for (int i = 0; i <= len1; i++) {
		free(dp[i]);
	}
	free(dp);

	return result;
}

//������������
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


//��������
void clear()
{
	char wait;
	scanf("%c", &wait);
	if (wait == '\n')
		system("cls");
	else
		clear();
}

//���ڴ�ӡ����

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