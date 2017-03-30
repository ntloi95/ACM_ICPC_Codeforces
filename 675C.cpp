#include<bits/stdc++.h>
using namespace std;

int magicBook(string s) {
    string cpy = s;
    int n = s.length();
    sort(s.begin(), s.end());
    int cnt = 1;
    map<char, int> ma;
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] != s[i+1])
        {
            ma[s[i]] = cnt-1;
            cnt++;
        } 
    }
    if(s[n-1] != s[n-2])
        ma[s[n-1]] = cnt-1;
    
    long long a = pow(cnt, n);
    long long id = 0;
    long long exp = 1;
    for (int i = n-1; i>=0; i++)
    {
        id += ma[s[i]] * exp;
        exp*= cnt;
    }
    return a-id;
}


int main()
{
	string s;
	cin >> s;

	cout << magicBook(s);

	return 0;
}