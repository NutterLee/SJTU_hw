#include<iostream>
using namespace std;

//QAQ:
//if you find anything wrong with this program,please contact qq1737078184
//thanks

//using num_of_ways to save the result
void climb_ladder(int length_of_ladder, int& num_of_ways);
//error class
class ladder_length_error{};

int main()
{
	while (true)
	{
		try
		{
			int length_of_ladder = 0;
			int num_of_ways = 0;	

			cout << "Enter the length of the ladder(Enter 0 to quit): ";
			cin >> length_of_ladder;

			if (length_of_ladder <0) throw ladder_length_error();
			if (length_of_ladder == 0) return 0;

			climb_ladder(length_of_ladder, num_of_ways);
			cout <<"Number of ways: "<< num_of_ways<<endl;
		}
		catch (ladder_length_error) { cerr << "the length of ladder must be greater than 0" << endl; }
	}	
	return 0;
}

void climb_ladder(int length_of_ladder,int& num_of_ways)
{
	//when the length of ladder becomes zero, it means we have got a right way, thus num_of_ways++
	if (length_of_ladder ==0)
	{
		num_of_ways++;
	}
	else if(length_of_ladder>0)
	{
		//using for statement to try different length of step
		for (int step = 1; step < 3; step++)
		{
			climb_ladder(length_of_ladder - step, num_of_ways);
		}
	}
}
