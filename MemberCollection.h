#pragma once

#include <iostream>
#include <string>
#include "Member.h"

#define MAX 50

using namespace std;

class Member;

class MemberCollection
{
	// Class: MemberCollection
	// Description: Member를 element로 갖는 MemberCollection class
	// Created: 2019/05/28
	// Author: 이계웅

private:
	Member * member[MAX];  // Member를 저장하는 포인터를 원소로 하는 배열
	int memberNumber;      // Member 번호를 기록하는 변수

public:
	MemberCollection(Member member[MAX]);  // MemberCollection의 사용자 정의 생성자
	void addMember(string id, string password, string name, string idNum, string memType, bool sessionOn);  // MemberCollectoin에 Member객체를 저장하는 함수
	void deleteMember(int deleteMemberIndex);  // memberCollecton의 Member를 하나 삭제하는 함수
	Member *getMember(int memberIndex);  // memberIndex번째의 Member를 불러오는 함수
	Member *currentSession();  		// 현재 세션의 Member를 불러오는 함수
	int getCurrentSessionIndex();   // 현재 세션이 몇번재 MemberCollection의 객체인지 반환하는 함수
	int getMemberNumber();  			// MemberCollection에서 몇번째로 저장되어 있는지 반환하는 함수
	void setMemberNumber(int memberIndex); // memberNumber를 저장하는 함수
};
