#pragma once
#include <Siv3D.hpp>
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"
#include "point_parameters.hpp"

// ゲームからファイルへのアクセスに関する処理クラス
class GameFileSystem final
{
private:

	GameFileSystem() = default; // コンストラクタ
	~GameFileSystem() = default; //デストラクタ

	PlantParameters& plant = PlantParameters::getInstance(); // 植物クラスへのアクセス 
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス

public:

	GameFileSystem(const GameFileSystem&) = delete; //コピーコンストラクタを削除指定
	GameFileSystem& operator = (const GameFileSystem&) = delete; //コピー代入演算子を削除指定
	GameFileSystem(GameFileSystem&&) = delete; //ムーブコンストラクタを削除指定
	GameFileSystem& operator = (GameFileSystem&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static GameFileSystem& getInstance()
	{
		static GameFileSystem inst; // privateのコンストラクタ
		return inst;
	}


	// プレイデータの保存
	int DataSave()
	{
		// 保存先
		JSON savedata;

		// 植物パラメータ
		savedata[U"Plant"][U"Moisture"] = plant.getMoisture();
		savedata[U"Plant"][U"Fertilizer"] = plant.getFertilizer();
		savedata[U"Plant"][U"Modo"] = plant.getMood();
		savedata[U"Plant"][U"PodLevel"] = plant.getPodLevel();
		savedata[U"Plant"][U"PlantLevel"] = plant.getPlantLevel();

		// 電池パラメータ
		savedata[U"Battery"][U"ChargingPower"] = battery.getChargingPower();
		savedata[U"Battery"][U"Stock"] = battery.getBatteryStock();
		savedata[U"Battery"][U"MaxStock"] = battery.getMaxBatteryStock();

		// ポイント
		savedata[U"Point"] = point.getPoint();

		// 時間
		savedata[U"Time"] = Time::GetSecSinceEpoch();

		savedata.save(U"Data/AuditTrail.json");

		return 0;
	}

};
