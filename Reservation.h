#pragma once

#include <iostream>
#include <string>
using namespace std;

class Reservation {
	// Class: Reservation
	// Description: Reservation 정보를 나타내는 entity class
	// Created: 2019/05/29
	// Author: 김승연

private:
	string sellerID; // 티켓을 판매한 Member의 ID
	string buyerID; // 티켓 예약을 한 Member의 ID
	int reservePrice; // 티켓을 구매한 가격
	string reserveDate; // 티켓을 예약한 날짜 혹은 입찰을 한 날짜
	string gameDate; // 경기 날짜
	string homeTeam; // 홈팀
	string awayTeam; // 어웨이팀
	string seatNumber; // 좌석 번호
	bool canShow;     // 예약정보에 출력이 되도 되는가? 즉, 경매시간이 끝났는가?

public:
	Reservation();
	Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, string seatNum, bool canShow);
	void makeNewReservation(string sID, string bID, int price, string reservedate, string gamedate, string homeTeam, string awayTeam, string seat, bool canShow);
	void changeAuctionBuyer(string bID, int price, string date);
	string getSellerID();
	string getBuyerID();
	int getReservePrice();
	string getReserveDate();
	string getGameDate();
	string getHomeTeam();
	string getAwayTeam();
	string getSeatNumber();
	void deleteReservation();
	bool getCanShow();
};
