#include "SetCurrentTimeUI.h"

void SetCurrentTimeUI::startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection) {
	// Function: void startInterface(SetCurrentTimeControl* control, Timer* timer, TicketCollection* ticketCollection)
	// Description: ����ð� ���� ����� ���� ����� �������̽��� �����ϴ� �Լ�
	// Created: 2019/05/31
	// Author: ��¿�

	string cntTime;

	cin >> cntTime;

	cout << "5.1 ����ð� ����" << endl;
	cout << "> " << cntTime << endl;
	cout << endl;
	control->setCurrentTime(timer, cntTime, ticketCollection);
}