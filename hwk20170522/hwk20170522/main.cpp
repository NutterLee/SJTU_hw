#include<fstream>
#include<string>
#include<iostream>
#include<vector>

using namespace std;
void find_way(int& current_x,int& current_y,vector<vector<int>>& maze);
int tmp_length = 0;
int shortest_length = 0;

int main()
{
	int size_x = 0;
	int size_y = 0;
	int current_x = 0;
	int current_y = 0;
	fstream file;
	file.open("mg1.txt");
	file >> size_y;
	file >> size_x;
	//cout << size_x << " " << size_y;
	vector<vector<int>>maze;
	for (int y = 0; y < size_y; y++)
	{
		vector<int> tmp_y;
		for (int x = 0; x < size_x; x++)
		{
			int tmp;
			file >> tmp;
			//cout << tmp<<" " ;
			tmp_y.push_back(tmp);
		}
		maze.push_back(tmp_y);
	//	cout << endl;
	}
	//cout << endl;
	find_way(current_x, current_y, maze);
	maze[0][0] = 2;	
	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			if (maze[y][x] == 3)maze[y][x] = 0;
			cout <<maze[y][x]<<" " ;
		}
		cout << endl;
	}		
	system("pause");
	return 0;
}

void find_way(int& current_x,int& current_y,vector<vector<int>>& maze)
{
	tmp_length++;
	int size_y = maze.size();
	int size_x = maze[0].size();
	if (maze[current_y][current_x] == 0)maze[current_y][current_x] = 2;
	if ((current_x + 1 < size_x) && (current_y + 1 < size_y))
	{
		int count = 0;
		if (maze[current_y + 1][current_x + 1] == 0)count++;
		if (maze[current_y][current_x + 1] == 0)count++;
		if (maze[current_y + 1][current_x] == 0)count++;
		if (count == 3)
			maze[current_y + 1][current_x + 1] = 3;
	}
	if (true)
	{
		int count = 0;
		if (current_y + 1 < size_y && (maze[current_y + 1][current_x] == 0))count++;
		if (current_x + 1 < size_x && (maze[current_y][current_x + 1] == 0))count++;
		if (current_y - 1 >= 0 && (maze[current_y - 1][current_x] == 0))count++;
		if (current_x - 1 >= 0 && (maze[current_y][current_x - 1] == 0))count++;	
		//if (count == 3)
			//maze[current_y ][current_x ] = 3;
	}
	if (current_y == maze.size() - 1 && current_x == maze[0].size() - 1)return;		
	else if (current_y + 1<size_y && (maze[current_y + 1][current_x] == 0))
	{
		maze[current_y + 1][current_x] = 2;
		current_y++;
		find_way(current_x, current_y, maze);
	}
	else if (current_x + 1<size_x && (maze[current_y][current_x + 1] == 0))
	{
		maze[current_y][current_x + 1] = 2;
		current_x++;
		find_way(current_x, current_y, maze);
	}
	else if(current_y-1>=0&& (maze[current_y -1][current_x] == 0))
	{
		maze[current_y -1][current_x] = 2;
		current_y = current_y - 1;
		find_way(current_x, current_y, maze);
	}
	else if (current_x-1>=0&&(maze[current_y][current_x - 1] == 0))
	{
		maze[current_y][current_x -1] = 2;
		current_x --;
		find_way(current_x, current_y, maze);
	}
	else 
	{		
		if (current_y-1>=0&&(maze[current_y - 1][current_x] == 2))
		{
			maze[current_y][current_x] = 3;
			current_y--;
			find_way(current_x, current_y, maze);
		}
		else if(current_y+1<size_y&& (maze[current_y +1][current_x] == 2))
		{
			maze[current_y][current_x] = 3;
			current_y++;
			find_way(current_x, current_y, maze);
		}
		else if (current_x+1<size_x&&(maze[current_y ][current_x+1] == 2))
		{
			maze[current_y][current_x] = 3;
			current_x++;
			find_way(current_x, current_y, maze);
		}
		else if (current_x-1>=0&& (maze[current_y][current_x - 1] == 2))
		{
			maze[current_y][current_x ] = 3;
			current_x--;
			find_way(current_x, current_y, maze);
		}
	}	

}
