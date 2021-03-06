#include<iostream>

using namespace std;

//1、创建立方体
//2、设计属性  长，宽，高
//3、设计行为  获取立方体面积和体积
//4、分别利用全局函数和成员函数 判断两个立方体是否相等

class Cube {
public:
	//设置长
	void setL(int l) {
		m_l = l;
	}
	//获取长
	int getL() {
		return m_l;
	}
	//设置宽
	void setW(int w) {
		m_w = w;
	}
	//获取宽
	int getW() {
		return m_w;
	}
	//设置高
	void setH(int h) {
		m_h = h;
	}
	//获取高
	int getH() {
		return m_h;
	}
	//获取立方体面积
	int calculateS() {
		return 2 * (m_l * m_w + m_w * m_h + m_h * m_l);
	}
	//获取立方体体积
	int calculateV() {
		return m_l * m_w * m_h;
	}
	//利用成员函数判断 两个立方体是否相等
	bool isSameByClass(Cube& c) {
		if (getL() == c.getL() && getW() == c.getW() && getH() == c.getH()) {
			return true;
		}
		return false;
	}
private:
	int m_l = 0;	//长
	int m_w = 0;	//宽
	int m_h = 0;	//高
};

//利用全局函数判断 两个立方体是否相等
bool isSame(Cube& c1, Cube& c2) {	//使用 引用 索引原始数据，而不是复制数据进入函数
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}
int main() {
	//创建立方体对象
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;

	//创建第二个立方体
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(11);

	//利用全局函数判断
	bool ret = isSame(c1, c2);
	if (ret) {
		cout << "成员函数判断：c1和c2是相等的" << endl;
	}
	else {
		cout << "成员函数判断：c1和c2是不相等的" << endl;
	}

	//利用成员函数判断
	ret = c1.isSameByClass(c2);
	if (ret) {
		cout << "成员函数判断：c1和c2是相等的" << endl;
	}
	else {
		cout << "成员函数判断：c1和c2是不相等的" << endl;
	}

	system("pause");
	return 0;
}