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

	// 充電量を加算する
	int addChargingPower(double x)
	{
		charging_power += x;
		return 0;
	}

	// 充電量を取得する
	double getChargingPower() const
	{
		return charging_power;
	}

	// 電池ストック
	// 電池ストックを入力する
	int setBatteryStock(int x)
	{
		battery_stock = x;
		return 0;
	}

	// 電池ストックを加算する
	int addBatteryStock(int x)
	{
		battery_stock += x;
		return 0;
	}

	// 電池ストックを取得する
	int getBatteryStock() const
	{
		return battery_stock;
	}

	// 最大電池ストック
	// 最大電池ストックを入力する
	int setMaxBatteryStock(int x)
	{
		battery_max_stock = x;
		return 0;
	}

	// 最大電池ストックを加算する
	int addMaxBatteryStock(int x)
	{
		battery_max_stock += x;
		return 0;
	}

	// 最大電池ストックを取得する
	int getMaxBatteryStock() const
	{
		return battery_max_stock;
	}

};
