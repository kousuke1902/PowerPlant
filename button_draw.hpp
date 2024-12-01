#pragma once

// ボタンの描画に関するクラス
class ButtonDraw final
{
private:



	Texture button_off; // ボタンを押下
	Texture button_on; // ボタン押下前

	ButtonDraw() = default; // コンストラクタ
	~ButtonDraw() = default; // デストラクタ

	RoundRect button_colision; // ボタン当たり判定
	

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
	bool Draw(int x, int y)
	{
		button_colision.x = x;
		button_colision.y = y;

		button_colision.draw();

		return false;
	}

	// システム処理

	// 初期化
	int StartUp()
	{
		Image img_off,img_on;

		// 画像読み込み
		button_off = Texture{ img_off.scaled(0.4), TextureDesc::Mipped };
		button_on = Texture{ img_on.scaled(0.4), TextureDesc::Mipped };

		button_colision = RoundRect{ Arg::center(400,300), 300, 50, 5 };

		return 0;
	}

};
