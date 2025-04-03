#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
int main() {

    //0�����˵� 1�����ѡ��˵� 2������Ա�˵� 3���н�˵� 4����Ͳ˵�
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4,
        //5:����Ա-�н����˵� 6:����Ա-��Դ����˵� 7:��Ϣ��ѯ�˵� 8:��Ϣ����˵�
        choice_5, choice_6, choice_7, choice_8,
        //9:��Ϣͳ�Ʋ˵� 10:��������˵� 11:�ⷿ����˵� 12:����ԤԼ�˵�
        choice_9, choice_10, choice_11, choice_12;
        //13�����Ҳ˵� 14���򵥲�ѯ�˵� 15����Χ��ѯ�˵� 17����ϲ�ѯ�˵�
    int choice_13, choice_14, choice_15, choice_16, choice_17;
    //18���ⷿ����˵�
    int choice_18, choice_19;

    //�˳�ѭ���ж�
    //0�����ѡ�� 1:�н���� 2:��Դ���� 3:��Ϣ��ѯ 4:��Ϣ���� 
    int jug0 = 0, jug1 = 0, jug2 = 0, jug3 = 0, jug4 = 0,
        //5:��Ϣͳ�� 6:�������� 7:�ⷿ���� 8:����ԤԼ
        jug5 = 0, jug6 = 0, jug7 = 0, jug8 = 0;
    //9�����ҷ�ʽ 10���򵥲�ѯ 11����Χ��ѯ 12����ϲ�ѯ
    int jug9 = 0, jug10 = 0, jug11 = 0, jug12 = 0;
    //13���ⷿ����
    int jug13 = 0, jug14 = 0;
 

    //
    int update_id = 0, delete_id = 0;
    int a;

    //�����û�
    struct User* p1, * p2, * tail, * head;
    p1 = (struct User*)malloc(sizeof(struct User));//����ռ�
    if (p1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }

    tail = p1; // ���ͷβ
    head = p1;
    p2 = p1;
    tail->next = NULL;
    head->prev = NULL;


    //���Ӷ���
    struct House* house_p1, * house_p2, * house_tail, * house_head;//��������
    house_p1 = (struct House*)malloc(sizeof(struct House));//����ռ�
    if (house_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }
    house_tail = house_p1;//���ͷβ
    house_head = house_p1;
    house_p2 = house_p1;
    house_tail->next = NULL;
    house_head->prev = NULL;


    //�ⷿ����
    struct Rent* q1, * q2, * tail1, * head1;
    q1 = (struct Rent*)malloc(sizeof(struct Rent));//����ռ�
    if (q1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }
    tail1 = q1; // ���ͷβ
    head1 = q1;
    q2 = q1;
    tail1->next = NULL;
    head1->prev = NULL;

    //���ݶ�ȡ
    read_user_data(&tail);
    read_house_data(&house_tail);
    read_tenant_data(&tail1);
    //������
    while (choice_0) {
        printf("******��    ¼******\n");
        printf("**                **\n");
        printf("**0.  ��    ��    **\n");
        printf("**1.  ��    ¼    **\n");
        printf("**2.  ���ע��    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("��ѡ���ܣ�");
        scanf_s("%d", &choice_0);
        clear();

        switch (choice_0) {
        case 0:
            break;
        case 1:
            //���ѡ�����
            printf("******���ѡ��******\n");
            printf("**                **\n");
            printf("**0.  ��    ��    **\n");
            printf("**1.  �� �� Ա    **\n");
            printf("**2.  ��    ��    **\n");
            printf("**3.  ��    ��    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("��ѡ����ݣ�");
            scanf_s("%d", &choice_1);
            clear();
            switch (choice_1)
            {
            case 0:
                break;
            case 1:
                jug0 = 1;
                p1 = login(1, p1, head);
                if (p1 == NULL)
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ��Դ����       **\n");
                    printf("**2.     �����н�       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.    ��ӹ���Ա      **\n");
                    printf("**8.     �н����       **\n");
                    printf("**9.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_2);
                    clear();

                    switch (choice_2)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    case 1:
                        jug2 = 1;
                        while (jug2)
                        {
                            //��Դ�������
                            printf("******��Դ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_6);
                            clear();
                            switch (choice_6)
                            {
                            case 0:
                                jug2 = 0;
                                break;
                            case 1:
                                addHouse(house_p1, house_head, house_tail, head, tail);
                                house_tail = house_tail->next;
                                printf("������س���������");
                                getchar();
                                clear();

                                break;
                            case 2:
                                printf("������Ҫ�޸ĵķ�ԴID��");
                                scanf_s("%d", &update_id);


                                if (updateHouse(update_id, house_head)) {
                                    printf("��Դ�޸ĳɹ���\n");
                                    printf("������س���������");
                                    getchar();
                                    clear();
                                }
                                else {
                                    printf("�޸�ʧ�ܣ�δ�ҵ���Դ��\n");
                                }
                                break;

                            case 3:

                                printf("������Ҫɾ���ķ�ԴID��");
                                scanf_s("%d", &delete_id);

                                if (deleteHouse(delete_id, house_head)) {
                                    printf("��Դɾ���ɹ���\n");
                                    printf("������س���������");
                                    getchar();
                                    clear();
                                }
                                else {
                                    printf("ɾ��ʧ�ܣ�δ�ҵ���Դ��\n");
                                }
                                break;

                            default:
                                jug2 = 0;
                                break;
                            }
                        }
                        break;
                    case 2:

                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  �û���Ϣ    **\n");
                            printf("**2.  ��Դ��Ϣ    **\n");
                            printf("**3.  ԤԼ��Ϣ    **\n");
                            printf("**4.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            case 2:

                                jug9 = 1;
                                while (jug9)
                                {
                                    printf("*********��ѯ��ʽ*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     �򵥲���       **\n");
                                    printf("**2.     ��Χ����       **\n");
                                    printf("**3.     ��ϲ���       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ����ҷ�ʽ:\n");
                                    scanf_s("%d", &choice_13);
                                    clear();
                                    switch (choice_13)
                                    {
                                    case 0:
                                        jug9 = 0;
                                        break;
                                    case 1:
                                        jug10 = 1;
                                        while (jug10)
                                        {
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("** 0.    ��    ��        **\n");
                                            printf("**1.     ������          **\n");
                                            printf("**2.     ������/��       **\n");
                                            printf("**3.     ����С��        **\n");
                                            printf("**4.     ��    ��       **\n");
                                            printf("**5.     ��    ��       **\n");
                                            printf("**6.     װ�����        **\n");
                                            printf("**7.     ��    ��       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            scanf_s("%d", &choice_14);
                                            clear();
                                            switch (choice_14)
                                            {
                                            case 0:
                                                jug10 = 0;
                                                break;
                                            case 1:
                                                simpleQueryHouse1(house_head);
                                                
                                                break;
                                            case 2:
                                                simpleQueryHouse2(house_head);
                                                
                                                break;
                                            case 3:
                                                simpleQueryHouse3(house_head);
                                                
                                                break;
                                            case 4:
                                                simpleQueryHouse4(house_head);
                                                
                                                break;
                                            case 5:
                                                simpleQueryHouse5(house_head);
                                                
                                                break;
                                            case 6:
                                                simpleQueryHouse6(house_head);
                                                
                                                break;
                                            case 7:
                                                simpleQueryHouse7(house_head);
                                                
                                                break;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                break;

                                            }
                                        }
                                        break;
                                    case 2:
                                        jug11 = 1;
                                        while (jug11)
                                        {
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     ��    ��       **\n");
                                            printf("**2.     ¥    ��       **\n");
                                            printf("**3.     ��    ��       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            scanf_s("%d", &choice_8);
                                            clear();
                                            switch (choice_8) {
                                            case 0:
                                                jug11 = 0;
                                                break;
                                            case 1:
                                                rangeQueryRent(house_head);
                                                break;
                                            case 2:
                                                rangeQueryFloor(house_head);
                                                break;
                                            case 3:
                                                rangeQueryArea(house_head);
                                                break;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                clear();
                                                break;
                                            }
                                        }

                                        break;

                                    }


                                }

                                break;




                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //��Ϣͳ�ƽ���
                            printf("******��Ϣͳ��******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                        continue;
                    case 8:
                        jug1 = 1;
                        while (jug1)
                        {
                            //�н�������
                            printf("******�н����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_5);
                            clear();
                            switch (choice_5)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                register_user(2, p1, p2, tail, head);
                                continue;
                            case 2:
                                updatePassword(2, p1, head);
                                continue;
                            case 3:
                                deleteUser(2, p1, head, tail);
                                continue;
                            default:
                                jug1 = 0;
                                break;
                            }
                        }
                        break;
                    case 9:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
                        break;
                    }
                }
                break;


            case 2:
                jug0 = 1;

                p1 = login(2, p1, head);
                if (p1 == NULL)
                {
                    break;
                }

                while (jug0)
                {

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
                    scanf_s("%d", &choice_3);
                    clear();

                    switch (choice_3)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    case 1:
                        jug6 = 1;
                        while (jug6)
                        {
                            //�����������
                            printf("******��������******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_10);
                            clear();
                            switch (choice_10)
                            {
                            case 0:
                                jug6 = 0;
                                break;
                            default:
                                jug6 = 0;
                                break;
                            }
                        }
                        break;
                    case 2:
                        jug7 = 1;
                        while (jug7)
                        {
                            printf("******�ⷿ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ����ⷿ    **\n");
                            printf("**2.  ɾ���ⷿ    **\n");
                            printf("**3.  �޸��ⷿ    **\n");
                            printf("**                **\n");
                            printf("********************\n");

                            scanf("%d", &choice_18);
                            switch (choice_18)
                            {
                            case 0:
                                jug7 = 0;
                                clear();
                                break; 
                            case 1: {
                                        struct Rent* p1;
                                        p1 = (struct Rent*)malloc(sizeof(struct Rent)); // �����ڴ�
                                        if (p1 == NULL) {  // �ж��ڴ��Ƿ����ɹ�
                                            printf("�ڴ�ռ����ʧ��");
                                            return false;
                                        }
                                        addRent(p1, &tail1);
                                        printf("������س���������");
                                        getchar();
                                        clear();
                                        break;
                                    }
                            case 2: {
                                        int id1;
                                        printf("����id\n");
                                        scanf("%d", &id1);
                                        struct Rent* p1 = findRent(id1, head1);
                                        //printf("%d", p1->contractTime);
                                        if (p1 != NULL) {
                                            if (p1->prev != NULL && p1->next != NULL) {
                                                deleteRent(&p1->prev, &p1, &p1->next);
                                            }
                                            else if (p1->prev == NULL) { p1->next->prev == NULL, free(p1); }
                                            else if (p1->next == NULL) { p1->prev->next == NULL, free(p1); }
                                        }
                                        else printf("û���ҵ���ɾ��ʧ��");
                                        printf("������س���������");
                                        getchar();
                                        clear();
                                        break;
                                    }
                            case 3: {
                                        int choice; int id1;
                                        printf("����id\n");
                                        scanf("%d", &id1);
                                        struct Rent* p1 = findRent(id1, head1);
                                        if (p1 != NULL) {
                                            printf("��ѡ��Ҫ�޸ĵ��ⷿ��Ϣ�ֶ�:\n");
                                            printf("1. �ⷿ���\n");
                                            printf("2. ��ͬǩ������\n");
                                            printf("3. ���⿪ʼ����\n");
                                            printf("4. Ԥ�Ƴ���ʱ��\n");
                                            printf("5. �н�����\n");
                                            printf("6. �������\n");
                                            printf("7. ��ԴID\n");
                                            printf("8. ��Դλ��\n");
                                            printf("9. ����״̬\n");
                                            printf("0. �˳��޸�\n");

                                            scanf("%d", &choice);
                                            while (choice != 0) {
                                                switch (choice) {
                                                case 1:
                                                    printf("�������µ��ⷿ���: ");
                                                    scanf("%d", &p1->id);
                                                    break;
                                                case 2:
                                                    printf("�������µĺ�ͬǩ������: ");
                                                    scanf("%d", &p1->contractTime);
                                                    break;
                                                case 3:
                                                    printf("�������µĳ��⿪ʼ����: ");
                                                    scanf("%d", &p1->rentStartTime);
                                                    break;
                                                case 4:
                                                    printf("�������µ�Ԥ�Ƴ���ʱ��: ");
                                                    scanf("%d", &p1->rentDuration);
                                                    break;
                                                case 5:
                                                    printf("�������µ��н�����: ");
                                                    scanf("%s", p1->agentname);
                                                    break;
                                                case 6:
                                                    printf("�������µ��������: ");
                                                    scanf("%s", p1->tenantname);
                                                    break;
                                                case 7:
                                                    printf("�������µķ�ԴID: ");
                                                    scanf("%d", &p1->house_id);
                                                    break;
                                                case 8://ûд
                                                    printf("�������µķ�Դλ��: ");
                                                    break;
                                                case 9:
                                                    printf("�������µ�����״̬ (0-�����, 1-������): ");
                                                    scanf("%d", &p1->statement);
                                                    break;
                                                default:
                                                    printf("��Чѡ�����������\n");
                                                }

                                                // ������ʾ�˵��������û������޸�
                                                printf("\n��ѡ��Ҫ�޸ĵ��ⷿ��Ϣ�ֶ�:\n");
                                                printf("1. �ⷿ���\n");
                                                printf("2. ��ͬǩ������\n");
                                                printf("3. ���⿪ʼ����\n");
                                                printf("4. Ԥ�Ƴ���ʱ��\n");
                                                printf("5. �н�����\n");
                                                printf("6. �������\n");
                                                printf("7. ��ԴID\n");
                                                printf("8. ��Դλ��\n");
                                                printf("9. ����״̬\n");
                                                printf("0. �˳��޸�\n");

                                                scanf("%d", &choice);
                                            }
                                            printf("�޸���ɣ�\n");
                                        }
                                        else printf("û���ҵ����޸�ʧ��");
                                        printf("������س���������");
                                        getchar();
                                        clear();
                                        break;
                                    }
                                   
                                   
                            default:
                                jug7 = 0;
                                break;
                                
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //��Ϣͳ�ƽ���
                            printf("******��Ϣͳ��******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
                        break;
                    }
                }
                break;

            case 3:
                jug0 = 1;

                p1 = login(3, p1, head);
                if (p1 == NULL)
                {
                    break;
                }

                while (jug0)
                {

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     �޸���Ϣ       **\n");
                    printf("**2.     ����ԤԼ       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_4);
                    clear();

                    switch (choice_4)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    case 1:
                        updateMyNameOrPhoneNumber(p1);
                        continue;
                    case 2:
                        jug8 = 1;
                        while (jug8)
                        {
                            //����ԤԼ����
                            printf("******����ԤԼ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_12);
                            clear();
                            switch (choice_12)
                            {
                            case 0:
                                jug8 = 0;
                                break;
                            default:
                                jug8 = 0;
                                break;
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //��Ϣͳ�ƽ���
                            printf("******��Ϣͳ��******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
                        break;
                    }
                }
                break;
            }
            break;
        case 2:
            register_user(3, p1, p2, tail, head);
        default:
            break;
        }
    }
    write_user_data(head);
    write_house_data(house_head);
    write_tenant_data(head1);
    return 0;
}