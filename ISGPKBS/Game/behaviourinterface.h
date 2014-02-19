#pragma once

namespace isgp {
	// The default interface which allows an object to have certain behaviours.
	// This interface does not define a behaviour by itself.
	class BehaviourInterface
	{
	public:
		// Executes the implemented behaviour.
		// The executing will keep in mind how many milliseconds have passed.
		// This method must be overridden in a child class
		virtual void Update(const long ms) = 0;
	};
}
