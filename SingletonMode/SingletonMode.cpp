// SingletonMode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Singleton.h"

int main(int argc, _TCHAR* argv[])
{
	auto i = Singleton::getInstance();
	system("pause");
	return 0;
}

