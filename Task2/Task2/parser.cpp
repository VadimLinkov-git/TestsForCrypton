#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;


struct user {
	string Name;
	int RequestsPerHour;
	int Hours;
	int TotalRequests;
	string Inf;
};

vector<user> SwapNeighboring(int i, int j, vector<user> vec) {
	user temp;
	temp = vec[i];
	vec.erase(vec.begin() + i);
	vec.insert(vec.begin()+j , temp);
	return vec;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	setlocale(LC_ALL, "rus");

	vector<user> users;
	int i;
	int counter;
	user temp;
	
	while (cin >> temp.Name) {
		cin >> temp.RequestsPerHour;
		cin >> temp.Hours;
		cin >> temp.Inf;
		temp.TotalRequests = temp.Hours * temp.RequestsPerHour;
		users.push_back(temp);
	}

	for (int i = 0; i < users.size(); i++){ //sum the information
		if (users.size() == 1) break;
		for (int j = i+1; j < users.size(); j++){
			if (users[i].Name == users[j].Name) {
				users[i].RequestsPerHour = users[i].RequestsPerHour + users[j].RequestsPerHour;
				users[i].Hours = users[i].Hours + users[j].Hours;
				users[i].TotalRequests = users[i].TotalRequests + (users[j].Hours * users[j].RequestsPerHour);
				users.erase(users.begin()+ j);
				j--;
			}
		}
	}

	i = 0;
	counter = 0;
	while (true){    //bubble sort
		if ((i + 1) == users.size()) {
			i = 0;
			if (counter == 0) { break; }
			else {
				counter = 0;
			}
		}
		if ((int)users[i].Name[0] > (int)users[i + 1].Name[0]) {
			users = SwapNeighboring(i, i + 1, users);
			counter++;
		}
		i++;
	}

	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].Name << " " << users[i].RequestsPerHour << " " << users[i].Hours << " " << users[i].TotalRequests << " " << users[i].Inf << endl;
	}
	

	return 0;
}