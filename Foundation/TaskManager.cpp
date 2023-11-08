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



void TaskManager::RunTypeAll(RUN_TYPE type)
{
	for (int i = 0; i < TASK_LAYER::MAX_LAYER; ++i)
	{
		switch (type)
		{
		case RUN_TYPE::DO:
			_rootTask[i]->Do();
			break;

		case RUN_TYPE::DRAW:
			_rootTask[i]->Draw();
			break;

		case RUN_TYPE::PHYSICS:
			_rootTask[i]->Physics();
			break;
		}
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