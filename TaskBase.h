#pragma once
#include <vector>

namespace Task
{
	class TaskBase 
	{

	private:
		int		_id;		//!<�N���X�h�c
		int		_priority;	//!<�����D��x

	protected:
		std::vector<std::shared_ptr<TaskBase>> _childs;	//!<�q��

	public:
		TaskBase() {}
		virtual	~TaskBase() {};

		int		AddChild(std::shared_ptr<TaskBase> task);
		void	RemoveChild(std::shared_ptr<TaskBase> task);
		const std::vector<std::shared_ptr<TaskBase>>& GetChilds() { return _childs; }

		virtual	void Start() {};		//�ŏ��̈���
		virtual	void Do() {};			//���C������
		virtual	void Physics() {};		//���Z����
		virtual	void Draw() {};			//�`�揈��
		virtual	void Release() {};		//���
	};
}
