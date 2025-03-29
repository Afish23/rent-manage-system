//�н鹦��ʵ��
#include "agent.h"
/*
1.�������� �ٲ鿴���⻧ָ����˾ָ���Ŀ���ԤԼ��Ϣ;
�ڶ���͵Ŀ�����Ϣ���й��������޸ġ�ɾ���ȡ�������ϢҪ��¼:������
Ψһ���)������ʱ�䡢��Դ����͡��н顢����ʱ������ͷ���������
2.�ⷿ���� ��͵��ⷿ��Ϣ���й��������޸ġ�ɾ���ȡ��ⷿ��Ϣ��Ҫ��¼:�ⷿ��
��(Ψһ���)����Դ����͡��н顢��ͬǩ�����ڡ����⿪ʼ���ڡ�Ԥ�Ƴ�
��ʱ���������ݡ�
3.��Ϣ��ѯ �Ը�����Ϣ(����ԤԼ�������ⷿ��Ϣ)���в�ѯ�������򵥡���ϡ�����
ѯ�������ѯĳ��Դĳʱ����Ƿ�ա���ѯĳ���ԤԼ������Ϣ��
��С������������)
5.��Ϣͳ�� �Ը�����Ϣ(����ԤԼ�������ⷿ��Ϣ)����ͳ�ƣ���������һ���ԡ�������
��ͳ�ơ�Ԥ��ͳ�ơ�������ͳ�Ƶ�(����ͳ��ĳ�෿Դ��ƽ������ʱ��(��
��)�����н鹫˾���з�Դĳ��ʱ���ڵĳ����ʡ�ĳ����ܵ��ⷿ�����)
6.ϵͳά�� ���Լ����������ά��
7.���� �������������õĹ���
*/
void bubbleSort_Area(Flat** head, int jug)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // �������ֻ��һ���ڵ㣬��������  
	}
	int swapped;
	if (jug == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			while (ptr1->next != NULL)
			{
				if (ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;  
					ptr1->next = temp->next;// ����ptr1��nextָ��
					if (ptr1->next != NULL)//���һ��
					{
						ptr1->next->prev = ptr1;
					}
					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)//��ֹ��һ������
					{
						temp->prev->next = temp;
					}
					else
					{
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;
					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;
				}
			}
		} while (swapped); // �������û�н��������������  
	}
	if (jug == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor > ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
	}
	if (jug == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
	}
}
int  bubbleSort_more(Flat** head, int jug1, int jug2)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // �������ֻ��һ���ڵ㣬��������  
	}
	int swapped;
	if (jug1 == 1 && jug2 == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->floor > ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 1 && jug2 == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 3)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->Area > ptr1->next->Area)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 1)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->rent > ptr1->next->rent)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 2)
	{
		do
		{
			swapped = 0; // ��Ǳ����Ƿ��н�������  
			Flat* ptr1 = *head;
			Flat* end = NULL; // ���ڼ�¼��ǰ�ֱȽϵ��յ�  

			// ע�⣺���ǲ���Ҫlptr����Ϊ�������Ǵ�ͷ��ʼ�Ƚ�  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->floor > ptr1->next->floor)
				{
					// ����ptr1��ptr1->next�ڵ�  
					Flat* temp = ptr1->next;

					// ����ptr1��nextָ��  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// ����temp��prevָ��  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// ���temp���µ�ͷ�ڵ㣬����ͷָ��  
						*head = temp;
					}

					// ��temp���뵽ptr1֮ǰ  
					temp->next = ptr1;
					ptr1->prev = temp;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // ��Ƿ����˽���  
				}
				else
				{
					// ���û�н������ƶ�ptr1����һ���ڵ�  
					ptr1 = ptr1->next;

					// ���ptr1����һ�ֱȽϵ��յ㣬����end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // �������û�н��������������  
		return 1;
	}
	else if (jug1 == jug2)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
void agent_menu(User* user) {
    while (1) {
		printf("*********���ܲ˵�*********\n");
		printf("**                      **\n");
		printf("**0.     ��    ��       **\n");
		printf("**1.     ��������       **\n");
		printf("**2.     �ⷿ����       **\n");
		printf("**3.     ��Ϣ��ѯ       **\n");
		printf("**4.     ��Ϣ����       **\n");
		printf("**5.     ��Ϣͳ��       **\n");
		printf("**6.     ��������       **\n");
		printf("**7.     ɾ���˻�       **\n");
		printf("**                      **\n");
		printf("**************************\n");
		printf("��ѡ���ܣ�");
    }
}
/*
4.��Ϣ���� �Ը�����Ϣ(����ԤԼ�������ⷿ��Ϣ)�������򣬰�������һ���ԡ�������
������ȣ������ܶԲ�ѯ������ж�������(����Բ�ѯ�����ķ�Դ�������
*/
case 4:
	//������
	printf("*********�鿴��Դ*********\n");
	printf("**   ѡ��������������   **\n");
	printf("**0.     ��    ��       **\n");
	printf("**1.     ��    ��       **\n");
	printf("**2.     ��    ��       **\n");
	printf("**3.     �������       **\n");
	printf("**                      **\n");
	printf("**************************\n");
	scanf("%d", &choice_5);
	if (choice_5 == 0)
	{
		choose();
	}


	else
	{
		printf("******�Ƿ����������******\n");
		printf("**                      **\n");
		printf("**1.        ��          **\n");
		printf("**2.        ��          **\n");
		printf("**                      **\n");
		printf("**************************\n");
		scanf("%d", &jug9);
		choose();
		if (jug9 == 1)
		{
			printf("*******ѡ���Ҫ����*******\n");
			printf("**                      **\n");
			printf("**1.     ��    ��       **\n");
			printf("**2.     ��    ��       **\n");
			printf("**3.     �������       **\n");
			printf("**                      **\n");
			printf("**************************\n");
			scanf("%d", &choice_6);
			choose();
			int t;//�ֲ��������ڷ���ֵ�ж�
			bubbleSort_Area(&fl_head, choice_5);
			t = bubbleSort_more(&fl_head, choice_5, choice_6);
			if (t == 1)
			{
				printf("*********����ʽ*********\n");
				printf("**                      **\n");
				printf("**1.     ��С����       **\n");
				printf("**2.     �Ӵ�С       **\n");
				printf("**                      **\n");
				printf("**************************\n");
				scanf("%d", &jug7);
				choose();
				list_printfl_cu(fl_head, fl_tail, jug7);
				printf("���»س��Լ���\n");
				getchar();
				choose();
			}
			if (t == 2)
			{
				printf("������ѡ���������ͬ,��Ĭ��Ϊ����������\n");
				bubbleSort_Area(&fl_head, choice_5);
				printf("*********����ʽ*********\n");
				printf("**                      **\n");
				printf("**1.     ��С����       **\n");
				printf("**2.     �Ӵ�С       **\n");
				printf("**                      **\n");
				printf("**************************\n");
				scanf("%d", &jug7);
				choose();
				list_printfl_cu(fl_head, fl_tail, jug7);
				printf("���»س��Լ���\n");
				getchar();
				choose();
			}
			if (t == 3)
			{
				printf("����ȷ����\n");
				printf("���»س��Լ���\n");
				getchar();
				choose();
			}


		}
		if (jug9 == 2)
		{
			bubbleSort_Area(&fl_head, choice_5);
			choose();
			printf("*********����ʽ*********\n");
			printf("**                      **\n");
			printf("**1.     ��С����       **\n");
			printf("**2.     �Ӵ�С       **\n");
			printf("**                      **\n");
			printf("**************************\n");
			scanf("%d", &jug7);
			choose();
			list_printfl_cu(fl_head, fl_tail, jug7);
			printf("���»س��Լ���\n");
			getchar();
			choose();
		}
	}
	break;