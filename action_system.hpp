#pragma once
#include <Siv3D.hpp>
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"
#include "point_parameters.hpp"

#define _INTERVAL_TIME_ 60

class ActionSystem final
{
private:

	ActionSystem() = default; // コンストラクタ
	~ActionSystem() = default; // デストラクタ

	PlantParameters& plant = PlantParameters::getInstance(); // 植物クラスへのアクセス 
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス
	bool timer_flag = true; // 実行可能な状態か
	int mood_magnification; // 気分による倍率値


public:

	ActionSystem(const ActionSystem&) = delete; // コピーコンストラクタを削除指定
	ActionSystem& operator = (const ActionSystem&) = delete; //コピー代入演算子を削除指定
	ActionSystem(ActionSystem&&) = delete; //ムーブコンストラクタを削除指定
	ActionSystem& operator = (ActionSystem&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static ActionSystem& getInstance()
	{
		static ActionSystem inst; // privateのコンストラクタ
		return inst;
	}

	// 植物関連

	// 水やりを行う
	int Watering()
	{
		// パーティクル
		plant.addMoisture(10);
		return 0;
	}

	// 肥料を与える
	int Fertilize()
	{
		// パーティクル
		plant.addFertilizer(10);
		return 0;
	}

	// ポッドのレベルを上げる
	int PodUpgrade()
	{
		plant.addPodLevel();
		return 0;
	}

	// 植物レベルを上げる
	int PlantUpgrafe()
	{
		plant.addPlantLevel();
		return 0;
	}

	// 植物をタッチする
	int TouchPlant()
	{
		// ストックが最大の場合，充電できない
		if (battery.getMaxBatteryStock() != battery.getBatteryStock())
		{
			// 植物の瞬間発電量を充電する
			battery.addChargingPower(plant.getMomentPower() * plant.getMoodMagnification());
		}

		return 0;
	}

	// 植物の時間発電
	int TimePower()
	{
		// x秒毎に実行する
		if (Time::GetSecSinceEpoch() % _INTERVAL_TIME_ == 0 && timer_flag)
		{
			// 実行した
			timer_flag = false;

			// ストックが最大の場合，充電できない
			if (battery.getMaxBatteryStock() != battery.getBatteryStock())
			{
				// 植物の時間発電量を充電する
				battery.addChargingPower(plant.getTimePower());
			}

		}

		// フラグのリセット
		else if (Time::GetSecSinceEpoch() % _INTERVAL_TIME_ == 1)
		{
			// 未実行
			timer_flag = true;
		}


		return 0;
	}


	// 電池関連

	// 最大電池ストックを引き上げる
	int MaxBatteryStockUpgrade()
	{
		battery.addMaxBatteryStock();
		return 0;
	}

	// 電池を出荷する
	int BatteryShipping()
	{
		battery.setBatteryStock(0);
		return 0;
	}

	// 電池の充電完了確認
	int BatteryChargingCheck()
	{
		// ストックが最大の場合，充電できない．
		if (battery.getMaxBatteryStock() != battery.getBatteryStock())
		{
			if (battery.getChargingPower() >= 2000)
			{
				battery.addChargingPower(-2000);
				battery.addBatteryStock(1);
			}

		}

		return 0;
	}

	// システム処理

	// 更新
	int Update()
	{
		// 定期処理
		TimePower();
		BatteryChargingCheck();
		return 0;
	}

};
