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
bool read_tenant_data(struct Rent** tailp)
{
	FILE* fp;
	fp = fopen("tenant.bin", "rb");

	if (fp == NULL)
	{
		printf("找不到指定文件!\n");
		return false;
	}
	struct Rent* p;
	p = NULL;
	while (fread(p, sizeof(struct Rent), 1, fp) == 1) // 确保成功读取
	{
		p = (struct Rent*)malloc(sizeof(struct Rent));
		assert(p);

		// 将新节点添加到链表
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}

	(*tailp)->next = NULL;  // 确保链表尾部的 next 指针为 NULL
	fclose(fp);
	return true;
}
bool write_tenant_data(struct Rent* headp) {
	FILE* fp;
	fp = fopen("tenant.bin", "wb");

	if (fp == NULL)
	{
		printf("找不到指定文件!\n");
		return false;
	}
	struct Rent* p;
	p = headp->next;
	while (p != NULL)
	{
		assert(p);
		fwrite(p, sizeof(struct Rent), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return true;
}
