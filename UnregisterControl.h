#pragma once

#include <iostream>
#include <string>

using namespace std;

class UnregisterUI;
class TicketCollection;
class ReservationCollection;
class MemberCollection;

class UnregisterControl
{
	// Class: UnregisterControl
	// Description: unregister의 control class
	// Created: 2019/06/02
	// Author: 이계웅

private:
	bool canUnregister;   // 회원 탈퇴 가능 여부를 저장하는 변수
	string unregisterId;  // 회원 탈퇴할 ID명을 저장하는 변수

public:
	UnregisterControl();  // canUnregister의 값을 true로 설정하는 생성자
	void requestUnregister(TicketCollection* TicketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection);  //해당 회원을 삭제하는 함수
	bool getCanUnregister();  //탈퇴 가능 여부를 반환하는 함수
	string getUnregisterId();  //탈퇴한 ID를 반환하는 함수
};