#pragma once
#include <Siv3D.hpp>

// 植物の各種パラメータクラス
class PlantParameters final
{

private:

	PlantParameters() = default; // コンストラクタ
	~PlantParameters() = default; // デストラクタ

	// 各種パラメータ
	int moisture; // 土壌の湿り気
	int fertilizer; // 肥料値
	int mood; // 気分
	int pod_level; // ポッドのレベル
	int plant_level; // 植物のレベル
	int time_power; // 時間発電量
	int moment_power;  // 瞬間発電量

public:

	PlantParameters(const PlantParameters&) = delete; // コピーコンストラクタを削除指定
	PlantParameters& operator = (const PlantParameters&) = delete; // コピー代入演算子を削除指定
	PlantParameters(PlantParameters&&) = delete; // ムーブコンストラクタを削除指定
	PlantParameters& operator = (PlantParameters&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static PlantParameters& getInstance()
	{
		static PlantParameters inst; // privateのコンストラクタ
		return inst;
	}

	// 土壌
	// 土壌の湿り気数値を入力する
	int setMoisture(int x)
	{
		moisture = x;
		return 0;
	}

	// 土壌の湿り気数値を加算する
	int addMoisture(int x)
	{
		moisture += x;
		return 0;
	}

	// 土壌の湿り気数値を取得する
	int getMoisture() const
	{
		return moisture;
	}

	// 肥料
	// 肥料値を入力する
	int setFertilizer(int x)
	{
		fertilizer = x;
		return 0;
	}

	// 肥料値を加算する
	int addFertilizer(int x)
	{
		fertilizer += x;
		return 0;
	}

	// 肥料値の取得
	int getFertilizer() const
	{
		return fertilizer;
	}

	// 気分
	// 気分値を入力する
	int setMood(int x)
	{
		mood = x;
		return 0;
	}

	// 気分値を加算する
	int addMood(int x)
	{
		mood += x;
		return 0;
	}

	// 気分値の取得
	int getMood(int x)
	{
		return mood;
	}

	// ポッドレベル
	// ポッドレベルを入力する
	int setPodLevel(int x)
	{
		pod_level = x;
		return 0;
	}

	// ポッドレベルの加算
	int addPodLevel()
	{
		pod_level++;
		return 0;
	}

	// ポッドレベルの取得
	int getPodLevel()
	{
		return pod_level;
	}

	// 植物レベル
	// 植物レベルを入力する
	int setPlantLevel(int x)
	{
		plant_level = x;
		return 0;
	}

	// 植物レベルの加算
	int addPlantLevel()
	{
		plant_level++;
		return 0;
	}

	// 植物レベルの取得
	int getPlantLevel()
	{
		return plant_level;
	}

	// 時間発電量
	// 時間発電量を入力する
	int setTimePower(int x)
	{
		time_power = x;
		return 0;
	}

	// 時間発電量の加算
	int addTimePower(int x)
	{
		time_power += 0;
		return 0;
	}

	// 時間発電量の取得
	int getTimePower()
	{
		return time_power;
	}

	// 瞬間発電量(タッチ)
	// 瞬間発電量を入力する
	int setMomentPower(int x)
	{
		moment_power = x;
		return 0;
	}

	// 瞬間発電量の加算
	int addMomentPower(int x)
	{
		moment_power += x;
		return 0;
	}

	// 瞬間発電量の取得
	int getMomentPower()
	{
		return moment_power;
	}


};

