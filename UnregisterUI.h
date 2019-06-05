#pragma once

#include <iostream>
#include <string>
using namespace std;

class UnregisterControl;
class TicketCollection;
class ReservationCollection;
class MemberCollection;

class UnregisterUI
{
	//Class: UnregisterUI
	//Description: Unregister의 boudnary class
	//Created: 2019/06/02
	//Author: 이계웅

public:
	void callUnregister(UnregisterControl* unregisterControl, TicketCollection* ticketCollection, ReservationCollection* reservationCollection,
		MemberCollection* memberCollection);  //회원 탈퇴 요청을 control로 전달하는 함수
};
