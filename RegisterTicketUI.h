#pragma once

#include<iostream>
#include <string>

class RegisterTicketControl;
class TicketCollection;
class MemberCollection;
class Timer;

class RegisterTicketUI {
	
	// Class: RegisterTicketUI
	// Description: Ƽ�ϵ���� ���� ������ �Է¹ް� RegisterControl::registerNewTicket�Լ����� �Ѱ��ش�
	// Created: 2019/05/31
	// Author: �̰��

private:

public:
	void inputRegisterNewTicket(RegisterTicketControl * registerTicketControl, TicketCollection *ticketCollection, MemberCollection * memberCollection, Timer * timer);  //�Ű������� �޾� �� Ticket���� �����ϴ� �Լ�	
};
