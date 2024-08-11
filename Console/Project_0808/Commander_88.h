#pragma once

class Commander_88
{
public:
	~Commander_88();

	void Start();
	void Update();
	void End();
protected:

	void ShoptoItem(class ItemManager* _Item);

	void ShopManager(class ItemManager* _Item, class Player_88* _Player);

	void PlayerManager(class Player_88* _Player);

private:
	class ItemManager* ItemM;
	class Screen_88* MainScreen;
	class Shop_88* Shop;
	class Player_88* Player;

	bool Done = true;
};

