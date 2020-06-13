#pragma once

namespace itf {

	template<class ... Types>
	class Observer
	{
	public:
		virtual void updateObservers(Types... args) = 0;

	};

}