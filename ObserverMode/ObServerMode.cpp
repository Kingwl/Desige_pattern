#include "stdafx.h"
#include "ObServerMode.h"
#include "string"
#include "iostream"

void Subject::Attach(Observer *obj)
{
	if (obj != nullptr)
	{
		_Observers.push_back(obj);
	}
}

void Subject::Detach(const Observer *obj)
{
	if (obj != nullptr)
	{
		auto iter = find(obj);
		if (iter != _Observers.end())
		{
			_Observers.erase(iter);
		}
	}
}

void Subject::Notify()
{
	for (auto &r : _Observers)
	{
		if (r != nullptr)
			r->Updata();
	}
}

std::vector<Observer*>::iterator Subject::find(const Observer *obj)
{
	auto iter = _Observers.begin();
	for (; iter != _Observers.end(); ++iter)
	{
		if (*iter == obj) break;
	}
	return iter;
}

void ConcreteSubject::setState(const std::string str)
{
	_subjectState = str;
}

std::string ConcreteSubject::getState() const
{
	return _subjectState;
}

void ConcreteSubject::Detach(const std::string name)
{
	auto iter = find(name);
	if (iter != _Observers.end())
		Subject::Detach(*iter);
}

std::vector<Observer*>::iterator ConcreteSubject::find(const std::string &name)
{
	auto iter = _Observers.begin();
	for (; iter != _Observers.end(); ++iter)
	{
		ConcreteObserver *CObj = dynamic_cast<ConcreteObserver*>(*iter);
		if (CObj->getName() == name) break;
	}
	return iter;
}

ConcreteObserver::ConcreteObserver(ConcreteSubject *subject, const std::string name)
:_subject(subject), _name(name)
{
	
}

ConcreteSubject* ConcreteObserver::getSubject() const
{
	return _subject;
}

void ConcreteObserver::setSubject(ConcreteSubject* subject)
{
	_subject = subject;
}

void ConcreteObserver::Updata()
{
	_observerState = _subject->getState();
	std::cout << _name << " " << _observerState << std::endl;
}

std::string ConcreteObserver::getName() const
{
	return _name;
}