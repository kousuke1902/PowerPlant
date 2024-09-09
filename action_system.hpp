#pragma once
#include <Siv3D.hpp>
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"
#include "point_parameters.hpp"

class ActionSystem final
{
private:

	ActionSystem() = default; // コンストラクタ
	~ActionSystem() = default; // デストラクタ

	PlantParameters& plant = PlantParameters::getInstance(); // 植物クラスへのアクセス 
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス

	RoundRect plant_colision{ Arg::center(300.0, 600.0), 100.0, 500.0, 10 }; // 植物当たり判定


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
		point.addPoint(-10);
		plant.addPodLevel();
		return 0;
	}

	// 植物レベルを上げる
	int PlantUpgrafe()
	{
		point.addPoint(-10);
		plant.addPlantLevel();
		return 0;
	}

	// 植物をタッチする
	int TouchPlant()
	{
		plant_colision.draw();
		if (plant_colision.mouseOver() && MouseL.down())
		{
			// 植物の瞬間発電量を充電する
			battery.addChargingPower(plant.getMomentPower());

		}

		return 0;
	}


	// 電池関連

	// 最大電池ストックを引き上げる
	int MaxBatteryStockUpgrade()
	{
		point.addPoint(-10);
		battery.addMaxBatteryStock();
		return 0;
	}

	// 電池を出荷する
	int BatteryShipping()
	{
		point.addPoint(battery.getBatteryStock() * 100);
		battery.setBatteryStock(0);
		return 0;
	}

	// システム処理

	// 更新
	int Update()
	{
		TouchPlant();
		return 0;
	}

};
