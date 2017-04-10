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
	const string ConcavePol = "Concave Polygon";//�������
	const string ConvexPol = "Convex Polygons";//͹�����
	
	bool isCave = false;//Ĭ����͹�����
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
		int px1 = points[pred].x - points[rightNow].x;//��һ������xֵ
		int py1= points[pred].y- points[rightNow].y;//��һ������yֵ
		int px2 = points[suc].x - points[rightNow].x;//�ڶ�������xֵ
		int py2 = points[suc].y - points[rightNow].y;//�ڶ�������yֵ
		int result = px1*py2 - px2 *py1;
		if (result > 0) isCave = true;
	}
	for (int i = 0; i < 5; i++)
	{
		int rightNow = (i + 5) % 5;
		int pred = (i - 1 + 5) % 5;
		int suc = (i + 1 + 5) % 5;
		int px1 = points2[pred].x - points2[rightNow].x;//��һ������xֵ
		int py1 = points2[pred].y - points2[rightNow].y;//��һ������yֵ
		int px2 = points2[suc].x - points2[rightNow].x;//�ڶ�������xֵ
		int py2 = points2[suc].y - points2[rightNow].y;//�ڶ�������yֵ
		int result = px1*py2 - px2 *py1;
		if (result > 0) isCave2 = true;
	}
	if (isCave) { 
		cout << "��һ��ͼ�ǰ������"<<endl;
	}
	else cout << "��һ��ͼ��͹�����"<<endl;
	if (isCave2) {
		cout << "�ڶ���ͼ�ǰ������" << endl;
	}
	else cout << "�ڶ���ͼ��͹�����" << endl;

	win1.wait_for_button();
	system("pause");
	return 0;
}