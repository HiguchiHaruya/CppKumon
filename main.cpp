#include <iostream>
#include <memory>
#include "DxLib.h"
#include "TaskManager.h"
#include "MainGameSequence.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	// �E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);

	if( DxLib_Init() == -1 )	// �c�w���C�u��������������
	{
		 return -1;				// �G���[���N�����璼���ɏI��
	}

	//�o�b�N�o�b�t�@�̐ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//������
	Task::TaskManager::Create();

	//�Q�[���V�[�P���X�쐬
	auto gameSequence = std::make_shared<MainGameSequence>();
	gameSequence->NextState(MAIN_GAME_SEQUENCE::TITLE); //�^�C�g������n�܂�

	// ESC�L�[���������܂Ń��[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();
		clsDx();

		gameSequence->Loop();

		// ����ʂ̓��e��\��ʂɔ��f���܂�
		ScreenFlip();

		if (ProcessMessage() == -1)
		{
			// �G���[���N�����烋�[�v�𔲂���
			break;
		}
	}

	//���
	Task::TaskManager::Release();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	return 0 ;
}
