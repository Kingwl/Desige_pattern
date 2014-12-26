// ObServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ObServerMode.h"

int main(int argc, _TCHAR* argv[])
{

	ConcreteSubject *subject = new ConcreteSubject();
	subject->Attach(new ConcreteObserver(subject, "Observer A"));
	subject->Attach(new ConcreteObserver(subject, "Observer B"));
	subject->Attach(new ConcreteObserver(subject, "Observer C"));
	subject->setState("Ready!");
	subject->Notify();
	subject->Detach("Observer A");
	subject->setState("Hello!");
	subject->Notify();
	system("pause");
	return 0;
}

