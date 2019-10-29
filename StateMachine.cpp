#include "StateMachine.h"

namespace lecture
{
	StateMachine::StateMachine()
		: mbIsRemoving(false)
		, mbIsAdding(false)
		, mbIsReplacing(false)
	{
	}

	void StateMachine::AddState(IStateRef newState, bool isReplacing)
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

	IStateRef& StateMachine::GetActiveState()
	{
		return mStates.top();
	}
}
