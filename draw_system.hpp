﻿#pragma once
#include <Siv3D.hpp>
#include "action_system.hpp"
#include "battery_parameters.hpp"
#include "point_parameters.hpp"

#define _BUTTON_SIZE_ Vec2{200.0, 50.0}

class DrawSystem final
{

private:

	DrawSystem() = default; // コンストラクタ
	~DrawSystem() = default; // デストラクタ

	ActionSystem& action = ActionSystem::getInstance(); // 操作クラスへのアクセス
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス

	Font point_text{ FontMethod::MSDF, 60 }; // ポイント表記
	Font charging_power_text{ FontMethod::MSDF, 60 }; // 充電量表記
	Font battery_stock_text{ FontMethod::MSDF, 60 }; // 電池ストック表記
	Font max_battery_stock_text{ FontMethod::MSDF, 60 }; // 最大電池ストック表記
	RoundRect waterring_button{ Arg::center(400.0, 200.0), _BUTTON_SIZE_ , 5.0 }; // 水やりボタン



	// 各種表示
	
	// ポイント表示
	int PointView()
	{
		point_text(U"{:}"_fmt(point.getPoint())).draw(50, Arg::leftCenter(600.0, 100.0), Palette::Black);
		return 0;
	}

	// 充電量表示
	int ChargingPowerView()
	{
		charging_power_text(U"{:}"_fmt(battery.getChargingPower())).draw(50, Arg::leftCenter(600.0, 200.0), Palette::Black);
		return 0;
	}

	// 電池ストック表示
	int BatteryStockView()
	{
		battery_stock_text(U"{:}"_fmt(battery.getBatteryStock())).draw(50, Arg::leftCenter(600.0, 300.0), Palette::Black);
		return 0;
	}

	//最大電池ストック表示
	int MaxBatteryStockView()
	{
		max_battery_stock_text(U"{:}"_fmt(battery.getMaxBatteryStock())).draw(50, Arg::leftCenter(600.0, 400.0), Palette::Black);
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

	//

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
	
	//更新
	int Update()
	{
		PointView();
		ChargingPowerView();
		WaterringButton();
		return 0;
	}

};
