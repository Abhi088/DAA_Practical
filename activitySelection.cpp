#include <iostream>
#include <algorithm>

using namespace std;

struct Activity {
	int s, f; // s for start and for finish
	
	Activity(int start, int finish) {
		this->s = start;
		this->f = finish;
	}
};

bool compareActivity(Activity a, Activity b) {
	return a.f < b.f;
}

vector<Activity> selectActivities(vector<Activity> arr, int n) {

	sort(arr.begin(), arr.end(), compareActivity);	
	
	vector<Activity> selectedActivity;
	
	int i = 0;
	selectedActivity.push_back(arr[i]);
	
	for (int j = 1; j < n; j++)	{
		if (arr[j].s >= arr[i].f) {
			selectedActivity.push_back(arr[j]);
			i = j;
		}
	}
	return selectedActivity;
}

int main()
{

	vector<Activity> arr = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
	
	vector<Activity> sActivities = selectActivities(arr, arr.size());
	
	cout << "Activities with following start and finish time are selected: \nStart Finish\n";
	
	for(int i = 0; i < sActivities.size(); i++) {
		cout << sActivities[i].s << "\t" << sActivities[i].f << "\n";
	}
	
	return 0;
}
