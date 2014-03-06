#pragma once
namespace isgp{
	// contains a condition which can gaurd somthing
	class ICondition{
		virtual bool Check(double tpf) = 0;
	};
}