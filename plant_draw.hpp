#pragma once

// 植物描画に関してのクラス
class PlantDraw final
{
private:

	PlantDraw() = default; // コンストラクタ
	~PlantDraw() = default; // デストラクタ

	Array<Texture> leafimg; // 葉っぱの画像イメージ
	RoundRect plant_colision; // 植物当たり判定

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

	// 葉の描画
	int Draw()
	{
		for (int i = 0; i < leafimg.size() / 2; ++i)
		{
			//交互に描画
			leafimg[i].draw(Arg::bottomRight(300, 600));
			leafimg[i + 1].draw(Arg::bottomLeft(300, 600));
		}

		return 0;
	}

	// 当たり判定
	bool Colision()
	{
		plant_colision.draw();
		return plant_colision.mouseOver();
	}

	// システム処理
	// 
	// 初期化
	int StartUp()
	{
		Image img{ U"Data/Leaf.svg" };
		leafimg << Texture{ img.scaled(0.4), TextureDesc::Mipped};
		leafimg << Texture{ img.mirrored().scaled(0.4), TextureDesc::Mipped};

		plant_colision = RoundRect{ Arg::center(300,600), 200, 100, 5 };

		return 0;
	}

	// 更新
	int Update()
	{
		Draw();

		return 0;
	}

};
