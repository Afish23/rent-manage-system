#include "statistics.h"
//ͳ��¥��
void statisHousesFloor(struct House* head) {
    struct House* p = head;
    int targetFloor;
    printf("��������Ҫͳ�Ƶ�¥������");
    scanf("%d", &targetFloor);
    int countFloor = 0;
    while (p != NULL) {
        if (p->floor == targetFloor) {
            countFloor++;


        }
        p = p->next; // ��������
    }
    printf("%d¥�������Ϊ��%d\n", targetFloor, countFloor);
    printf("�밴�س���������");
    getchar();
    clear();
}

void statisHousesToward(struct House* head) {
    struct House* p = head;
    printf("��������Ҫͳ�Ƶĳ���0-��, 1-��, 2-��, 3-��, 4-����, 5-����, 6-����, 7-��������");
    int targetToward;
    scanf("%d", &targetToward);

    int countToward = 0;
    while (p != NULL) {
        if (p->toward == targetToward) {
            countToward++;
        }
        p = p->next; // ��������
    }
    printf("���� %d �ķ�Դ����Ϊ��%d\n", targetToward, countToward);
    printf("�밴�س���������");
    getchar(); // �ȴ��س�
    clear();
}

void statisHousesRent(struct House* head) {
    struct House* p = head;
    float targetRentMin, targetRentMax;
    printf("��������Ҫͳ�Ƶ����Χ����С��� �����𣩣�");
    scanf("%f %f", &targetRentMin, &targetRentMax);

    int countRent = 0;
    while (p != NULL) {
        if (p->rent >= targetRentMin && p->rent <= targetRentMax) {
            countRent++;
        }
        p = p->next; // ��������
    }
    printf("����� %.2f �� %.2f ֮��ķ�Դ����Ϊ��%d\n", targetRentMin, targetRentMax, countRent);
    printf("�밴�س���������");
    getchar(); // �ȴ��س�
    clear();
}

void statisHousesArea(struct House* head) {
    struct House* p = head;
    float targetAreaMin, targetAreaMax;
    printf("��������Ҫͳ�Ƶ������Χ����С��� ����������");
    scanf("%f %f", &targetAreaMin, &targetAreaMax);

    int countArea = 0;
    while (p != NULL) {
        if (p->Area >= targetAreaMin && p->Area <= targetAreaMax) {
            countArea++;
        }
        p = p->next; // ��������
    }
    printf("����� %.2f �� %.2f ֮��ķ�Դ����Ϊ��%d\n", targetAreaMin, targetAreaMax, countArea);
    printf("�밴�س���������");
    getchar(); // �ȴ��س�
    clear();
}

void statisHousesRoom(struct House* head) {
    struct House* p = head;
    int targetRoom;
    printf("��������Ҫͳ�Ƶķ��������ң���");
    scanf("%d", &targetRoom);

    int countRoom = 0;
    while (p != NULL) {
        if (p->room == targetRoom) {
            countRoom++;
        }
        p = p->next; // ��������
    }
    printf("%d�ҵķ�Դ����Ϊ��%d\n", targetRoom, countRoom);
    printf("�밴�س���������");
    getchar(); // �ȴ��س�
    clear();
}

void statisHousesFitment(struct House* head) {
    struct House* p = head;
    printf("��������Ҫͳ�Ƶ�װ���������װ��/δװ�ޣ���");
    char targetFitment[10];
    scanf("%s", targetFitment);

    int countFitment = 0;
    while (p != NULL) {
        if (strcmp(p->fitment, targetFitment) == 0) {
            countFitment++;
        }
        p = p->next; // ��������
    }
    printf("װ�����Ϊ %s �ķ�Դ����Ϊ��%d\n", targetFitment, countFitment);
    printf("�밴�س���������");
    getchar(); // �ȴ��س�
    clear();
}



// �����������Χͳ�Ʒ�Դ����
void statisRentAndArea(struct House* head) {
    struct House* p = head;
    float minRent, maxRent, minArea, maxArea;

    // �������������Χ
    printf("���������ķ�Χ����С���������𣩣�\n");
    printf("��С���");
    scanf("%f", &minRent);
    printf("������");
    scanf("%f", &maxRent);

    printf("����������ķ�Χ����С���������������\n");
    printf("��С�����");
    scanf("%f", &minArea);
    printf("��������");
    scanf("%f", &maxArea);

    int count = 0;

    // ��������ͳ�Ʒ��������ķ�Դ
    while (p != NULL) {
        if (p->rent >= minRent && p->rent <= maxRent && p->Area >= minArea && p->Area <= maxArea) {
            count++;
        }
        p = p->next; // ������һ����Դ
    }

    // ���ͳ�ƽ��
    printf("���ΧΪ [%.2f, %.2f] �������ΧΪ [%.2f, %.2f] �ķ�Դ����Ϊ��%d\n",
        minRent, maxRent, minArea, maxArea, count);
    printf("�밴�س���������");
    getchar(); // ��ȡ���з�
    clear();
}
// �������¥�㷶Χͳ�Ʒ�Դ����
void statisTowardAndFloor(struct House* head) {
    struct House* p = head;
    int minFloor, maxFloor;
    enum Toward minToward, maxToward;

    // ���볯��Χ��¥�㷶Χ
    printf("������¥��ķ�Χ����С¥������¥�㣩��\n");
    printf("��С¥�㣺");
    scanf("%d", &minFloor);
    printf("���¥�㣺");
    scanf("%d", &maxFloor);

    printf("�����볯��Χ��0-��, 1-��, 2-��, 3-��, 4-����, 5-����, 6-����, 7-��������\n");
    printf("��С����");
    scanf("%d", &minToward);
    printf("�����");
    scanf("%d", &maxToward);

    int count = 0;

    // ��������ͳ�Ʒ��������ķ�Դ
    while (p != NULL) {
        if (p->floor >= minFloor && p->floor <= maxFloor && p->toward >= minToward && p->toward <= maxToward) {
            count++;
        }
        p = p->next;
    }

    // ���ͳ�ƽ��
    printf("¥�㷶ΧΪ [%d, %d] �ҳ���ΧΪ [%d, %d] �ķ�Դ����Ϊ��%d\n",
        minFloor, maxFloor, minToward, maxToward, count);
    printf("�밴�س���������");
    getchar();
    clear();
}
// ������װ�����ͳ�Ʒ�Դ����
void statisRentAndFitment(struct House* head) {
    struct House* p = head;
    float minRent, maxRent;
    char fitment[10];

    // �������Χ��װ�����
    printf("���������ķ�Χ����С���������𣩣�\n");
    printf("��С���");
    scanf("%f", &minRent);
    printf("������");
    scanf("%f", &maxRent);

    printf("������װ����������磺�򵥡���װ�޵ȣ���\n");
    printf("װ�������");
    scanf("%s", fitment);

    int count = 0;

    // ��������ͳ�Ʒ��������ķ�Դ
    while (p != NULL) {
        if (p->rent >= minRent && p->rent <= maxRent && strcmp(p->fitment, fitment) == 0) {
            count++;
        }
        p = p->next;
    }

    // ���ͳ�ƽ��
    printf("���ΧΪ [%.2f, %.2f] ��װ�����Ϊ %s �ķ�Դ����Ϊ��%d\n",
        minRent, maxRent, fitment, count);
    printf("�밴�س���������");
    getchar();
    clear();
}
// ��С����¥�㷶Χͳ�Ʒ�Դ����
void statisCommunityAndFloor(struct House* head) {
    struct House* p = head;
    char community[20];
    int minFloor, maxFloor;

    // ����С������¥�㷶Χ
    printf("������С�����ƣ�\n");
    printf("С�����ƣ�");
    scanf("%s", community);

    printf("������¥��ķ�Χ����С¥������¥�㣩��\n");
    printf("��С¥�㣺");
    scanf("%d", &minFloor);
    printf("���¥�㣺");
    scanf("%d", &maxFloor);

    int count = 0;

    // ��������ͳ�Ʒ��������ķ�Դ
    while (p != NULL) {
        if (strcmp(p->community, community) == 0 && p->floor >= minFloor && p->floor <= maxFloor) {
            count++;
        }
        p = p->next;
    }

    // ���ͳ�ƽ��
    printf("С�� %s ��¥�㷶ΧΪ [%d, %d] �ķ�Դ����Ϊ��%d\n",
        community, minFloor, maxFloor, count);
    printf("�밴�س���������");
    getchar();
    clear();
}
// ���������ͳ���ͳ�Ʒ�Դ����
void statisRoomAndToward(struct House* head) {
    struct House* p = head;
    int minRoom, maxRoom;
    enum Toward minToward, maxToward;

    // ���뷿������Χ�ͳ���Χ
    printf("�����뷿�����ķ�Χ����С����������󷿼�������\n");
    printf("��С��������");
    scanf("%d", &minRoom);
    printf("��󷿼�����");
    scanf("%d", &maxRoom);

    printf("�����볯��Χ��0-��, 1-��, 2-��, 3-��, 4-����, 5-����, 6-����, 7-��������\n");
    printf("��С����");
    scanf("%d", &minToward);
    printf("�����");
    scanf("%d", &maxToward);

    int count = 0;

    // ��������ͳ�Ʒ��������ķ�Դ
    while (p != NULL) {
        if (p->room >= minRoom && p->room <= maxRoom && p->toward >= minToward && p->toward <= maxToward) {
            count++;
        }
        p = p->next;
    }

    // ���ͳ�ƽ��
    printf("��������ΧΪ [%d, %d] �ҳ���ΧΪ [%d, %d] �ķ�Դ����Ϊ��%d\n",
        minRoom, maxRoom, minToward, maxToward, count);
    printf("�밴�س���������");
    getchar();
    clear();
}


int calculateTotalDays(int date) {
    int year = date / 10000;      // ��ȡ���
    int month = (date / 100) % 100; // ��ȡ�·�
    int day = date % 100;         // ��ȡ����

    int totalDays = 0;



    totalDays = year * 365 + month * 30 + day; // ���ϸ��µ�����

    return totalDays;
}


void statisAverageRentDuration(struct House* head) {
    struct House* p = head;
    int totalDuration = 0; // �ܳ�������
    int totalHouses = 0;   // ��Դ����

    while (p != NULL) {
        if (p->status == 1) { // ��ͳ������ķ�Դ
            totalDuration += calculateTotalDays(p->rentDuration); // �ۼӳ�������
            totalHouses++; // �������ⷿԴ����
        }
        p = p->next; // ��������
    }

    if (totalHouses > 0) {
        // ��������ת��Ϊ�£�����һ����30�죩
        float averageDuration = (float)totalDuration / totalHouses / 30.0;
        printf("�������ⷿԴ��ƽ������ʱ��Ϊ��%.2f ����\n", averageDuration);
    }
    else {
        printf("û������ķ�Դ��\n");
    }

    printf("�밴�س���������");
    getchar();
    clear();
}


void statisOccupancyRate(struct House* head) {
    int totalHouses = 0;    // ��Դ����
    int rentedHouses = 0;   // ���ⷿԴ��

    struct House* current = head;

    // ������������
    while (current != NULL) {
        totalHouses++;  // ÿ����һ����Դ����Դ��������
        if (current->status == 1) {
            rentedHouses++;  // ���״̬Ϊ���⣬���ⷿԴ������
        }
        current = current->next;  // ����������һ����Դ
    }
    float rate = (rentedHouses / totalHouses) * 100;
    if (totalHouses == 0) {
        printf("��ǰû�з��ӳ��⣡");
    }
    else { printf("������Ϊ%f%%", rate); }
    // ���������
    printf("�밴�س���������");
    getchar();
    clear();

}


// ͳ��ԤԼ�����ĺ���
void statisTotalAppointments(struct Appointment* head) {
    int count = 0;
    struct Appointment* current = head->next;

    // ��������ֱ��ĩβ
    while (current != NULL) {
        count++;
        current = current->next;
    }

    printf("��ԤԼ������%d\n", count);

    printf("�밴�س���������");
    getchar();
    clear();

    return count;
}
// ͳ�������ԤԼ������
void statisCompletedAppointments(struct Appointment* head) {
    int count = 0;
    struct Appointment* current = head->next;

    // ��������ֱ��ĩβ
    while (current != NULL) {
        // ���ԤԼ����ɣ��� statement Ϊ 1���������
        if (current->statement == 1) {
            count++;
        }
        current = current->next;
    }

    // ��������ԤԼ������
    printf("����ɵ�ԤԼ������%d\n", count);


    printf("�밴�س���������");
    getchar();

    clear();
}


// ͳ��ԤԼʱ���ͼ���ƽ��ʱ��
void statisAppointmentDuration(struct Appointment* head) {
    float totalDuration = 0;  // �ۼ���ʱ��
    float count = 0;          // ��¼ԤԼ����
    struct Appointment* current = head->next;

    // ��������ֱ��ĩβ
    while (current != NULL) {
        totalDuration += current->duration;  // �ۼӵ�ǰԤԼ��ʱ��
        count++;  // ������ԤԼ��
        current = current->next;
    }



    // ���㲢���ƽ��ʱ��
    if (count > 0) {
        double averageDuration = (double)totalDuration / count;

        printf("��ԤԼʱ����%f\n", totalDuration);
        printf("ƽ��ԤԼʱ����%.2f\n", averageDuration);
    }
    else {
        printf("û��ԤԼ��¼��\n");
    }


    printf("�밴�س���������");
    getchar();

    clear();
}


// ͳ��ʱ����ڵ�ԤԼ����
void statisAppointmentInPeriod(struct Appointment* head) {
    int startDate, endDate;
    int count = 0;  // ��¼��ʱ����ڵ�ԤԼ����
    struct Appointment* current = head;

    // �û�����ʱ���
    printf("��������ʼʱ�䣨��ʽ YYYYMMDD����");
    scanf("%d", &startDate);
    printf("���������ʱ�䣨��ʽ YYYYMMDD����");
    scanf("%d", &endDate);

    // ��������ֱ��ĩβ
    while (current != NULL) {
        if (current->time >= startDate && current->time <= endDate) {
            count++;  // ��ǰԤԼ������ʱ�����
        }
        current = current->next;
    }

    // ���ͳ�ƽ��
    printf("��ʱ��� %d �� %d ֮���ԤԼ����Ϊ��%d\n", startDate, endDate, count);

    // �ȴ��û������Լ���
    printf("�밴�س���������");
    getchar();
    getchar();

    clear();
}


// ���������ͳ��ԤԼ������ԤԼʱ�����ʱ��
void statisAppointmentByTenant(struct Appointment* head) {
    char tenantName[20];       // ���ڴ洢�û�������������
    int count = 0;             // ͳ��ԤԼ����
    int totalDuration = 0;     // ͳ����ʱ��
    struct Appointment* current = head;

    // �û������������
    printf("���������������");
    scanf("%s", tenantName);

    // �����������Ҹ���͵�ԤԼ
    while (current != NULL) {
        if (strcmp(current->tenantname, tenantName) == 0) {
            count++;  // �������ԤԼ
            totalDuration += current->duration;  // �ۼ�ʱ��
            printf("ԤԼʱ�䣺%d, ԤԼʱ����%d����\n", current->time, current->duration);
        }
        current = current->next;
    }

    // ���ͳ�ƽ��
    if (count > 0) {
        printf("��� %s ��ԤԼ����Ϊ��%d\n", tenantName, count);
        printf("��� %s ��ԤԼ��ʱ��Ϊ��%d����\n", tenantName, totalDuration);
    }
    else {
        printf("δ�ҵ���� %s ���κ�ԤԼ��\n", tenantName);
    }


    printf("�밴�س���������");
    getchar();
    getchar();
    clear();
}


// ͳ���ⷿ�����ĺ���
void statisTotalRents(struct Rent* head) {
    int count = 0;  // ����ͳ���ⷿ����
    struct Rent* current = head->next;  // ���ڱ�������

    // ��������ֱ��ĩβ
    while (current != NULL) {
        count++;  // �����ⷿ����
        current = current->next;  // �ƶ�����һ���ⷿ�ڵ�
    }

    // ����ⷿ����
    printf("�ⷿ������%d\n", count);


    printf("�밴�س���������");
    getchar();
    getchar();
    clear();

}

// ͳ���ⷿ���ڵ��ⷿ������֧������ʱ��Σ���ʽ��YYYYMMDD��
void statisRentDate(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int startDate, endDate;

    // ����ʱ��Σ���ʼ���ںͽ������ڣ�
    printf("��������ʼ�ⷿ���ڣ���ʽ��YYYYMMDD����");
    scanf("%d", &startDate);
    printf("����������ⷿ���ڣ���ʽ��YYYYMMDD����");
    scanf("%d", &endDate);

    // ȷ�������ʱ����Ǻ���ģ���ʼ���ڲ����ڽ������ڣ�
    if (startDate > endDate) {
        printf("������ʼ���ڲ������ڽ������ڡ�\n");
        return;
    }

    // �����������ÿ���ⷿ���ⷿ�����Ƿ���ָ����ʱ�����
    while (current != NULL) {
        if (current->rentStartTime >= startDate && current->rentStartTime <= endDate) {
            count++;
        }
        current = current->next;
    }

    // ����ⷿ������ʱ����ڵ��ⷿ����
    printf("�ⷿ������ %d �� %d ֮����ⷿ������%d\n", startDate, endDate, count);

    printf("�밴�س���������");
    getchar();
    getchar();
    clear();
}



// ͳ�ƺ�ͬ���ڵ��ⷿ������֧������ʱ���
void statisContractDate(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int startDate, endDate;

    // ����ʱ��Σ���ʼ���ںͽ������ڣ�
    printf("��������ʼ��ͬ���ڣ���ʽ��YYYYMMDD����");
    scanf("%d", &startDate);
    printf("�����������ͬ���ڣ���ʽ��YYYYMMDD����");
    scanf("%d", &endDate);

    // ȷ�������ʱ����Ǻ���ģ���ʼ���ڲ����ڽ������ڣ�
    if (startDate > endDate) {
        printf("������ʼ���ڲ������ڽ������ڡ�\n");
        return;
    }

    // �����������ÿ���ⷿ�ĺ�ͬ�����Ƿ���ָ����ʱ�����
    while (current != NULL) {
        if (current->contractTime >= startDate && current->contractTime <= endDate) {
            count++;
        }
        current = current->next;
    }

    // ����ⷿ��ͬ������ʱ����ڵ��ⷿ����
    printf("��ͬ������ %d �� %d ֮����ⷿ������%d\n", startDate, endDate, count);

    // �ȴ��û����س�������
    printf("�밴�س���������");
    getchar();
    getchar();
    clear();
}


// ͳ�Ƴ���ʱ�����ⷿ����
void statisRentDuration(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int minDuration, maxDuration;

    // �������ʱ����Χ
    printf("��������С����ʱ�����£���");
    scanf("%d", &minDuration);
    printf("������������ʱ�����£���");
    scanf("%d", &maxDuration);

    // �����������ÿ���ⷿ�ĳ���ʱ���Ƿ���ָ����Χ��
    while (current != NULL) {
        if (current->rentDuration >= minDuration && current->rentDuration <= maxDuration) {
            count++;
        }
        current = current->next;
    }

    // �������ʱ����Χ�ڵ��ⷿ����
    printf("����ʱ���� %d �� %d ��֮����ⷿ������%d\n", minDuration, maxDuration, count);


    printf("�밴�س���������");
    getchar();
    getchar();
    clear();
}



// ͳ����͵��ⷿ�����Լ��ⷿ��ʱ��
void statisTenant(struct Rent* head) {
    int count = 0;
    int totalDuration = 0;  // ���ⷿʱ��
    struct Rent* current = head;
    char tenantName[100];

    // �����������
    printf("������������֣�");
    scanf("%s", tenantName);

    // �����������ÿ���ⷿ������Ƿ�ƥ��
    while (current != NULL) {
        if (strcmp(current->tenantname, tenantName) == 0) {  // ����������ƥ��
            count++;
            totalDuration += current->rentDuration;  // �ۼ��ⷿʱ��
        }
        current = current->next;
    }

    // �����͵��ⷿ���������ⷿʱ��
    printf("��� %s ���ⷿ������%d\n", tenantName, count);
    printf("��� %s �����ⷿʱ����%d �죨��ʽ��YYYYMMDD��\n", tenantName, totalDuration);

    printf("�밴�س���������");
    getchar();
    getchar();
    clear();
}
