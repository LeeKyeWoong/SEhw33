// Fliename: main.h
// Description: main���� ���Ǵ� ��� �� ������ ��� �Է�
// Created: 2019/05/29
// Author: �̰��

#pragma once

#include <iostream>
#include <string.h>
#include <cstdio>

#include "Member.h"           // ���             
#include "MemberCollection.h"
#include "SignUpUI.h"         // ȸ������
#include "SignUpControl.h"
#include "LoginUI.h"          // �α���
#include "LoginControl.h"
#include "LogoutUI.h"         // �α׾ƿ� 
#include "LogoutControl.h"
#include "UnregisterUI.h"     // ȸ��Ż�� 
#include "UnregisterControl.h"

//Ƽ�� ���, ��� Ƽ�� ��ȸ ���
#include "Ticket.h" //Ƽ��
#include "TicketCollection.h"
#include "CheckTicketControl.h" //��� Ƽ�� ��ȸ
#include "CheckTicketUI.h"
#include "RegisterTicketControl.h" //Ƽ�� ���
#include "RegisterTicketUI.h"

//Ƽ�� �˻� �� ���� ���, ��� ���� ���, ���� ���� ��ȸ ���
#include "Reservation.h" //����
#include "ReservationCollection.h"
#include "ReserveGeneralTicketUI.h" //�Ϲ�Ƽ�� ����
#include "ReserveGeneralTicketControl.h"
#include "SearchTicketControl.h" //Ƽ�� �˻�
#include "SearchTicketUI.h"
#include "SearchAuctionTicketControl.h" //���Ƽ�� �˻�
#include "SearchAuctionTicketUI.h"
#include "ParticipateAuctionTicketUI.h" //���� ����
#include "ParticipateAuctionTicketControl.h" 
#include "CheckReservationInfoUI.h" //�������� ��ȸ
#include "CheckReservationInfoControl.h"

//����ð� ���� ���, ���� ���� ���
#include "Timer.h" //Ÿ�̸�
#include "SetCurrentTimeUI.h" //���� �ð� ����
#include "SetCurrentTimeControl.h"
#include "ChangeSessionUI.h" //���� ����
#include "ChangeSessionControl.h"

void signupInterface(MemberCollection* memberCollection);//1.1 ȸ������ �������̽�
void unregisterInterface(TicketCollection* ticketCollection, ReservationCollection* reservationCollection, MemberCollection* memberCollection); //1.2 ȸ��Ż�� �������̽�

void loginInterface(MemberCollection* memberCollection); //2.1 �α��� �������̽�
void logoutInterface(MemberCollection* memberCollection);//2.2 �α׾ƿ� �������̽�

void registerTicketInterface(TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer * timer); //3.1 Ƽ�� ���
void checkTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection); // 3.2. ���Ƽ�� ��ȸ

void searchTicketInterface(TicketCollection* TicketCollection, MemberCollection* memberCollection);  //4.1 Ƽ�� �˻�
void reserveGeneralTicketInterface(ReservationCollection* reservationCollection, TicketCollection* TicketCollection, MemberCollection* MemberCollection, Timer* timer); //4.2 Ƽ�� ���� �������̽�
void searchAutionTicketInterface(TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer* timer); //4.3 ���Ƽ�� �˻�
void participateAuctionTicketInterface(ReservationCollection* reservationCollection, TicketCollection* ticketCollection, MemberCollection* memberCollection, Timer *timer); //4.4 ������� �������̽�
void checkReservationInterface(ReservationCollection* reservationCollection, MemberCollection* MemberCollection);  //4.5 �������� ��ȸ �������̽�

void setCurrentTimeInterface(Timer* timer, TicketCollection* ticketCollection); //5.1 ����ð�����
void changeSessionInterface(MemberCollection* mCollection);  //6.1 Session����

void guestSession(MemberCollection* p_membercollection); //6.2. gusetSession���� ����
void exitProgram(); //7.1���� �������̽�