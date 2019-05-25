#pragma once
#include <iostream>
#include <string>
using namespace std;

class WeaponBehavior{
public:
	virtual void useWeapon() = 0;
};
class AK47:public WeaponBehavior{
public:
	void useWeapon() override{
		cout << "use AK47" << endl;
	}
};
class DesertEagle :public WeaponBehavior{
public:
	void useWeapon() override{
		cout << "use DesertEagle" << endl;
	}
};

class CharacterContext{
public:
	CharacterContext() :weapon(nullptr){}
	virtual void fight() = 0;
	void setWeapon(WeaponBehavior *w){
		weapon = w;
	}
protected:
	WeaponBehavior *weapon;
};
class zhangbo :public CharacterContext{
public:
	void fight()override{
		if (nullptr == weapon){
			cout << "do not have a weapon" << endl;
		}
		else{
			cout << "zhangbo";
			weapon->useWeapon();
		}
	}
};
class zhangxiaopeng :public CharacterContext{
public:
	void fight()override{
		if (nullptr == weapon){
			cout << "do not have a weapon" << endl;
		}
		else{
			weapon->useWeapon();
		}
	}
};