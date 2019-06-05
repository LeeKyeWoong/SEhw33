#include "ReservationCollection.h"

ReservationCollection::ReservationCollection(Reservation reservation[MAX]) {
	// Function: ReservationCollection(Reservation reservation[MAX])
	// Description: ReservationCollection의 생성자이다.
	// Created: 2019/05/31
	// Author: 김승연

	for (int i = 0; i < MAX; i++) // MAX까지 반복한다.
	{
		this->reservation[i] = &reservation[i]; // i번째 멤버는 Member[i]의 주소를 넣어준다.(포인터배열)
	}
	reservationCount = 0; // reservationCount를 0으로 초기화한다.
}

void ReservationCollection::addReservation(string sID, string bID, int price, string reserveDate, string gameDate, string homeTeam, string awayTeam, string seat, bool canShow) {
	// Function: void addReservation(string sID, string bID, int price, string date, string homeTeam, string awayTeam, int seat)
	// Description: reservation 객체를 하나 추가하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	reservation[reservationCount]->makeNewReservation(sID, bID, price, reserveDate, gameDate, homeTeam, awayTeam, seat, canShow);
	reservationCount++;
}

void ReservationCollection::deleteReservation(int deleteIndex) {
	// Function: void deleteReservation(int deleteIndex)
	// Description: reservation 객체를 삭제하는 함수이다. 구매자가 회원탈퇴 시 예약 정보를 파기해야 하므로 필요하다.
	// Parameter: 삭제할 reservation 객체의 인덱스
	// Created: 2019/06/04
	// Author: 김승연

	reservation[deleteIndex]->deleteReservation();
	int num = this->reservationCount;
	for (int i = deleteIndex; i < num - 1; i++) {
		this->reservation[i] = this->reservation[i + 1];
	}
	
	this->reservation[num] = NULL;
}

int ReservationCollection::getReservationCount() {
	// Function: int getReservationCount()
	// Description: reservation 객체의 개수를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->reservationCount;
}

Reservation* ReservationCollection::getReservation(int reservationCount) {
	// Function: int getReservationCount()
	// Description: 특정 reservation 객체를 리턴하는 함수이다.
	// Parameter: int reservationCount - 리턴하고자 하는 reservation 배열의 인덱스값
	// Created: 2019/05/31
	// Author: 김승연

	return this->reservation[reservationCount];
}