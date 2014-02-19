#pragma once
class BehaviourInterface
{
public:
	// Executes the implemented behaviour.
	// The executing will keep in mind how many milliseconds have passed.
	// This method must be overridden in a child class
	virtual void Update(long ms) = 0;
};

