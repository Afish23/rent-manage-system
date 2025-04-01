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

