#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class Hero                        // 英雄基类
{
public:
	int viability;      // 生存能力。
	int attack;         // 攻击伤害。
	virtual void skill1() { cout << "英雄释放了一技能。\n"; }
	virtual void skill2() { cout << "英雄释放了二技能。\n"; }
	virtual void uskill() { cout << "英雄释放了大绝招。\n"; }
};

class XS :public Hero       // 西施派生类
{
public:
	void skill1() { cout << "西施释放了一技能。\n"; }
	void skill2() { cout << "西施释放了二技能。\n"; }
	void uskill() { cout << "西施释放了大招。\n"; }
	void show() { cout << "我是天下第一美女。\n"; }
};

class HX :public Hero       // 韩信派生类
{
public:
	void skill1() { cout << "韩信释放了一技能。\n"; }
	void skill2() { cout << "韩信释放了二技能。\n"; }
	void uskill() { cout << "韩信释放了大招。\n"; }
};

class LB :public Hero       // 李白派生类
{
public:
	void skill1() { cout << "李白释放了一技能。\n"; }
	void skill2() { cout << "李白释放了二技能。\n"; }
	void uskill() { cout << "李白释放了大招。\n"; }
};

int main()
{
	// 以下代码演示把基类引用转换为派生类引用时发生异常的情况。
	HX hx;
	Hero& rh = hx;
	try{
		XS & rxs= dynamic_cast<XS &>(rh);
	}
	catch (bad_cast) {
		cout << "出现了bad_cast异常。\n";
	}
}