#pragma once
#include "GameEngineArray.h"
#include "ConsoleGameObject.h"
#include <vector>
#include <list>

// Ό³Έν :
class GameObjectManager
{
public:
	template<typename ObjectType>
	static ObjectType* CreateConsoleObject(int _Order)
	{
		if (_Order >= AllObject.size())
		{
			AllObject.resize(_Order + 1);
		}

		std::list<ConsoleGameObject*>& Group = AllObject[_Order];
		ObjectType* NewObject = new ObjectType();
		Group.push_back(NewObject);

		return NewObject;
	}

	template<typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _Order)
	{
		return CreateConsoleObject<ObjectType>(static_cast<int>(_Order));
	}


	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();

	template<typename EnumType>
	static std::list<ConsoleGameObject*>& GetGroup(EnumType _Order)
	{
		return AllObject[static_cast<int>(_Order)];
	}

	static std::list<ConsoleGameObject*>& GetGroup(int _Order)
	{
		return AllObject[_Order];
	}

private:
	// constructer destructer
	GameObjectManager();
	~GameObjectManager();

	// delete Function
	GameObjectManager(const GameObjectManager& _Other) = delete;
	GameObjectManager(GameObjectManager&& _Other) noexcept = delete;
	GameObjectManager& operator = (const GameObjectManager& _Other) = delete;
	GameObjectManager& operator = (GameObjectManager&& _Other) noexcept = delete;

	static std::vector<std::list<ConsoleGameObject*>> AllObject;
};

