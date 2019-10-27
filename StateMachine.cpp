#include "StateMachine.h"

namespace lecture
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		mbIsAdding = true;
		mbIsReplacing = isReplacing;
		mNewState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		mbIsRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (mbIsRemoving && !mStates.empty())
		{
			mStates.pop();

			if (!mStates.empty())
			{
				mStates.top()->Resume();
			}

			mbIsRemoving = false;
		}

		if (mbIsAdding)
		{
			if (!mStates.empty())
			{
				if (mbIsReplacing)
				{
					mStates.pop();
				}
				else
				{
					mStates.top()->Pause();
				}
			}

			mStates.push(std::move(mNewState));
			mStates.top()->Init();
			mbIsAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		return mStates.top();
	}
}
