#pragma once
#include <memory>
#include <stack>

#include "IState.h"

namespace lecture
{
	typedef std::unique_ptr<IState> StateRef;

	class StateMachine
	{
	public:
		StateMachine() = default;
		virtual ~StateMachine() = default;

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> mStates;
		StateRef mNewState;

		bool mIsRemoving;
		bool mIsAdding;
		bool mIsReplacing;
	};
}