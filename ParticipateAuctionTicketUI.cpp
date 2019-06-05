#include "ParticipateAuctionTicketUI.h"

void ParticipateAuctionTicketUI::participateAuctionInterface(ParticipateAuctionTicketControl *ctl, 
	ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *timer) {
	// Function: void participateAuctionInterface()
	// Description: [날짜-시간] [어웨이팀] [좌석위치] [입찰금액] 순으로 입력을 받아 컨트롤 클래스에 전달한다.
	// Created: 2019/06/03
	// Auther: 김승연

	string date, awayTeam, seatNum;
	int bid;

	cin >> date >> awayTeam >> seatNum >> bid;

	cout << "4.4 경매참여" << endl << "> ";
	ctl->participateAuction(date, awayTeam, seatNum, bid, resCollect, memCollect, tkCollect, timer);
	cout << endl;
}