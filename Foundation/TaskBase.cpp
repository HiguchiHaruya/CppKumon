
#include "stdafx.h"
#include "TaskBase.h"

using namespace Task;

int		TaskBase::AddChild(std::shared_ptr<TaskBase> task)
{
	_childs.push_back(task);
	return (int)_childs.size() - 1;
}

void	TaskBase::RemoveChild(std::shared_ptr<TaskBase> task)
{
	for (auto itr = _childs.begin(); itr != _childs.end(); ++itr) {
		if (*itr == task)
		{
			_childs.erase(itr);
			break;
		}
	}
}
