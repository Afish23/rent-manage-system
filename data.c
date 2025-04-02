//���ݴ洢ʵ��
#include "data.h"
#include "models.h"
#include "utils.h"


bool read_user_data(struct User** tailp)
{
	FILE* fp;
	fp = fopen("user.bin", "rb");

	if (fp == NULL)
	{
		printf("�Ҳ���ָ���ļ�!\n");
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
		printf("�Ҳ���ָ���ļ�!\n");
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

bool read_house_data(struct House** tailp) {
	FILE* fp;
	fp = fopen("house.bin", "rb");

	if (fp == NULL) {
		printf("�Ҳ���ָ���ļ�!\n");
		return false;
	}

	struct House* p = NULL;
	while (!feof(fp)) {
		p = (struct House*)malloc(sizeof(struct House));
		assert(p);

		// ��ȡ��Դ����
		fread(p, sizeof(struct House), 1, fp);

		// ���ӵ�����
		(*tailp)->next = p;
		p->prev = (*tailp);
		(*tailp) = p;
		p->next = NULL;
	}

	assert(p);

	// ���� tailp �����һ����Ч�ڵ�
	*tailp = p->prev;
	p->prev->next = NULL;

	// �ͷŵ����һ���ڵ㣨������Ҫ��
	free(p);
	p = NULL;

	fclose(fp);
	return true;
}
//д�뷿Դ
bool write_house_data(struct House* headp) {
	FILE* fp = fopen("house.bin", "wb");
	if (fp == NULL) {
		printf("�Ҳ���ָ���ļ�!\n");
		return false;
	}

	struct House* p = headp->next;
	while (p != NULL) {
		assert(p);
		fwrite(p, sizeof(struct House), 1, fp);
		p = p->next;  // �ƶ���ǰһ���ڵ�
	}

	fclose(fp);
	return true;
}