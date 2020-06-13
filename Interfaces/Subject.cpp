#include "Subject.h"

namespace itf {

	template<class ...Types>
	void Subject<Types...>::addObserver(Observer<Types...>* observer)
	{
		observers.push_back(observer);
	}

	template<class ...Types>
	void Subject<Types...>::removeObserver(Observer<Types...>* observer)
	{
		auto iterator = std::find(observers.begin(), observers.end(), observer);

		if (iterator != observers.end()) {
			observers.erase(iterator);
		}
#if !defined(NDEBUG)
		else {
			std::cout << "Warning: Observer " << observer << "was not found!" << std::endl;
		}
#endif
	}

	template<class ...Types>
	void Subject<Types...>::notifyObservers(Types... args)
	{
		for (Observer<Types...>* observer : observers) {
			observer->updateObservers(args...);
		}
	}
}