#pragma once
#include <vector>

namespace Task
{
	class TaskBase 
	{

	private:
		int		_id;		//!<クラスＩＤ
		int		_priority;	//!<処理優先度

	protected:
		std::vector<std::shared_ptr<TaskBase>> _childs;	//!<子供

	public:
		TaskBase() {}
		virtual	~TaskBase() {};

		int		AddChild(std::shared_ptr<TaskBase> task);
		void	RemoveChild(std::shared_ptr<TaskBase> task);
		const std::vector<std::shared_ptr<TaskBase>>& GetChilds() { return _childs; }

		virtual	void Start() {};		//最初の一回目
		virtual	void Do() {};			//メイン処理
		virtual	void Physics() {};		//演算処理
		virtual	void Draw() {};			//描画処理
		virtual	void Release() {};		//解放
	};
}
