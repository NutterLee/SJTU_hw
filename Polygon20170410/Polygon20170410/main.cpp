#include"Graph.h"
#include"GUI.h"
#include"Point.h"
#include"Window.h"
#include"Simple_window.h"
#include<vector>
#include<iostream>

using namespace std;
using namespace Graph_lib;
int main()
{
	const string ConcavePol = "Concave Polygon";//凹多边形
	const string ConvexPol = "Convex Polygons";//凸多边形
	
	bool isCave = false;//默认是凸多边形
	bool isCave2 = false;
	Point pStart(100, 100);
	Point m1Attach(100, 100);
	Point m2Attach(500, 100);
	Simple_window win1(pStart,600, 400, "Polygon");
	vector<Point> points;
	vector<Point> points2;
	Point p1(50, 10);
	Point p2(150, 60);
	Point p3(90, 80);
	Point p4(40, 80);
	Point p5(30, 60);
	Polygon  polVex;
	Polygon polVex2;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	Point p6(300, 10);
	Point p7(250, 70);
	Point p8(270, 90);
	Point p9(220, 90);
	Point p10(180, 60);
	points2.push_back(p6);
	points2.push_back(p7);
	points2.push_back(p8);
	points2.push_back(p9);
	points2.push_back(p10);

	for (auto s : points)
	{
		polVex.add(s);
	}
	for (auto s : points2)
	{
		polVex2.add(s);
	}
	win1.attach(polVex);
	win1.attach(polVex2);

	for (int i = 0; i < 5; i++)
	{
		int rightNow = (i+5) % 5;
		int pred = (i - 1+5) % 5;
		int suc = (i + 1+5) % 5;
		int px1 = points[pred].x - points[rightNow].x;//第一个向量x值
		int py1= points[pred].y- points[rightNow].y;//第一个向量y值
		int px2 = points[suc].x - points[rightNow].x;//第二个向量x值
		int py2 = points[suc].y - points[rightNow].y;//第二个向量y值
		int result = px1*py2 - px2 *py1;
		if (result > 0) isCave = true;
	}
	for (int i = 0; i < 5; i++)
	{
		int rightNow = (i + 5) % 5;
		int pred = (i - 1 + 5) % 5;
		int suc = (i + 1 + 5) % 5;
		int px1 = points2[pred].x - points2[rightNow].x;//第一个向量x值
		int py1 = points2[pred].y - points2[rightNow].y;//第一个向量y值
		int px2 = points2[suc].x - points2[rightNow].x;//第二个向量x值
		int py2 = points2[suc].y - points2[rightNow].y;//第二个向量y值
		int result = px1*py2 - px2 *py1;
		if (result > 0) isCave2 = true;
	}
	if (isCave) { 
		cout << "第一个图是凹多边形"<<endl;
	}
	else cout << "第一个图形凸多边形"<<endl;
	if (isCave2) {
		cout << "第二个图是凹多边形" << endl;
	}
	else cout << "第二个图形凸多边形" << endl;

	win1.wait_for_button();
	system("pause");
	return 0;
}