#pragma once

#include "Observer.h"
#include <vector>
#include <iostream>

namespace itf {

	template<class ...Types>
	class Subject
	{

	public:
		void addObserver(Observer<Types...>* observer);
		void removeObserver(Observer<Types...>* observer);

	protected:
		void notifyObservers(Types... args);

	private:
		std::vector<Observer<Types...>*> observers;

	};

};