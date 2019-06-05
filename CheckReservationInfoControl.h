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
	//Description : CheckReservationInfo(�������� ��ȸ)�� control class
	//Created : 2019/5/31
	//Author : ȫ����


private:
	Reservation *temp[MAX]; //output.txt�� ����� reservation�˻������ ���� �ӽú���
	int tempCount; //�ӽú��� ���� count

public:
	CheckReservationInfoControl();
	void getReservationInfo(CheckReservationInfoControl* checkReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection);
	Reservation* getReservationInfo(int n); //n��° Ƽ���� ��������
	int getTempCount(); //���°���� ���
};