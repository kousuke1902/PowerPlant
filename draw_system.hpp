#pragma once
#include <Siv3D.hpp>
#include "action_system.hpp"
#include "battery_parameters.hpp"
#include "point_parameters.hpp"
#include "plant_draw.hpp"
#include "button_draw.hpp"

#define _BUTTON_SIZE_ Vec2{200.0, 50.0}

// ゲームでの描画処理に関するクラス
class DrawSystem final
{

private:

	DrawSystem() = default; // コンストラクタ
	~DrawSystem() = default; // デストラクタ

	ActionSystem& action = ActionSystem::getInstance(); // 操作クラスへのアクセス
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス
	PlantDraw& plant_draw = PlantDraw::getInstance(); // 植物描画クラスへのアクセス
	ButtonDraw& button_draw = ButtonDraw::getInstance(); // ボタン描画クラスへのアクセス

	// 表示
	Font point_text{ FontMethod::MSDF, 60 }; // ポイント表記
	Font charging_power_text{ FontMethod::MSDF, 60 }; // 充電量表記
	Font battery_stock_text{ FontMethod::MSDF, 60 }; // 電池ストック表記
	Font max_battery_stock_text{ FontMethod::MSDF, 60 }; // 最大電池ストック表記
	Font button_text{ FontMethod::MSDF, 60 }; // ボタンの文字表記

	// 各種表示
	
	// ポイント表示
	int PointView()
	{
		point_text(U"{:}"_fmt(point.getPoint()),U"pt").draw(50, Arg::rightCenter(1100.0, 100.0), Palette::Black);
		return 0;
	}

	// 充電量表示
	int ChargingPowerView()
	{
		charging_power_text(U"{:}"_fmt(battery.getChargingPower()),U"mA").draw(50, Arg::leftCenter(600.0, 200.0), Palette::Black);
		return 0;
	}

	// 電池ストック表示
	int BatteryStockView()
	{
		battery_stock_text(U"{:}"_fmt(battery.getBatteryStock()),U"本").draw(50, Arg::leftCenter(600.0, 300.0), Palette::Black);
		return 0;
	}

	//最大電池ストック表示
	int MaxBatteryStockView()
	{
		max_battery_stock_text(U"最大", U"{:}"_fmt(battery.getMaxBatteryStock()),U"本").draw(50, Arg::leftCenter(600.0, 400.0), Palette::Black);
		return 0;
	}

	// 

	// 各種ボタン

	// 水やり
	int WaterringButton()
	{
		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 id=0
			button_draw.Draw(0);

			
		}

		else
		{
	
		}

		return 0;
	}

	// 肥料
	int FertilizerButton()
	{
		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 id=1
			button_draw.Draw(1);
		}

		else
		{
			// 暗く表示 使用出来ないことの提示
			
		}

		return 0;
	}

	// ポッドアップグレード
	int PodUpgradeButton()
	{

		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 id=2
			button_draw.Draw(2);
		}

		else
		{
			// 暗く表示 使用出来ないことの提示
			
		}

		return 0;
	}


	// プラントアップグレード
	int PlantUpgradeButton()
	{
		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 
			
		}

		else
		{
			// 暗く表示 使用出来ないことの提示
			
		}

		return 0;
	}
	// 電池ストック追加
	int MaxButteryStockUpgradeButton()
	{
		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 id=3
			button_draw.Draw(3);

		}

		else
		{
			// 暗く表示 使用出来ないことの提示
			
		}

		return 0;
	}

	// 電池出荷
	int BatteryShippingButton()
	{
		// 利用可能確認
		if (point.getPoint() >= 10)
		{
			// 明るく表示 使用できることを提示 id=4
			button_draw.Draw(4);

		}

		else
		{
			// 暗く表示 使用出来ないことの提示

		}

		return 0;
	}

	// 植物タッチ
	int TouchPlant()
	{
		// 描画
		plant_draw.Draw();		

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
	
	//更新
	int Update()
	{
		// 表示
		PointView();
		ChargingPowerView();
		BatteryStockView();
		MaxBatteryStockView();

		// ボタン
		WaterringButton();
		FertilizerButton();
		PodUpgradeButton();
		// PlantUpgradeButton();
		MaxButteryStockUpgradeButton();
		BatteryShippingButton();

		// システム
		TouchPlant();

		return 0;
	}

};
