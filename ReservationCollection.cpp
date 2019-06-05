#include "ReservationCollection.h"

ReservationCollection::ReservationCollection(Reservation reservation[MAX]) {
	// Function: ReservationCollection(Reservation reservation[MAX])
	// Description: ReservationCollection�� �������̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	for (int i = 0; i < MAX; i++) // MAX���� �ݺ��Ѵ�.
	{
		this->reservation[i] = &reservation[i]; // i��° ����� Member[i]�� �ּҸ� �־��ش�.(�����͹迭)
	}
	reservationCount = 0; // reservationCount�� 0���� �ʱ�ȭ�Ѵ�.
}

void ReservationCollection::addReservation(string sID, string bID, int price, string reserveDate, string gameDate, string homeTeam, string awayTeam, string seat) {
	// Function: void addReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat)
	// Description: reservation ��ü�� �ϳ� �߰��ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	reservation[reservationCount]->makeNewReservation(sID, bID, price, reserveDate, gameDate, homeTeam, awayTeam, seat);
	reservationCount++;
}

void ReservationCollection::deleteReservation(int deleteIndex) {
	// Function: void deleteReservation(int deleteIndex)
	// Description: reservation ��ü�� �����ϴ� �Լ��̴�. �����ڰ� ȸ��Ż�� �� ���� ������ �ı��ؾ� �ϹǷ� �ʿ��ϴ�.
	// Parameter: ������ reservation ��ü�� �ε���
	// Created: 2019/06/04
	// Author: ��¿�

	reservation[deleteIndex]->deleteReservation();
	int num = this->reservationCount;
	for (int i = deleteIndex; i < num - 1; i++) {
		this->reservation[i] = this->reservation[i + 1];
	}
	
	this->reservation[num] = NULL;
}

int ReservationCollection::getReservationCount() {
	// Function: int getReservationCount()
	// Description: reservation ��ü�� ������ �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->reservationCount;
}

Reservation* ReservationCollection::getReservation(int reservationCount) {
	// Function: int getReservationCount()
	// Description: Ư�� reservation ��ü�� �����ϴ� �Լ��̴�.
	// Parameter: int reservationCount - �����ϰ��� �ϴ� reservation �迭�� �ε�����
	// Created: 2019/05/31
	// Author: ��¿�

	return this->reservation[reservationCount];
}