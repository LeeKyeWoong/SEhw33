#include "SetCurrentTimeControl.h"

void SetCurrentTimeControl::setCurrentTime(Timer *t, string time, TicketCollection *tc) {
	// Function: void setCurrentTime(Timer *t, string time, TicketCollection *tc)
	// Description: ����ð��� ������Ʈ�ϵ��� timer�� �Լ��� setCurrentTime�� ȣ���ϰ�, 
	//						����� ����ð��� ���� �����ؾ� �� Ƽ���� ã�� �������� �ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

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