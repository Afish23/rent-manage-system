//���ݲ�������
#pragma once
#include "models.h"


// �ļ���������
bool read_user_data(struct User** tailp);
bool write_user_data(struct User* headp);

bool read_tenant_data(struct Rent** tailp);
bool write_tenant_data(struct Rent* headp);