#pragma once

#include <iostream>
#include <string>
#include "Reservation.h"

#define MAX 50

using namespace std;

class Reservation;

class ReservationCollection {
	// Class: ReservationCollection
	// Description: Reservation ��ü���� ������ �� �ִ� �ݷ��� Ŭ����
	// Created: 2019/05/29
	// Author: ��¿�

private:
	Reservation *reservation[MAX];
	int reservationCount;

public:
	ReservationCollection(Reservation reservation[MAX]);
	void addReservation(string sID, string bID, int price, string reserveDate, string gameDate, string homeTeam, string awayTeam, string seat);
	void deleteReservation(int deleteIndex);
	int getReservationCount();
	Reservation* getReservation(int reservationCount);
};