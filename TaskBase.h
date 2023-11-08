#pragma once
#include <vector>

namespace Task
{
	class TaskBase 
	{

	private:
		int		_id;		//!<ƒNƒ‰ƒX‚h‚c
		int		_priority;	//!<ˆ——Dæ“x

	protected:
		std::vector<std::shared_ptr<TaskBase>> _childs;	//!<q‹Ÿ

	public:
		TaskBase() {}
		virtual	~TaskBase() {};

		int		AddChild(std::shared_ptr<TaskBase> task);
		void	RemoveChild(std::shared_ptr<TaskBase> task);
		const std::vector<std::shared_ptr<TaskBase>>& GetChilds() { return _childs; }

		virtual	void Start() {};		//Å‰‚Ìˆê‰ñ–Ú
		virtual	void Do() {};			//ƒƒCƒ“ˆ—
		virtual	void Physics() {};		//‰‰Zˆ—
		virtual	void Draw() {};			//•`‰æˆ—
		virtual	void Release() {};		//‰ğ•ú
	};
}
