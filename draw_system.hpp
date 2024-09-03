#pragma once
#include <Siv3D.hpp>
#include "action_system.hpp"
#include "point_parameters.hpp"

#define _BUTTON_SIZE_ Vec2{200.0, 50.0}

class DrawSystem final
{

private:

	DrawSystem() = default; // コンストラクタ
	~DrawSystem() = default; // デストラクタ

	ActionSystem& action = ActionSystem::getInstance(); // 操作クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス
	Font point_text; // ポイント表記
	RoundRect waterring_button; // 水やりボタン



	// 各種表示
	// ポイント表示
	int PointView()
	{
		point_text(U"{:}"_fmt(point.getPoint())).draw(50, Arg::leftCenter(600.0, 100.0), Palette::Black);
		return 0;
	}


	// 各種ボタン
	// 水やり
	int WaterringButton()
	{
		// 利用可能確認
		if (point.getPoint() > 10)
		{
			// 明るく表示 使用できることを提示
			waterring_button.draw(Palette::Skyblue);

			//ボタンをマウス左クリック
			if (waterring_button.mouseOver() && MouseL.down())
			{
				point.addPoint(-10);
				action.Watering();
			}

		}


		else
		{
			// 暗く表示 使用出来ないことの提示
			waterring_button.draw(Palette::Lightgray);
		}

		return 0;
	}


public:

	DrawSystem(const DrawSystem&) = delete; // コピーコンストラクタを削除指定
	DrawSystem& operator = (const DrawSystem&) = delete; //コピー代入演算子を削除指定
	DrawSystem(DrawSystem&&) = delete; //ムーブコンストラクタを削除指定
	DrawSystem& operator = (DrawSystem&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static DrawSystem& getInstance()
	{
		static DrawSystem inst; // privateのコンストラクタ
		return inst;
	}


	// システム処理
	// 初期化
	int Startup()
	{
		waterring_button = RoundRect{ Arg::center(400.0, 200.0), _BUTTON_SIZE_ , 5.0};
		point_text = Font{ FontMethod::MSDF, 60 };

		return 0;
	}

	//更新
	int Update()
	{
		PointView();
		WaterringButton();
		return 0;
	}

};
