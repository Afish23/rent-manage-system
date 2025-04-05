#pragma once
#include "models.h"
void statisHousesFloor(struct House* head);
void statisHousesToward(struct House* head);
void statisHousesRent(struct House* head);
void statisHousesArea(struct House* head);
void statisHousesRoom(struct House* head);
void statisHousesFitment(struct House* head);
void statisRentAndArea(struct House* head);
void statisTowardAndFloor(struct House* head);
void statisRentAndFitment(struct House* head);
void statisCommunityAndFloor(struct House* head);
void statisRoomAndToward(struct House* head);
int calculateTotalDays(int date);
void statisAverageRentDuration(struct House* head);
void statisOccupancyRate(struct House* head);
void statisTotalAppointments(struct Appointment* head);
void statisCompletedAppointments(struct Appointment* head);
void statisAppointmentDuration(struct Appointment* head);
void statisAppointmentInPeriod(struct Appointment* head);
void statisAppointmentByTenant(struct Appointment* head);
void statisTotalRents(struct Rent* head);
void statisRentDate(struct Rent* head);
void statisContractDate(struct Rent* head);
void statisRentDuration(struct Rent* head);
void statisTenant(struct Rent* head);