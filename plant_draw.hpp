#pragma once
#include "action_system.hpp"
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"

class PlantDraw final
{
private:

	PlantDraw() = default; // コンストラクタ
	~PlantDraw() = default; // デストラクタ

	PlantParameters& plant = PlantParameters::getInstance(); // 植物クラスへのアクセス 
	BatteryParameters& battery = BatteryParameters::getInstance(); // 電池クラスへのアクセス
	PointParameters& point = PointParameters::getInstance(); // ポイントクラスへのアクセス
	Array<Texture> leafimg; // 葉っぱの画像イメージ

public:

	PlantDraw(const PlantDraw&) = delete; // コピーコンストラクタを削除指定
	PlantDraw& operator = (const PlantDraw&) = delete; //コピー代入演算子を削除指定
	PlantDraw(PlantDraw&&) = delete; //ムーブコンストラクタを削除指定
	PlantDraw& operator = (PlantDraw&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static PlantDraw& getInstance()
	{
		static PlantDraw inst; // privateのコンストラクタ
		return inst;
	}

	// 描画と
	int Draw()
	{
		for (int i = 0; i < leafimg.size(); ++i)
		{
			leafimg[i].scaled(0.4).draw(300, 300);

		}

		return 0;
	}

	// システム処理
	// 
	// 初期化
	int StartUp()
	{

		leafimg << Texture{ U"Data/Leaf.svg", TextureDesc::Mipped};

		return 0;
	}

	// 更新
	int Update()
	{
		Draw();

		return 0;
	}

};
