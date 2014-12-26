#pragma once
#include "iostream"
class Singleton
{
public:
	static Singleton* getInstance();
	virtual ~Singleton();
private:
	static Singleton* _instance;
	Singleton();
	struct deleter{
		~deleter();
	};
	static deleter _deleter;
};


