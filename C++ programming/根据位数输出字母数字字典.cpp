#include <iostream>
#include <vector>
using namespace std;
char alphaBet[40] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int T, cnt = 0;
vector<int> wait;
void generate(int len)
{
	if (len == T)
	{
		for (int i = 0; i < len; i++)
			cout << alphaBet[wait[i]];
		cout << endl;
        cnt++;
		return;
	}
	wait.push_back(0);
	for (int i = 0; i < 36; i++)
	{
		//cout << alphaBet[i];
		wait.pop_back();
		wait.push_back(i);
		generate(len + 1);
	}
	if (!wait.empty())
		wait.pop_back();
}
int main()
{
	freopen("out.txt", "w", stdout);
    cin >> T;
	generate(0);
    cout << "Sum: " << cnt << endl;
    cin.get();
	return 0;
}
