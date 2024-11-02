#include <Siv3D.hpp>
#include "plant_parameters.hpp"
#include "battery_parameters.hpp"
#include "action_system.hpp"
#include "draw_system.hpp"
#include "particle_system.hpp"
#include "file_system.hpp"


void Main()
{
	// 背景の色を設定する
	Window::Resize(1200, 720);
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	PlantParameters& plant = PlantParameters::getInstance();
	BatteryParameters& battery = BatteryParameters::getInstance();
	PointParameters& point = PointParameters::getInstance();
	ActionSystem& action = ActionSystem::getInstance();
	DrawSystem& draw = DrawSystem::getInstance();

	battery.Startup();
	plant.Startup();
	point.Startup();

	while (System::Update())
	{
		action.Update();
		draw.Update();
	}

	GameFileSystem::getInstance().DataSave();
}

