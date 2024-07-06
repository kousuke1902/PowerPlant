#include <Siv3D.hpp>
#include "plant_parameters.hpp"


void Main()
{
	// 背景の色を設定する
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	PlantParameters& plant = PlantParameters::getInstance();
	plant.getMoisture();

	while (System::Update())
	{

	}
}

