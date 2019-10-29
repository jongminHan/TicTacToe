#pragma once
#include <memory>
#include <stack>

#include "IState.h"

namespace lecture
{
	typedef std::unique_ptr<IState> IStateRef;

	class StateMachine
	{
	public:
		StateMachine();
		virtual ~StateMachine() = default;

		void AddState(IStateRef newState, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();

		IStateRef& GetActiveState();

	private:
		std::stack<IStateRef> mStates;
		IStateRef mNewState;

		bool mbIsRemoving;
		bool mbIsAdding;
		bool mbIsReplacing;
	};
}