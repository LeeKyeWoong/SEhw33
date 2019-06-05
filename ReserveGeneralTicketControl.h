#pragma once

#include <iostream>
#include <string>

using namespace std;

class ReserveGeneralTicketUI;
class TicketCollection;
class ReservationCollection;
class MemberCollection;
class Ticket;

class ReserveGeneralTicketControl
{
	//Class: ReserveGeneralTicketControl
	//Description: ReserveGeneralTicket�� control class
	//Created: 2019/6/2
	//Author: ȫ����
private:
	Ticket *tempTicket; //�ӽ�Ƽ�ϰ�ü
public:
	ReserveGeneralTicketControl();  //tempTicket�� �ʱ�ȭ
	void makeGeneralReservation(string gameDateTime, string awayTime, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
		TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t); //��¥�ð�, �������, �¼���ġ�� Ƽ���� �����ϴ� �Լ�
	Ticket* getReservedTicket();  //���������� Ƽ���� ���� �Ǿ��� ��, �ش� ���� ����� ��ȯ�ϴ� �Լ�
}; 
