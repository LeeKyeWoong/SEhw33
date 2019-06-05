#pragma once

#include "CheckReservationInfoUI.h"
#include "CheckReservationInfoControl.h"
#include "Reservation.h"
#include "reservationCollection.h"
#include "Member.h"
#include "MemberCollection.h"

void CheckReservationInfoUI::showReservationInfo(CheckReservationInfoControl* checkReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
{
	//Function: showReservationInfo(CheckReservationInfoControl* checkReservationInfo, ReservationCollection* reservationCollection, MemberCollection* memberCollection)
	//Description: ȸ���� ���������� ������
	//Created: 2019/05/31
	//Author: ȫ����

	//������� : ���Ű���/��¥�ð�/Ȩ��/�������/�¼���ġ


	checkReservationInfo->getReservationInfo(checkReservationInfo, reservationCollection, memberCollection);

	int reservationCount = checkReservationInfo->getTempCount();

	if (reservationCount == 0)
	{
		cout << "4.5. �������� ��ȸ" << endl;
		cout << "> " << endl;
	}

	else //������ Ƽ���� ������ �ִٸ�
	{
		cout << "4.5.�������� ��ȸ" << endl;
		for (int i = 0; i < reservationCount ; i++)
		{
			cout << "> " <<"{"<< checkReservationInfo->getReservationInfo(i)->getReservePrice() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getGameDate() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getHomeTeam() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getAwayTeam() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getSeatNumber() <<"}"<< endl;
		}
	}
	cout << endl;
}