#include "models.h"
//Rent���ĵ�һ����������
void simpleSortid(struct Rent** head);
void simpleSortByContractTime(struct Rent** head);
void simpleSortByRentStartTime(struct Rent** head);
void simpleSortByRentDuration(struct Rent** head);
void simpleSortByStatement(struct Rent** head);

//Rent���Ķ�������������
void multSortid_ByRentDuration(struct Rent** head);
void multSortid_ByRentStartTime(struct Rent** head);
void multSortRentDuration_Byid(struct Rent** head);
void multSortRentDuration_ByRentStartTime(struct Rent** head);
void multSortRentStartTime_ByRentDuration(struct Rent** head);



//House���ĵ�һ����������
void simpleSortHouseid(struct House** head);
void simpleSortHouseArea(struct House** head);
void simpleSortHouseRent(struct House** head);
void simpleSortHouseAgencyFee(struct House** head);

//House���Ķ�������������
void multSortArea_ByRent(struct House** head);
void multSortArea_ByAgencyFee(struct House** head);
void multSortRent_ByArea(struct House** head);
void multSortRent_ByAgencyFee(struct House** head);
void multSortAgencyFee_ByArea(struct House** head);
void multSortAgencyFee_ByRent(struct House** head);
//Rent��������
void swap(struct Rent** head1, struct Rent** head2);
//House��������
void swapHouse(struct House** head1, struct House** head2);