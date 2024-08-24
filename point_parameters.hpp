#pragma once
#include <Siv3D.hpp>

// ポイント関連のパラメータクラス
class PointParameters final
{

private:

	PointParameters() = default; // コンストラクタ
	~PointParameters() = default; //デストラクタ

	//各種パラメータ
	int point; // 使用ポイント

public:

	PointParameters(const PointParameters&) = delete; //コピーコンストラクタを削除指定
	PointParameters& operator = (const PointParameters&) = delete; //コピー代入演算子を削除指定
	PointParameters(PointParameters&&) = delete; //ムーブコンストラクタを削除指定
	PointParameters& operator = (PointParameters&&) = delete; // ムーブ代入演算子を削除指定

	// インスタンスを取得
	static PointParameters& getInstance()
	{
		static PointParameters inst; // privateのコンストラクタ
		return inst;
	}

	// 使用ポイント
	// 使用ポイントを入力する
	int setPoint(int x)
	{
		point = x;
		return 0;
	}

	// 使用ポイントを加算する
	int addPoint(int x)
	{
		point += x;
		return 0;
	}

	// 使用ポイントを取得する
	int getPoint() const
	{
		return point;
	}

};
