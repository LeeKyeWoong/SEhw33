#pragma once

#include <iostream>
#include <string>
#include "ParticipateAuctionTicketControl.h"

using namespace std;

class ParticipateAuctionTicketControl;
class ReservationCollection;
class MemberCollection;
class TicketCollection;

class ParticipateAuctionTicketUI {
	// Class: ParticipateAuctionTicketUI
	// Description: °æ¸ÅÂü¿©¸¦ À§ÇÑ boundary class
	// Created: 2019/06/03
	// Author: ±è½Â¿¬
public:
	void participateAuctionInterface(ParticipateAuctionTicketControl *ctl, 
		ReservationCollection *resCollect, MemberCollection *memCollect, TicketCollection *tkCollect, Timer *timer);
};