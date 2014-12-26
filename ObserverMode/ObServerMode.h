#pragma once
#include "vector"

template <class T>
inline void safe_delete(T t)
{
	if (t != nullptr)
	{
		delete t;
		t = nullptr;
	}
}

class Observer{
public:
	virtual void Updata() = 0;
};

class Subject{

public:
	void Attach(Observer *obj);
	void Detach(const Observer *obj);
	void Notify();

	std::vector<Observer*>::iterator find(const Observer *obj);
protected:
	std::vector<Observer*> _Observers;
};

class ConcreteSubject : public Subject
{
public:
	void setState(const std::string str);
	std::string getState() const;

	void Detach(const std::string name);

	std::vector<Observer*>::iterator find(const std::string &name);
private:
	std::string _subjectState;
};

class ConcreteObserver :public Observer
{
public:
	ConcreteObserver(ConcreteSubject *subject, const std::string name);

	ConcreteSubject* getSubject() const;
	void setSubject(ConcreteSubject* subject);

	std::string getName() const;

	virtual void Updata();

private:
	ConcreteSubject *_subject;
	std::string _name;
	std::string _observerState;
};
