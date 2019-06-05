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
	// Description: Member�� element�� ���� MemberCollection class
	// Created: 2019/05/28
	// Author: �̰��

private:
	Member * member[MAX];  // Member�� �����ϴ� �����͸� ���ҷ� �ϴ� �迭
	int memberNumber;      // Member ��ȣ�� ����ϴ� ����

public:
	MemberCollection(Member member[MAX]);  // MemberCollection�� ����� ���� ������
	void addMember(string id, string password, string name, string idNum, string memType, bool sessionOn);  // MemberCollectoin�� Member��ü�� �����ϴ� �Լ�
	void deleteMember(int deleteMemberIndex);  // memberCollecton�� Member�� �ϳ� �����ϴ� �Լ�
	Member *getMember(int memberIndex);  // memberIndex��°�� Member�� �ҷ����� �Լ�
	Member *currentSession();  		// ���� ������ Member�� �ҷ����� �Լ�
	int getCurrentSessionIndex();   // ���� ������ ����� MemberCollection�� ��ü���� ��ȯ�ϴ� �Լ�
	int getMemberNumber();  			// MemberCollection���� ���°�� ����Ǿ� �ִ��� ��ȯ�ϴ� �Լ�
	void setMemberNumber(int memberIndex); // memberNumber�� �����ϴ� �Լ�
};
