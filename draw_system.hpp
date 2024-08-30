#pragma once
#include <Siv3D.hpp>
#include "action_system.hpp"
#include "point_parameters.hpp"

class DrawSystem final
{

private:

	DrawSystem() = default; // コンストラクタ
	~DrawSystem() = default; // デストラクタ

	ActionSystem& action = ActionSystem::getInstance(); // 操作クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス

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

	// 各種表示

	// 各種ボタン
	// 水やり
	int WaterringButton()
	{
		// 利用可能確認
		if (point.getPoint() > 10)
		{


		}

		return 0;
	}

};
