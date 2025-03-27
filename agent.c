//中介功能实现
#include "agent.h"
/*
1.看房管理 ①查看被租户指定或公司指定的看房预约信息;
②对租客的看房信息进行管理，包括修改、删除等。看房信息要记录:看房编
唯一编号)、看房时间、房源、租客、中介、看房时长、租客反馈等数据
2.租房管理 租客的租房信息进行管理，包括修改、删除等。租房信息主要记录:租房编
号(唯一编号)、房源、租客、中介、合同签订日期、出租开始日期、预计出
租时长、等数据。
3.信息查询 对各种信息(包括预约看房和租房信息)进行查询，包括简单、组合、糊查
询，例如查询某房源某时间段是否空、查询某租客预约看房信息等
大小进行升序排序)
5.信息统计 对各种信息(包括预约看房和租房信息)进行统计，包括按单一属性、按多属
性统计、预设统计、按条件统计等(例如统计某类房源的平均出租时间(按
月)、本中介公司所有房源某段时间内的出租率、某租客总的租房情况等)
6.系统维护 对自己的密码进行维护
7.其他 可增加其他有用的功能
*/
void bubbleSort_Area(Flat** head, int jug)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // 空链表或只有一个节点，无需排序  
	}
	int swapped;
	if (jug == 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			while (ptr1->next != NULL)
			{
				if (ptr1->rent > ptr1->next->rent)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;  
					ptr1->next = temp->next;// 更新ptr1的next指针
					if (ptr1->next != NULL)//最后一个
					{
						ptr1->next->prev = ptr1;
					}
					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)//防止第一个出错
					{
						temp->prev->next = temp;
					}
					else
					{
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;
					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
	if (jug == 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor > ptr1->next->floor)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
	if (jug == 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area > ptr1->next->Area)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
	}
}
int  bubbleSort_more(Flat** head, int jug1, int jug2)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // 空链表或只有一个节点，无需排序  
	}
	int swapped;
	if (jug1 == 1 && jug2 == 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->floor > ptr1->next->floor)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
		return 1;
	}
	else if (jug1 == 1 && jug2 == 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->rent == ptr1->next->rent && ptr1->Area > ptr1->next->Area)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->rent > ptr1->next->rent)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
		return 1;
	}
	else if (jug1 == 2 && jug2 == 3)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->floor == ptr1->next->floor && ptr1->Area > ptr1->next->Area)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 1)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->rent > ptr1->next->rent)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
		return 1;
	}
	else if (jug1 == 3 && jug2 == 2)
	{
		do
		{
			swapped = 0; // 标记本轮是否有交换发生  
			Flat* ptr1 = *head;
			Flat* end = NULL; // 用于记录当前轮比较的终点  

			// 注意：我们不需要lptr，因为我们总是从头开始比较  
			while (ptr1->next != end)
			{
				if (ptr1->Area == ptr1->next->Area && ptr1->floor > ptr1->next->floor)
				{
					// 交换ptr1和ptr1->next节点  
					Flat* temp = ptr1->next;

					// 更新ptr1的next指针  
					ptr1->next = temp->next;
					if (ptr1->next != NULL)
					{
						ptr1->next->prev = ptr1;
					}

					// 更新temp的prev指针  
					temp->prev = ptr1->prev;
					if (temp->prev != NULL)
					{
						temp->prev->next = temp;
					}
					else {
						// 如果temp是新的头节点，更新头指针  
						*head = temp;
					}

					// 将temp插入到ptr1之前  
					temp->next = ptr1;
					ptr1->prev = temp;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = temp;
					}

					swapped = 1; // 标记发生了交换  
				}
				else
				{
					// 如果没有交换，移动ptr1到下一个节点  
					ptr1 = ptr1->next;

					// 如果ptr1是上一轮比较的终点，更新end  
					if (ptr1 == end)
					{
						end = end->next;
					}
				}
			}
		} while (swapped); // 如果本轮没有交换，则排序完成  
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
		printf("*********功能菜单*********\n");
		printf("**                      **\n");
		printf("**0.     退    出       **\n");
		printf("**1.     看房管理       **\n");
		printf("**2.     租房管理       **\n");
		printf("**3.     信息查询       **\n");
		printf("**4.     信息排序       **\n");
		printf("**5.     信息统计       **\n");
		printf("**6.     更改密码       **\n");
		printf("**7.     删除账户       **\n");
		printf("**                      **\n");
		printf("**************************\n");
		printf("请选择功能：");
    }
}
/*
4.信息排序 对各种信息(包括预约看房和租房信息)进行排序，包括按单一属性、按多属
性排序等，尽可能对查询结果进行多种排序(例如对查询出来的房源按照面积
*/
case 4:
	//空闲中
	printf("*********查看房源*********\n");
	printf("**   选择优先排序属性   **\n");
	printf("**0.     返    回       **\n");
	printf("**1.     租    金       **\n");
	printf("**2.     层    数       **\n");
	printf("**3.     房产面积       **\n");
	printf("**                      **\n");
	printf("**************************\n");
	scanf("%d", &choice_5);
	if (choice_5 == 0)
	{
		choose();
	}


	else
	{
		printf("******是否多属性排序******\n");
		printf("**                      **\n");
		printf("**1.        是          **\n");
		printf("**2.        否          **\n");
		printf("**                      **\n");
		printf("**************************\n");
		scanf("%d", &jug9);
		choose();
		if (jug9 == 1)
		{
			printf("*******选择次要属性*******\n");
			printf("**                      **\n");
			printf("**1.     租    金       **\n");
			printf("**2.     层    数       **\n");
			printf("**3.     房产面积       **\n");
			printf("**                      **\n");
			printf("**************************\n");
			scanf("%d", &choice_6);
			choose();
			int t;//局部变量用于返回值判断
			bubbleSort_Area(&fl_head, choice_5);
			t = bubbleSort_more(&fl_head, choice_5, choice_6);
			if (t == 1)
			{
				printf("*********排序方式*********\n");
				printf("**                      **\n");
				printf("**1.     从小到大       **\n");
				printf("**2.     从大到小       **\n");
				printf("**                      **\n");
				printf("**************************\n");
				scanf("%d", &jug7);
				choose();
				list_printfl_cu(fl_head, fl_tail, jug7);
				printf("按下回车以继续\n");
				getchar();
				choose();
			}
			if (t == 2)
			{
				printf("您两次选择的属性相同,已默认为单属性排序\n");
				bubbleSort_Area(&fl_head, choice_5);
				printf("*********排序方式*********\n");
				printf("**                      **\n");
				printf("**1.     从小到大       **\n");
				printf("**2.     从大到小       **\n");
				printf("**                      **\n");
				printf("**************************\n");
				scanf("%d", &jug7);
				choose();
				list_printfl_cu(fl_head, fl_tail, jug7);
				printf("按下回车以继续\n");
				getchar();
				choose();
			}
			if (t == 3)
			{
				printf("请正确输入\n");
				printf("按下回车以继续\n");
				getchar();
				choose();
			}


		}
		if (jug9 == 2)
		{
			bubbleSort_Area(&fl_head, choice_5);
			choose();
			printf("*********排序方式*********\n");
			printf("**                      **\n");
			printf("**1.     从小到大       **\n");
			printf("**2.     从大到小       **\n");
			printf("**                      **\n");
			printf("**************************\n");
			scanf("%d", &jug7);
			choose();
			list_printfl_cu(fl_head, fl_tail, jug7);
			printf("按下回车以继续\n");
			getchar();
			choose();
		}
	}
	break;