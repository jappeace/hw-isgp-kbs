#pragma once

#include "TimesPerSecondCounter.h"
#include <ctime>
namespace isgp {
	TimesPerSecondCounter::TimesPerSecondCounter(void) : _tempUpdateCount(0), _savedUpdateCount(0)
	{
		_lastClock = clock();
	}


	TimesPerSecondCounter::~TimesPerSecondCounter(void)
	{
	}

	void TimesPerSecondCounter::Update() {
		_tempUpdateCount++;
		if(clock() - _lastClock > 1000) {
			_savedUpdateCount = _tempUpdateCount;
			_tempUpdateCount = 0;
			_lastClock = clock();
		}
	}

	int TimesPerSecondCounter::Get() {
		return _savedUpdateCount;
	}
}