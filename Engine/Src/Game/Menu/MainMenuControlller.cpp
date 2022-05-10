#include "MainMenuControlller.h"

MainMenuControlller::MainMenuControlller()
{
	startGameText = new Text(L"������� \"SPACE\" ����� ������", 159);
	scoreMenuText = new Text(L"������� \"A\" ����� ������� ������� ����", 159);
	scoreMenuText->setLocation(Vec2(0, 2));

	camera = new Camera(this);
}

MainMenuControlller::~MainMenuControlller()
{
	delete camera;
	delete startGameText;
	delete scoreMenuText;
}

void MainMenuControlller::OnKeyUp(int key)
{
	switch (key)
	{
	case 32:
		onStart.Call(0);
		break;
	}
}
