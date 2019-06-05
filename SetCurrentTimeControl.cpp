#include "SetCurrentTimeControl.h"

void SetCurrentTimeControl::setCurrentTime(Timer *t, string time, TicketCollection *tc) {
	// Function: void setCurrentTime(Timer *t, string time, TicketCollection *tc)
	// Description: 현재시간을 업데이트하도록 timer의 함수인 setCurrentTime을 호출하고, 
	//						변경된 현재시간에 따라 삭제해야 할 티켓을 찾아 삭제까지 하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	t->setCurrentTime(time);

	int t_count = tc->getTicketCount();
	for (int i = 0; i < t_count; i++) {
		string registerDate = tc->getTicket(i)->getTicketRegisterDate();
		bool haveToDelete = t->checkTimeToDeleteTicket(registerDate);
		if (haveToDelete) {
			tc->deleteTicket(i);
		}
		else { ; }
	}
}