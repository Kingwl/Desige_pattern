#include "stdafx.h"
#include "Singleton.h"
Singleton* Singleton::_instance = nullptr;
Singleton* Singleton::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Singleton();
	}
	return _instance;
}
Singleton::Singleton()
{
	std::cout << "single construct" << std::endl;
}


Singleton::~Singleton()
{
	std::cout << "single deconstruct" << std::endl;
}
Singleton::deleter::~deleter()
{
	if (Singleton::_instance != nullptr)
	{
		delete Singleton::_instance;
		Singleton::_instance = nullptr;
		system("pause");
	}
}
