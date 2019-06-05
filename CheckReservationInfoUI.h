#pragma once

#include <iostream>
#include <string>
using namespace std;

class ReservationCollection;
class MemberCollection;
class CheckReservationInfoControl;

class CheckReservationInfoUI
{
	//Class: CheckReservationInfoUI
	//Description : CheckReservationInfo(예약정보 조회)의 boundary class
	//Created : 2019/5/31
	//Author : 홍지은

private:
public:
	void showReservationInfo(CheckReservationInfoControl* checkReservationInfo,
		ReservationCollection* reservationCollection,
		MemberCollection* memberCollection); //티켓 예약정보를 보여주는 함수
};