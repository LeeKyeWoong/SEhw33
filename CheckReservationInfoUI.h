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
	//Description : CheckReservationInfo(�������� ��ȸ)�� boundary class
	//Created : 2019/5/31
	//Author : ȫ����

private:
public:
	void showReservationInfo(CheckReservationInfoControl* checkReservationInfo,
		ReservationCollection* reservationCollection,
		MemberCollection* memberCollection); //Ƽ�� ���������� �����ִ� �Լ�
};