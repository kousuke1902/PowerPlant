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
		// ポイント消費可非
		if (PointParameters::getInstance().getPoint() > 10)
		{
			PointParameters::getInstance().addPoint(-10);
			PlantParameters::getInstance().addMoisture(10);
		}
		return 0;
	}

	// 肥料を与える
	int Fertilize()
	{
		// ポイント消費可非
		if (PointParameters::getInstance().getPoint() > 10)
		{
			PointParameters::getInstance().addPoint(-10);
			PlantParameters::getInstance().addFertilizer(10);
		}
		return 0;
	}

	// ポッドのレベルを上げる
	int PodUpgrade()
	{
		// ポイント消費可非
		if (PointParameters::getInstance().getPoint() > 10)
		{
			PointParameters::getInstance().addPoint(-10);
			PlantParameters::getInstance().addPodLevel();
		}
		return 0;
	}

	// 植物レベルを上げる
	int PlantUpgrafe()
	{
		// ポイント消費可非
		if (PointParameters::getInstance().getPoint() > 10)
		{
			PointParameters::getInstance().addPoint(-10);
			PlantParameters::getInstance().addPlantLevel();
		}
		return 0;
	}

	// 植物をタッチする
	int TouchPlant()
	{
		// 植物の瞬間発電量を充電する
		BatteryParameters::getInstance().addChargingPower(PlantParameters::getInstance().getMomentPower());
		return 0;
	}


	// 電池関連
	// 最大電池ストックを引き上げる
	int MaxBatteryStockUpgrade()
	{
		// ポイント消費可非
		if (PointParameters::getInstance().getPoint() > 10)
		{
			PointParameters::getInstance().addPoint(-10);
			BatteryParameters::getInstance().addMaxBatteryStock();
		}
		return 0;
	}
};
