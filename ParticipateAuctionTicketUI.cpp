#include "ParticipateAuctionTicketUI.h"

void ParticipateAuctionTicketUI::participateAuctionInterface(ParticipateAuctionTicketControl *ctl, 
	ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *timer) {
	// Function: void participateAuctionInterface()
	// Description: [��¥-�ð�] [�������] [�¼���ġ] [�����ݾ�] ������ �Է��� �޾� ��Ʈ�� Ŭ������ �����Ѵ�.
	// Created: 2019/06/03
	// Auther: ��¿�

	string date, awayTeam, seatNum;
	int bid;

	cin >> date >> awayTeam >> seatNum >> bid;

	cout << "4.4 �������" << endl << "> ";
	ctl->participateAuction(date, awayTeam, seatNum, bid, resCollect, memCollect, tkCollect, timer);
	cout << endl;
}