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

	// プレイデータの読取
	int DataLoad()
	{

		// 読込先
		JSON loaddata = JSON::Load(U"Data/AuditTrail.json");

		// データの有無確認
		if (not loaddata)return 0;
		
		// 植物パラメータ
		plant.setMoisture(loaddata[U"Plant"][U"Moisture"].get<int32>());
		plant.setFertilizer(loaddata[U"Plant"][U"Fertilizer"].get<int32>());
		plant.setMood(loaddata[U"Plant"][U"Modo"].get<int32>());
		plant.setPodLevel(loaddata[U"Plant"][U"PodLevel"].get<int32>());
		plant.setPlantLevel(loaddata[U"Plant"][U"PlantLevel"].get<int32>());

		// 電池パラメータ
		battery.setChargingPower(loaddata[U"Battery"][U"ChargingPower"].get<int32>());
		battery.setBatteryStock(loaddata[U"Battery"][U"Stock"].get<int32>());
		battery.setMaxBatteryStock(loaddata[U"Battery"][U"MaxStock"].get<int32>());

		// ポイント
		point.setPoint(loaddata[U"Point"].get<int32>());

		// 時間差分処理

		return 0;

	}

};
