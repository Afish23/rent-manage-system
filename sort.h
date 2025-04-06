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

//Rent��������
void swap(struct Rent** head1, struct Rent** head2);