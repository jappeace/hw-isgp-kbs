#pragma once

namespace isgp {
	class TimesPerSecondCounter {
	private:
		// The amount of update calls in the current second so far.
		unsigned int _tempUpdateCount;
		// The amount of update calls in the last second.
		unsigned int _savedUpdateCount;
		// The last time the update call counter was reset.
		unsigned int _lastClock;

	public:
		TimesPerSecondCounter(void);
		~TimesPerSecondCounter(void);

		// Increases the update count by one for this second.
		void Update();
		// Gets the latest update count
		int Get();
	};
}
