#include <iostream>
#include <memory>
#include "DxLib.h"
#include "TaskManager.h"
#include "MainGameSequence.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	// ウインドウモードに変更
	ChangeWindowMode(TRUE);

	if( DxLib_Init() == -1 )	// ＤＸライブラリ初期化処理
	{
		 return -1;				// エラーが起きたら直ちに終了
	}

	//バックバッファの設定
	SetDrawScreen(DX_SCREEN_BACK);

	//初期化
	Task::TaskManager::Create();

	//ゲームシーケンス作成
	auto gameSequence = std::make_shared<MainGameSequence>();
	gameSequence->NextState(MAIN_GAME_SEQUENCE::TITLE); //タイトルから始まる

	// ESCキーが押されるまでループ
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		clsDx();

		gameSequence->Loop();

		// 裏画面の内容を表画面に反映します
		ScreenFlip();

		if (ProcessMessage() == -1)
		{
			// エラーが起きたらループを抜ける
			break;
		}
	}

	//解放
	Task::TaskManager::Release();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	return 0 ;
}
