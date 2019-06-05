#include "SetCurrentTimeUI.h"

void SetCurrentTimeUI::startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection, ReservationCollection* reservationCollection) {
	// Function: void startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection, ReservationCollection* reservationCollection)
	// Description: 현재시간 변경 기능을 위해 사용자 인터페이스를 제공하는 함수
	// Created: 2019/05/31
	// Author: 김승연

	string cntTime;

	cin >> cntTime;

	cout << "5.1 현재시간 설정" << endl;
	cout << "> " << cntTime << endl;
	cout << endl;
	control->setCurrentTime(timer, cntTime, ticketCollection, reservationCollection);
}