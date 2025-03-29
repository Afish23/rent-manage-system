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


bool read_house_data(struct House** tailp)
{
	FILE* fp = fopen("house.bin", "rb");  // �����ļ���Ϊ "house_data.bin"

	if (fp == NULL) {
		printf("�޷����ļ���\n");
		return false;
	}

	struct House* p = NULL;

	// ��ȡ�ļ����ݣ�ֱ���ļ���β
	while (1) {
		p = (struct House*)malloc(sizeof(struct House));
		if (p == NULL) {
			printf("�ڴ����ʧ�ܣ�\n");
			fclose(fp);
			return false;
		}

		size_t read_count = fread(p, sizeof(struct House), 1, fp);
		if (read_count == 0) {
			if (feof(fp)) {
				break;  // �����ļ�ĩβ
			}
			else {
				printf("��ȡ����ʧ�ܣ�\n");
				free(p);
				fclose(fp);
				return false;
			}
		}

		// �������
		if (*tailp == NULL) {
			// ��һ��Ԫ�أ���ʼ��ͷ�ڵ�
			*tailp = p;
			p->prev = NULL;
			p->next = NULL;
		}
		else {
			// �ǵ�һ��Ԫ�أ����뵽����β��
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
		printf("�Ҳ���ָ���ļ�!\n");
		return false;
	}

	struct House* p;
	p = tailp;  // ������β����ʼ
	while (p != NULL) {
		assert(p);  // ȷ���ڵ���Ч
		fwrite(p, sizeof(struct House), 1, fp);  // д�뷿Դ����
		p = p->prev;  // �ƶ���ǰһ���ڵ�
	}

	fclose(fp);
	return true;
}
bool read_appointment_data(struct Appointment** tailp)
{
	FILE* fp = fopen("appointment.bin", "rb");
	if (fp == NULL) {
		printf("�Ҳ���ָ���ļ�!\n");
		return false;
	}

	// ��ȡ�ļ��е����ݵ�����
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
			*tailp = new_appointment;  // ͷָ��ָ���һ��Ԫ��
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
		printf("�Ҳ���ָ���ļ�!\n");
		return false;
	}

	// ������β����ʼд������
	struct Appointment* p = *tailp;
	while (p != NULL) {
		fwrite(p, sizeof(struct Appointment), 1, fp);
		p = p->prev;  // ����ǰһ���ڵ�
	}

	fclose(fp);
	return true;
}