#include <iostream>
#include <memory>
#include "stdafx.h"
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
	gameSequence->NextState(MAIN_GAME_SEQUENCE::INGAME); //�^�C�g������n�܂�

	int tick = GetNowCount();
	int fps = 0;
	int fps_view = 0;

	// ESC�L�[���������܂Ń��[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();
		clsDx();

		//TODO:�{���͕ʃX���b�h�œ�����
		TaskManager::Run(RUN_TYPE::PHYSICS);


		//���C���X���b�h
		TaskManager::Run(RUN_TYPE::DO);
		gameSequence->Loop();

		//�ʃX���b�h�ł����Loop�͓�������Ƃ悢���A�������܂ł��Ȃ��Ă�����
		TaskManager::Run(RUN_TYPE::DRAW);

		fps++;
		if (GetNowCount() - tick > 1000)
		{
			tick += 1000;
			fps_view = fps;
			fps = 0;
		}
		DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS: %d", fps_view);

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
