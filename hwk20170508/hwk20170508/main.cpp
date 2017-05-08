#include<set>
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//获取一个word最后num个字符，如果num>字符长度，则返回""
string get_last_of(string word, int num);
//p1比p2大返回true
bool compare_pair(const pair<string, int>& p1, const pair<string, int>& p2);
int main()
{
	ifstream file("dictionary.txt");
	vector<string>dictionary;
	map<string, int>collection;
	set<pair<string, int>>collections;
	vector<pair<string, int>> sort_collection;;
	//文件输入
	string word;
	while (getline(file, word))
	{
		dictionary.push_back(word);
	}

	int num_of_suf = 0;
	cout << "enter the number of letters of suffix: " << endl;
	cin >> num_of_suf;
	for (auto word : dictionary)
	{
		if(get_last_of(word, num_of_suf)!="")
		collection[get_last_of(word, num_of_suf)] += 1;
	
	}
	//cout << collection.size() << endl;
		for(map<string, int>::iterator p = collection.begin();p!=collection.end();p++)
		{
			string key = p->first;
			int num = p->second;
			pair<string, int>tmp_pair = std::make_pair(key, num);
			sort_collection.push_back(tmp_pair);
		}
		//cout << sort_collection.size();
		std::sort(sort_collection.begin(), sort_collection.end(), compare_pair);
		cout << "top 10 suffixes and their numbers:" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << sort_collection[i].first<<" "<<sort_collection[i].second<<endl;
		}
		cout << "enter the " << num_of_suf << "-letter suffix: " << endl;
		string suffix_input;
		cin >> suffix_input;
		cout << "suffix:" << suffix_input << " numbers: " << collection[suffix_input] << endl;
		cout << "words of " << num_of_suf << "-letter(in descending order):" << endl;
		for (int i = dictionary.size(); i > -1; i--)
		{
			if (get_last_of(dictionary[i], num_of_suf) == suffix_input)
				cout << dictionary[i] << endl;
		}
	
	

	system("pause");
	return 0;
}

string get_last_of(string word, int num)
{
	if (word.size() < num) return "";
	if (word.size() == num) return word;
	string tmp;
	tmp = word.substr(word.size() - num);
	return tmp;	
}

bool compare_pair(const pair<string, int>& p1, const pair<string, int>& p2)
{
	if (p1.second > p2.second) return true;
	else return false;
}
