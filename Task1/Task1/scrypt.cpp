#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> NumberFiller() {
	vector<int> res;
	int temp;
	while (true) {
		temp = cin.get();
		if (temp == 10 || temp == -1) break;
		else
			res.push_back(temp-48);
	}
	return res;
}

vector<int> MakeSum(vector<int> a, vector<int> b) {
	vector<int> res;
	int temp;
	int rank;
	if (a.size() > b.size()) {
		temp = a.size() - b.size();
		rank = a.size();
		for (int i = 0; i < temp; i++) {
			b.insert(b.begin(), 0);
		}
	}
	else {
		temp = b.size() - a.size();
		rank = b.size();
		for (int i = 0; i < temp; i++) {
			a.insert(a.begin(), 0);
		}
	}
	temp = 0;
	for (int i = rank-1 ; i >= 0; i--){
		temp = a[i] + b[i] + temp;
		res.insert(res.begin(), temp % 10);
		temp = temp / 10;
	}
	
	return res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> frstNumber;
	vector<int> scndNumber;
	vector<int> result;

	frstNumber = NumberFiller();
	scndNumber = NumberFiller();
	
	result = MakeSum(frstNumber, scndNumber);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	return 0;
}