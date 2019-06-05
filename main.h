// Fliename: main.h
// Description: main에서 사용되는 헤더 및 참조할 헤더 입력
// Created: 2019/05/29
// Author: 이계웅

#pragma once

#include <iostream>
#include <string.h>
#include <cstdio>

#include "Member.h"           // 멤버             
#include "MemberCollection.h"
#include "SignUpUI.h"         // 회원가입
#include "SignUpControl.h"
#include "LoginUI.h"          // 로그인
#include "LoginControl.h"
#include "LogoutUI.h"         // 로그아웃 
#include "LogoutControl.h"
#include "UnregisterUI.h"     // 회원탈퇴 
#include "UnregisterControl.h"

//티켓 등록, 등록 티켓 조회 기능
#include "Ticket.h" //티켓
#include "TicketCollection.h"
#include "CheckTicketControl.h" //등록 티켓 조회
#include "CheckTicketUI.h"
#include "RegisterTicketControl.h" //티켓 등록
#include "RegisterTicketUI.h"

//티켓 검색 및 예약 기능, 경매 참여 기능, 예약 정보 조회 기능
#include "Reservation.h" //예약
#include "ReservationCollection.h"
#include "ReserveGeneralTicketUI.h" //일반티켓 예약
#include "ReserveGeneralTicketControl.h"
#include "SearchTicketControl.h" //티켓 검색
#include "SearchTicketUI.h"
#include "SearchAuctionTicketControl.h" //경매티켓 검색
#include "SearchAuctionTicketUI.h"
#include "ParticipateAuctionTicketUI.h" //입찰 참여
#include "ParticipateAuctionTicketControl.h" 
#include "CheckReservationInfoUI.h" //예약정보 조회
#include "CheckReservationInfoControl.h"

//현재시간 변경 기능, 세션 변경 기능
#include "Timer.h" //타이머
#include "SetCurrentTimeUI.h" //현재 시간 변경
#include "SetCurrentTimeControl.h"
#include "ChangeSessionUI.h" //세션 변경
#include "ChangeSessionControl.h"

void signupInterface(MemberCollection* memberCollection);//1.1 회원가입 인터페이스
void unregisterInterface(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection); //1.2 회원탈퇴 인터페이스

void loginInterface(MemberCollection* memberCollection); //2.1 로그인 인터페이스
void logoutInterface(MemberCollection* memberCollection);//2.2 로그아웃 인터페이스

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer); //3.1 티켓 등록
void checkTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection); // 3.2. 등록티켓 조회

void searchTicketInterface(TicketCollection* TicketCollection, MemberCollection* memberCollection);  //4.1 티켓 검색
void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer); //4.2 티켓 예약 인터페이스
void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer); //4.3 경매티켓 검색
void participateAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer); //4.4 경매참여 인터페이스
void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection);  //4.5 예약정보 조회 인터페이스

void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection, ReservationCollection *reservationCollection); //5.1 현재시간설정
void changeSessionInterface(MemberCollection* mCollection);  //6.1 Session변경

void guestSession(MemberCollection* p_membercollection); //6.2. gusetSession으로 변경
void exitProgram(); //7.1종료 인터페이스