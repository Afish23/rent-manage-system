#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
int main() {

    //0�����˵� 1�����ѡ��˵� 2������Ա�˵� 3���н�˵� 4����Ͳ˵�
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //5:�н����˵�10����������˵�
    int choice_5,choice_10;
    int update_id ,delete_id;//�޸ķ�Դid
    //6.��Ϣ��ѯ�˵�7.�򵥲�ѯ�˵�8.��Χ��ѯ�˵�9.��ϲ�ѯ�˵�
    int choice_6, choice_7,choice_8, choice_9;
    //�˳�ѭ���ж�
    //0�����ѡ�� 1:�н����
    int jug0 = 0, jug1 = 0,jug2 = 0;

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

    //���ݶ�ȡ
    read_user_data(&tail);
    read_house_data(&house_tail);

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
                    printf("**1.     ��Ϣ����       **\n");
                    printf("**2.     ��������       **\n");
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
                    case 2:
                        jug1 = 1;
                        while (jug1)
                        {
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
                                jug1 = 0;
                                break;
                            case 1:
                                addHouse(house_head, house_tail, head, tail);
                                write_house_data(house_head);
                                break;
                            case 2: 
                                printf("������Ҫ�޸ĵķ�ԴID��");
                                scanf_s("%d", &update_id);

                                
                                if (updateHouse(update_id, house_head)) {
                                    printf("��Դ�޸ĳɹ���\n");
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
                                }
                                else {
                                    printf("ɾ��ʧ�ܣ�δ�ҵ���Դ��\n");
                                }
                                break;
                            
                            
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                clear();

                            }

                        }
                        break;

                    case 3:
                        jug1 = 1;
                        while(jug1)
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
                            scanf_s("%d", &choice_6);
                            clear();
                            switch (choice_6)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                jug2 = 1;
                                while (jug2)
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
                                    scanf_s("%d", &choice_7);
                                    clear();
                                    switch (choice_7)
                                    {
                                    case 0:
                                        jug2 = 0;
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
                                        clear();
                                        break;

                                    }
                                }
                                break;
                            case 2:
                                jug2 = 1;
                                while (jug2)
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
                                        jug2 = 0;
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
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                        write_user_data(head);
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
                                write_user_data(head);
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
                    printf("**1.     ������Ϣ       **\n");
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
            write_user_data(head);
        default:
            break;
        }
    }

    return 0;
}