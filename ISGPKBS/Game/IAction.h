#pragma once
namespace isgp{
	// contains a piece of logic wich can be executed and is trothled by the time per frame
	class IAction{
		// execute somthing a time per frame
		virtual void Execute(double tpf) = 0;
	};
}