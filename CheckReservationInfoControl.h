#pragma once

#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class CheckReservationInfoUI;
class ReservationCollection;
class MemberCollection;
class Reservation;

class CheckReservationInfoControl
{

	//Class: CheckReservationInfoControl
	//Description : CheckReservationInfo(예약정보 조회)의 control class
	//Created : 2019/5/31
	//Author : 홍지은


private:
	Reservation *temp[MAX]; //output.txt에 출력할 reservation검색목록을 담을 임시변수
	int tempCount; //임시변수 개수 count

public:
	CheckReservationInfoControl();
	void getReservationInfo(CheckReservationInfoControl* checkReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection);
	Reservation* getReservationInfo(int n); //n번째 티켓을 가져오기
	int getTempCount(); //몇번째인지 출력
};