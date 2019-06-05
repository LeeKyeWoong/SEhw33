#include "Reservation.h"

Reservation::Reservation() {
	// Function: Reservation()
	// Description: Reservation Ŭ������ �⺻ ������
	// Created: 2019/05/31
	// Author: ��¿�
}

Reservation::Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, string seatNum)
{
	//Function: Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, int seatNum)
	//Description: Reservation ������ & �ʱ�ȭ
	//Created: 2019/05/31
	//Author: ��¿�

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
	// Description: �Ű������� ���� ������ ������ reservation ��ü�� ���� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

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
	// Description: �� ���� �����ݾ��� �Է¹��� ��� reservation ��ü�� ������ ������Ʈ�ϱ� ���� �ʿ��� �Լ��̴�.
	// Parameters: string bID - �� ���� �����ݾ��� �Է��� �������� ���̵�
	//						int price - �Է¹��� �����ݾ�
	//						string date - ������ �� ��¥
	// Created: 2019/05/31
	// Author: ��¿�

	this->buyerID = bID;
	this->reservePrice = price;
	this->reserveDate = date;
}

string Reservation::getSellerID() {
	// Function: string getSellerID()
	// Description: sellerID�� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->sellerID;
}

string Reservation::getBuyerID() {
	// Function: string getBuyerID()
	// Description: BuyerID�� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->buyerID;
}

int Reservation::getReservePrice() {
	// Function: int getReservePrice()
	// Description: ���� �ݾ��� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->reservePrice;
}

string Reservation::getReserveDate() {
	// Function: string getReserveDate()
	// Description: ���೯¥�� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->reserveDate;
}

string Reservation::getGameDate() {
	// Function: string getGameDate()
	// Description: ��⳯¥�� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->gameDate;
}

string Reservation::getHomeTeam() {
	// Function: string getHomeTeam()
	// Description: Ȩ���� �̸��� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->homeTeam;
}

string Reservation::getAwayTeam() {
	// Function: string getAwayTeam()
	// Description: ��������� �̸��� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->awayTeam;
}

string Reservation::getSeatNumber() {
	// Function: int getSeatNumber()
	// Description: �¼���ȣ�� �����ϴ� �Լ��̴�.
	// Created: 2019/05/31
	// Author: ��¿�

	return this->seatNumber;
}

void Reservation::deleteReservation() {
	// Function: void deleteReservation()
	// Description: ���������� �����ϴ� �Լ��̴�.
	// Created: 2019/06/04
	// Author: ��¿�

	sellerID = "";
	buyerID = "";
	reservePrice = 0;
	reserveDate = "";
	gameDate = "";
	homeTeam = awayTeam = seatNumber = "";
}