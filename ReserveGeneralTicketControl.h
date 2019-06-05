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
	//Description: ReserveGeneralTicket의 control class
	//Created: 2019/6/2
	//Author: 홍지은
private:
	Ticket *tempTicket; //임시티켓객체
public:
	ReserveGeneralTicketControl();  //tempTicket을 초기화
	void makeGeneralReservation(string gameDateTime, string awayTime, string seatNum, ReserveGeneralTicketControl* reserveGeneralTicket, ReservationCollection* reservationCollection,
		TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* t); //날짜시간, 어웨이팀, 좌석위치로 티켓을 예약하는 함수
	Ticket* getReservedTicket();  //성공적으로 티켓이 예약 되었을 시, 해당 예약 결과를 반환하는 함수
}; 
