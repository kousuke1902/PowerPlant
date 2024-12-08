#pragma once

// ボタンの描画に関するクラス
class ButtonDraw final
{
private:



	Texture purchase_button_off; // 購入ボタンを押下
	Texture purchase_button_on; // 購入ボタン押下前

	ButtonDraw() = default; // コンストラクタ
	~ButtonDraw() = default; // デストラクタ

	Array<RoundRect> purchase_button_colision; // 購入ボタン当たり判定
	

public:

	ButtonDraw(const ButtonDraw&) = delete; // コピーコンストラクタを削除指定
	ButtonDraw& operator = (const ButtonDraw&) = delete; //コピー代入演算子を削除指定
	ButtonDraw(ButtonDraw&&) = delete; //ムーブコンストラクタを削除指定
	ButtonDraw& operator = (ButtonDraw&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static ButtonDraw& getInstance()
	{
		static ButtonDraw inst; // privateのコンストラクタ
		return inst;
	}

	// 描画
	int Draw(size_t id)
	{

		purchase_button_on.draw(purchase_button_colision[id].x, purchase_button_colision[id].y);

		return 0;
	}

	// 当たり判定
	bool Colision(size_t id)
	{
		if (purchase_button_colision.size() > id)
		{
			// purchase_button_colision[id].draw();

			return purchase_button_colision[id].mouseOver();
		}

		return false;
	}

	// システム処理

	// 初期化
	int StartUp()
	{
		Image img_off{ U"Data/button0.svg" }, img_on{ U"Data/button1.svg" };

		// 画像読み込み
		purchase_button_off = Texture{ img_off.scaled(0.4), TextureDesc::Mipped };
		purchase_button_on = Texture{ img_on.scaled(0.4), TextureDesc::Mipped };

		// 購入各ボタン 水やり，肥料，ポッド，電池ストック，出荷
		for (int time = 0; time < 5; ++time)
		{
			purchase_button_colision << RoundRect{ Arg::center(1000,200 + 100 * time), 230, 64, 5 };
		}
		


		return 0;
	}

};
