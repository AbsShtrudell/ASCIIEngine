#include "MainMenuControlller.h"

MainMenuControlller::MainMenuControlller()
{
	startGameText = new Text(L"������� \"SPACE\" ����� ������ ����", 159);
	scoreMenuText = new Text(L"������� \"S\" ����� ������� ������� �������", 159);
	scoreMenuText->setLocation(Vec2(0, 2));
	adminMenuText = new Text(L"������� \"A\" ����� ������� ���� ��������������", 159);
	adminMenuText->setVisibility(admin);
	adminMenuText->setLocation(Vec2(0, 4));
	exitMenuText = new Text(L"������� \"ESC\" ����� �����", 159);
	exitMenuText->setLocation(Vec2(0, 4));
}

MainMenuControlller::~MainMenuControlller()
{
	startGameText->Destroy();
	scoreMenuText->Destroy();
	adminMenuText->Destroy();
	exitMenuText->Destroy();
}

void MainMenuControlller::OnKeyUp(int key)
{
	switch (key)
	{
	case 32:
		onStart.Call(0);
		break;
	case 'S':
		onScoreMenu.Call(0);
		break;
	case 'A':
		if (admin)
		{
			onAdminMenu.Call(0);
		}
		break;
	}
}

void MainMenuControlller::setAdminState(bool value)
{
	admin = value;
	adminMenuText->setVisibility(admin);
}
