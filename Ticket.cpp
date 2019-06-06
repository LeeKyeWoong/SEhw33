#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;


Ticket::Ticket()
{

	//Function: Ticket()
	//Description:Ticket의 생성자 및 초기화
	//Created: 2019/5/28
	//Author: 홍지은


	this->sellerId = "";
	this->homeTeam = "";
	this->awayTeam = "";
	this->price = 0;
	this->gameDateNTime = "";
	this->registerTicketDate = "";
	this->seatNum = "";
	this->isSold = false;
	this->ticketType = "";
	this->isLimitedTimeAuction = false;
	this->canSell = true;
}

void Ticket::addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sellerId, string registerTicketDate, string ticketType )
{
	//Function: addNewTicket(int price, string gameDateNTime, string homeTeam, string awayTeam, string seatNum, bool isLimitedTimeAuction, bool isSold, string sellerId, string registerTicketDate, string ticketType )
	//Description: 새로운 티켓을 추가한다.
	//Created: 2019/5/28
	//Author: 홍지은

	this->price = price;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->gameDateNTime = gameDateNTime;
	this->seatNum = seatNum;
	this->isLimitedTimeAuction = isLimitedTimeAuction;
	this->isSold = false; //새로 들어온 티켓은 아직 팔리지 않은상태!
	this->sellerId = sellerId;
	this->registerTicketDate = registerTicketDate;
	this->ticketType = ticketType;
}

void Ticket::removeTicket()
{
	//Function: removeTicket()
	//Description: 티켓을 삭제한다.
	//Created: 2019/6/1
	//Author: 홍지은

	this->price = 0; //가격
	this->homeTeam = ""; //홈팀
	this->awayTeam = ""; //어웨이팀
	this->gameDateNTime = ""; //게임시간
	this->seatNum = ""; //좌석
	this->isLimitedTimeAuction = false; //경매여부
	this->isSold = false; //팔렸는지
	this->canSell = true; //경매 판매 가능기간인지
	this->sellerId = ""; //판매자 아이디
	this->registerTicketDate = ""; //등록날짜
	this->ticketType = ""; //티켓타입
}

bool Ticket::getReservable()
{

	//Function: getReservable()
	//Description: 예약가능한지에 대한 여부를 반환한다. getReservable이 트루이면 예약이 가능하다는 뜻이고 isSold는 false이다.
	//Created: 2019/5/28
	//Author: 홍지은

	return !isSold;
}

void Ticket::setReservable(bool pSold)
{
	//Function: setReservable(bool pSold)
	//Description: setReservable이 true면 티켓이 다시 예약가능한 상태가 되도록 한다.
	//Created: 2019/5/28
	//Author: 홍지은

	isSold = !pSold;

	//만일 pSold가 true이면 아직 안팔렸다는 뜻이므로 isSold는 false가 된다
	//반대로 pSold가 false이면 팔렸다는 뜻이므로 isSold는 true가 되야한다.
}

string Ticket::getSellerId()
{
	//Function: getSellerId()
	//Description: seller의 id를 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->sellerId;
}

string Ticket::getHomeTeam()
{
	//Function: getHomeTeam()
	//Description: 홈팀을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->homeTeam;
}

string Ticket::getAwayTeam()
{
	//Function: getAwayTeam()
	//Description: 어웨이팀을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->awayTeam;
}

int Ticket::getTicketPrice()
{
	//Function: getTicketPrice()
	//Description: 티켓의 가격을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->price;
}

string Ticket::getTicketRegisterDate()
{
	//Function: getTicketRegisterDate()
	//Description: 티켓의 등록날짜를 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->registerTicketDate;
}

string Ticket::getTicketSeatNum()
{
	//Function: getTicketSeatNum()
	//Description: 좌석을 반환한다.
	//Created: 2019/5/28
	//Author: 홍지은

	return this->seatNum;
}

string Ticket::getGameDateNTime()
{
	//Function: getGameDateNTime()
	//Description: 게임날짜와 시간을 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은
	return this->gameDateNTime;
}

bool Ticket::getIsLimitedTimeAuction()
{
	//Function: getGameDateNTime()
	//Description: 게임날짜와 시간을 반환한다.
	//Created: 2019/6/1
	//Author: 홍지은

	return this->isLimitedTimeAuction;
}

bool Ticket::getIsSold()
{
	//Function: getIsSold()
	//Description: 판매여부를 반환한다.
	//Created: 2019/6/2
	//Author: 이계웅

	return this->isSold;
}

bool Ticket::getCanSell() {
	//Function: getCanSell()
	//Description: 판매기간에 속해있는 티켓인 경우 true를 리턴하는 함수이다.
	//Created: 2019/06/02
	//Author: 김승연

	return this->canSell;
}

void Ticket::setCanSell(bool can) {
	//Function: setCanSell(bool can)
	//Description: 판매가능기간에 속해있는지 여부를 설정할 때 쓰는 함수이다.
	//Created: 2019/06/02
	//Author: 김승연

	this->canSell = can;
}

string Ticket::getTicketType() {
	//Function: getTicketType()
	//Description: ticketType을 리턴하는 함수이다.
	//Created: 2019/06/02
	//Author: 김승연

	return this->ticketType;
}

void Ticket::setTicketType(string type) {
	//Function: setTicketType(string type)
	//Description: ticketType을 바꿀 때 쓰는 함수이다.
	//Created: 2019/06/02
	//Author: 김승연

	ticketType = type;
}