#include "GameObjectManager.h"
#include "PackManScreen.h"

std::vector<std::list<ConsoleGameObject*>> GameObjectManager::AllObject;

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::ConsoleAllObjectUpdate()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; Start++)
		{
			ConsoleGameObject* Object = *Start;
			
			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Update();
		}
	}
}

void GameObjectManager::ConsoleAllObjectRender()
{
	//PackManScreen::GetMainScreen().ScreenClear();

	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object || false == Object->IsUpdate())
			{
				continue;
			}
			Object->Render();
		}
	}
	PackManScreen::GetMainScreen().ScreenPrint();
}

void GameObjectManager::ConsoleAllObjectRelease()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();

		for (; Start != End; )
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object || false == Object->IsDeath())
			{
				++Start;
				continue;
			}

			Start = Group.erase(Start);
			delete Object;
			Object = nullptr;
		}
	}
}

void GameObjectManager::ConsoleAllObjectDelete()
{
	for (size_t GroupIndex = 0; GroupIndex < AllObject.size(); GroupIndex++)
	{
		std::list<ConsoleGameObject*>& Group = AllObject[GroupIndex];

		std::list<ConsoleGameObject*>::iterator Start = Group.begin();
		std::list<ConsoleGameObject*>::iterator End = Group.end();


		for (; Start != End; ++Start)
		{
			ConsoleGameObject* Object = *Start;

			if (nullptr == Object)
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}
	}
}