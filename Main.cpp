﻿#include <Siv3D.hpp>
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"


void Main()
{
	// 背景の色を設定する
	Window::Resize(1200, 720);
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	PlantParameters& plant = PlantParameters::getInstance();
	BatteryParameters& battery = BatteryParameters::getInstance();

	plant.getMoisture();

	while (System::Update())
	{

	}
}

