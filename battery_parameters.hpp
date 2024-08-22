#pragma once
#include <Siv3D.hpp>

class BatteryParameters final
{

private:

	BatteryParameters() = default; // コンストラクタ
	~BatteryParameters() = default; // デストラクタ

	// 各種パラメータ
	double charging_power; // 充電量
	int battery_stock; // 電池ストック
	int battery_max_stock; // 最大電池ストック


public:

	BatteryParameters(const BatteryParameters&) = delete; // コピーコンストラクタを削除指定
	BatteryParameters& operator = (const BatteryParameters&) = delete; // コピー代入演算子を削除指定
	BatteryParameters(BatteryParameters&&) = delete; // ムーブコンストラクタを削除指定
	BatteryParameters& operator = (BatteryParameters&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static BatteryParameters& getInstance()
	{
		static BatteryParameters inst; //privateのコンストラクタ
		return inst;
	}

	// 充電量
	// 充電量を入力する
	int setChargingPower(double x)
	{
		charging_power = x;
		return 0;
	}

};
