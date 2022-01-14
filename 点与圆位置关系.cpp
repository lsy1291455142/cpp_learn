#include <iostream>
using namespace std;

class Point {
public:
	void setX(double x) {
		m_x = x;
	}
	void setY(double y) {
		m_y = y;
	}
	double getX() {
		return m_x;
	}
	double getY() {
		return m_y;
	}
private:
	double m_x;
	double m_y;
};

class Circle {
public:
	void setR(double r) {
		m_r = r;
	}
	double getR() {
		return m_r;
	}
	void setCenter(Point P) {
		m_p = P;
	}
	Point getCenter() {
		return m_p;
	}


private:
	double m_r;
	Point m_p;

};

void isIncircle(Circle c, Point p) {
	double dist = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());
	if (dist < c.getR()*c.getR()) {
		cout << "点在圆内" << endl;
	}
	else if (dist > c.getR()*c.getR()) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆上" << endl;
	}
}

int main() {
	Circle c1;
	double r;
	cout << "输入圆的半径" << endl;
	cin >> r;
	c1.setR(r);
	Point center;
	double x;
	cout << "输入圆心坐标x" << endl;
	cin >> x;
	center.setX(x);
	double y;
	cout << "输入圆心坐标y" << endl;
	cin >> y;
	center.setY(y);
	c1.setCenter(center);
	Point p1;
	double px;
	cout << "输入点坐标x" << endl;
	cin >> px;
	double py;
	cout << "输入点坐标y" << endl;
	cin >> py;
	p1.setX(px);
	p1.setY(py);
	cout << "圆："<<"圆心(" <<x<<","<<y<<")"<<"半径："<<r<< endl;
	cout << "点(" <<px<<", "<<py<<")"<< endl;
	isIncircle(c1, p1);
	system("pause");
}