//数据存储实现
#include "data.h"
#include "models.h"
#include "utils.h"


bool read_user_data(struct User** tailp)
{
	FILE* fp;
	fp = fopen("user.bin", "rb");

	if (fp == NULL)
	{
		printf("找不到指定文件!\n");
		return false;
	}
	struct User* p;
	p = NULL;
	while (!feof(fp))
	{
		p = (struct User*)malloc(sizeof(struct User));
		assert(p);
		fread(p, sizeof(struct User), 1, fp);
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}
	assert(p);
	*tailp = p->prev;
	p->prev->next = NULL;
	free(p);
	p = NULL;
	fclose(fp);
	return true;
}

bool write_user_data(struct User* headp) {
	FILE* fp;
	fp = fopen("user.bin", "wb");

	if (fp == NULL)
	{
		printf("找不到指定文件!\n");
		return false;
	}
	struct User* p;
	p = headp->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct User), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}


bool read_house_data(struct House** tailp)
{
	FILE* fp = fopen("house.bin", "rb");  // 假设文件名为 "house_data.bin"

	if (fp == NULL) {
		printf("无法打开文件！\n");
		return false;
	}

	struct House* p = NULL;

	// 读取文件内容，直到文件结尾
	while (1) {
		p = (struct House*)malloc(sizeof(struct House));
		if (p == NULL) {
			printf("内存分配失败！\n");
			fclose(fp);
			return false;
		}

		size_t read_count = fread(p, sizeof(struct House), 1, fp);
		if (read_count == 0) {
			if (feof(fp)) {
				break;  // 到达文件末尾
			}
			else {
				printf("读取数据失败！\n");
				free(p);
				fclose(fp);
				return false;
			}
		}

		// 链表操作
		if (*tailp == NULL) {
			// 第一个元素，初始化头节点
			*tailp = p;
			p->prev = NULL;
			p->next = NULL;
		}
		else {
			// 非第一个元素，插入到链表尾部
			(*tailp)->next = p;
			p->prev = *tailp;
			p->next = NULL;
			*tailp = p;
		}
	}

	fclose(fp);
	return true;
}



bool write_house_data(struct House** tailp)
{
	FILE* fp;
	fp = fopen("house.bin", "wb");

	if (fp == NULL) {
		printf("找不到指定文件!\n");
		return false;
	}

	struct House* p;
	p = tailp;  // 从链表尾部开始
	while (p != NULL) {
		assert(p);  // 确保节点有效
		fwrite(p, sizeof(struct House), 1, fp);  // 写入房源数据
		p = p->prev;  // 移动到前一个节点
	}

	fclose(fp);
	return true;
}
bool read_appointment_data(struct Appointment** tailp)
{
	FILE* fp = fopen("appointment.bin", "rb");
	if (fp == NULL) {
		printf("找不到指定文件!\n");
		return false;
	}

	// 读取文件中的数据到链表
	struct Appointment* p = NULL;
	struct Appointment* last = NULL;

	while (true) {
		struct Appointment* new_appointment = (struct Appointment*)malloc(sizeof(struct Appointment));
		if (fread(new_appointment, sizeof(struct Appointment), 1, fp) != 1) {
			free(new_appointment);
			break;
		}

		if (last != NULL) {
			last->next = new_appointment;
			new_appointment->prev = last;
		}
		else {
			*tailp = new_appointment;  // 头指针指向第一个元素
		}

		last = new_appointment;
	}

	fclose(fp);
	return true;
}
bool write_appointment_data(struct Appointment** tailp)
{
	FILE* fp = fopen("appointment.bin", "wb");
	if (fp == NULL) {
		printf("找不到指定文件!\n");
		return false;
	}

	// 从链表尾部开始写入数据
	struct Appointment* p = *tailp;
	while (p != NULL) {
		fwrite(p, sizeof(struct Appointment), 1, fp);
		p = p->prev;  // 遍历前一个节点
	}

	fclose(fp);
	return true;
}