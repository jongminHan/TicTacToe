#include "StateMachine.h"

namespace lecture
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		mIsAdding = true;
		mIsReplacing = isReplacing;
		mNewState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		mIsRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (mIsRemoving && !mStates.empty())
		{
			mStates.pop();

			if (!mStates.empty())
			{
				mStates.top()->Resume();
			}

			mIsRemoving = false;
		}

		if (mIsAdding)
		{
			if (!mStates.empty())
			{
				if (mIsReplacing)
				{
					mStates.pop();
				}
			}
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		// TODO: insert return statement here
	}
}