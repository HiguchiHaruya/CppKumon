#include "stdafx.h"
#include "TaskBase.h"
#include "TaskManager.h"

using namespace Task;

static std::unique_ptr<Task::TaskManager> _instance;
Task::TaskManager* GetTaskManagerInstance()
{
	return _instance.get();
}


TaskManager::TaskManager()
{
	for (int i = 0; i < TASK_LAYER::MAX_LAYER; ++i)
	{
		_rootTask[i] = std::make_shared<TaskBase>();
	}
}

void TaskManager::Run(RUN_TYPE type)
{
	GetTaskManagerInstance()->RunTypeAll(type);
}

void TaskManager::Register(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	GetTaskManagerInstance()->RegisterTask(task, layer);
}

void TaskManager::Destroy(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	GetTaskManagerInstance()->DestroyTask(task, layer);
}

void TaskManager::Create()
{
	if (_instance == nullptr)
	{
		_instance = std::unique_ptr<Task::TaskManager>(new Task::TaskManager());
	}
}

void TaskManager::Release()
{
	_instance.release();
}

void TaskManager::Runner(RUN_TYPE type, std::shared_ptr<TaskBase> current)
{
	switch (type)
	{
	case RUN_TYPE::DO:
		//初期化系
		if (current->_init)
		{
			current->Start();
			current->_init = false;
		}
		current->Do();
		break;

	case RUN_TYPE::DRAW:
		current->Draw();
		break;

	case RUN_TYPE::PHYSICS:
		current->Physics();
		break;
	}

	auto childs = current->GetChilds();
	for (std::shared_ptr<TaskBase> c : childs)
	{
		Runner(type, c);
	}
};

void TaskManager::RunTypeAll(RUN_TYPE type)
{
	for (int i = 0; i < TASK_LAYER::MAX_LAYER; ++i)
	{
		Runner(type, _rootTask[i]);
	}
}

void TaskManager::RegisterTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	_rootTask[layer]->AddChild(task);
}

void TaskManager::DestroyTask(std::shared_ptr<TaskBase> task, TASK_LAYER layer)
{
	_rootTask[layer]->RemoveChild(task);
}