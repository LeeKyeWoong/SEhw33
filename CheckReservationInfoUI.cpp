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
	//Description: 회원의 예약정보를 보여줌
	//Created: 2019/05/31
	//Author: 홍지은

	//출력형식 : 구매가격/날짜시간/홈팀/어웨이팀/좌석위치


	checkReservationInfo->getReservationInfo(checkReservationInfo, reservationCollection, memberCollection);

	int reservationCount = checkReservationInfo->getTempCount();

	if (reservationCount == 0)
	{
		cout << "4.5. 예약정보 조회" << endl;
		cout << "> " << endl;
	}

	else //예약한 티켓의 개수가 있다면
	{
		cout << "4.5.예약정보 조회" << endl;
		for (int i = 0; i < reservationCount ; i++)
		{
			cout << "> " << checkReservationInfo->getReservationInfo(i)->getReservePrice() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getGameDate() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getHomeTeam() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getAwayTeam() << " ";
			cout << checkReservationInfo->getReservationInfo(i)->getSeatNumber() << endl;
		}
	}
	cout << endl;
}