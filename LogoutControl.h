#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutUI;
class MemberCollection;

class LogoutControl
{
	//Class: LogoutControl
	//Description: Logout의 control class
	//Created: 2019/05/31
	//Author: 이계웅

private:
	string logoutId;  //Logout을 시도하는 Memeber의 ID를 저장하는 변수
public:
	void requestLogout(MemberCollection* memberCollection); // 현재 sessionOn상태의 회원을 세션 종료하는 함수
	string getLogoutId();  // logoutID를 반환하는 함수
};