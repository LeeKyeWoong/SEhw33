#pragma once

#include <iostream>
#include <string>
#include "Ticket.h"

#define MAX 50

using namespace std;

class TicketCollection {
	//Class : TicketCollection
	//Description : TicketCollection�� entity class
	//Created : 2019/05/28
	//Author : ȫ����

private:
	Ticket * ticketList[MAX];
	int ticketCount; //Ƽ���� ����

public:
	TicketCollection(Ticket ticketList[MAX]); //������
	void increaseTicketCount(); //Ƽ���� ���� ����
	int getTicketCount(); //Ƽ�� ���� ��������
	void deleteTicket(int deleteTicketIndex); //Ƽ�� ����
	void addTicket(int price, string gameDatenTime, string homeTeam, string awayTeam, string seatNum, 
		bool isLimitedTimeAuction, bool isSold, string sid, string registerTicketDate, string ticketType); //����Ʈ�� Ƽ���߰�
	Ticket *getTicket(int ticketCount); //Ư��Ƽ�� �������� �Լ�

};
