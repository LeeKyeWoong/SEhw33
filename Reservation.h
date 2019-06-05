#pragma once

#include <iostream>
#include <string>
using namespace std;

class Reservation {
	// Class: Reservation
	// Description: Reservation ������ ��Ÿ���� entity class
	// Created: 2019/05/29
	// Author: ��¿�

private:
	string sellerID; // Ƽ���� �Ǹ��� Member�� ID
	string buyerID; // Ƽ�� ������ �� Member�� ID
	int reservePrice; // Ƽ���� ������ ����
	string reserveDate; // Ƽ���� ������ ��¥ Ȥ�� ������ �� ��¥
	string gameDate; // ��� ��¥
	string homeTeam; // Ȩ��
	string awayTeam; // �������
	string seatNumber; // �¼� ��ȣ

public:
	Reservation();
	Reservation(string sellerId, string buyerId, int price, string reserveDate, string gameDate, string home, string away, string seatNum);
	void makeNewReservation(string sID, string bID, int price, string reservedate, string gamedate, string homeTeam, string awayTeam, string seat);
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
};
