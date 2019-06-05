#pragma once

#include <iostream>
#include <string>
using namespace std;

class ReservationCollection;
class TicketCollection;
class MemberCollection;
class ReserveGeneralTicketControl;
class Timer;

class ReserveGeneralTicketUI
{
	//Class: ReserveGeneralTicketUI
	//Description: ReserveGeneralTicket�� boundary class
	//Created: 2019/6/2
	//Author: ȫ����


public:
	void reserveGeneralTicket(ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
		TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer);
	//��¥�ð�, �������, �¼���ġ�� �Է��ؼ� Ƽ�� ����
};