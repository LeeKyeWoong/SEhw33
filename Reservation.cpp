#include "Reservation.h"

Reservation::Reservation() {
	// Function: Reservation()
	// Description: Reservation 클래스의 기본 생성자
	// Created: 2019/05/31
	// Author: 김승연
}

Reservation::Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, string seatNum)
{
	//Function: Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, int seatNum)
	//Description: Reservation 생성자 & 초기화
	//Created: 2019/05/31
	//Author: 김승연

	this->sellerID = sellerId;
	this->buyerID = buyerId;
	this->reservePrice = price;
	this->reserveDate = reserveDate;
	this->gameDate = gameDate;
	this->homeTeam = home;
	this->awayTeam = away;
	this->seatNumber = seatNum;
}

void Reservation::makeNewReservation(string sID, string bID, int price, string reservedate, string gamedate, string homeTeam, string awayTeam, string seat) {
	// Function: void makeNewReservation(string sID, string bID, int price, string reservedate, string gamedate, string homeTeam, string awayTeam, int seat)
	// Description: 매개변수로 받은 값들을 가지고 reservation 객체의 값을 설정하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	this->sellerID = sID;
	this->buyerID = bID;
	this->reservePrice = price;
	this->reserveDate = reservedate;
	this->gameDate = gamedate;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seatNumber = seat;
}

void Reservation::changeAuctionBuyer(string bID, int price, string date) {
	// Function: void changeAuctionBuyer(sting bId, int price, string date)
	// Description: 더 높은 입찰금액을 입력받은 경우 reservation 객체의 정보를 업데이트하기 위해 필요한 함수이다.
	// Parameters: string bID - 더 높은 입찰금액을 입력한 구매자의 아이디
	//						int price - 입력받은 입찰금액
	//						string date - 입찰을 한 날짜
	// Created: 2019/05/31
	// Author: 김승연

	this->buyerID = bID;
	this->reservePrice = price;
	this->reserveDate = date;
}

string Reservation::getSellerID() {
	// Function: string getSellerID()
	// Description: sellerID를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->sellerID;
}

string Reservation::getBuyerID() {
	// Function: string getBuyerID()
	// Description: BuyerID를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->buyerID;
}

int Reservation::getReservePrice() {
	// Function: int getReservePrice()
	// Description: 예매 금액을 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->reservePrice;
}

string Reservation::getReserveDate() {
	// Function: string getReserveDate()
	// Description: 예약날짜를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->reserveDate;
}

string Reservation::getGameDate() {
	// Function: string getGameDate()
	// Description: 경기날짜를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->gameDate;
}

string Reservation::getHomeTeam() {
	// Function: string getHomeTeam()
	// Description: 홈팀의 이름을 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->homeTeam;
}

string Reservation::getAwayTeam() {
	// Function: string getAwayTeam()
	// Description: 어웨이팀의 이름을 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->awayTeam;
}

string Reservation::getSeatNumber() {
	// Function: int getSeatNumber()
	// Description: 좌석번호를 리턴하는 함수이다.
	// Created: 2019/05/31
	// Author: 김승연

	return this->seatNumber;
}

void Reservation::deleteReservation() {
	// Function: void deleteReservation()
	// Description: 예약정보를 삭제하는 함수이다.
	// Created: 2019/06/04
	// Author: 김승연

	sellerID = "";
	buyerID = "";
	reservePrice = 0;
	reserveDate = "";
	gameDate = "";
	homeTeam = awayTeam = seatNumber = "";
}