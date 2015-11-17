#include <bits/stdc++.h>
//#define __test__
//#define __unlinkcout__
#define to_int(a) ((a) - '0')

using namespace std;

template <class T, class U> inline T max (T &a, U &b){  return a > b ? a : b;  }
template <class T, class U> inline T min (T &a, U &b){  return a < b ? a : b;  }
template <class T, class U> inline T swap (T &a, U &b){  T tmp = a; a = b; b = tmp;  }

//{ 4 Direction
//const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1}; 
//}
//{ 8 Direction
//const int dx[]={1,1,0,-1,-1,-1,0,1}; const int dy[]={0,1,1,1,0,-1,-1,-1};
//}

short ns[10], len;
string in;

char best_canditate(short j)
{
	short i;
	for (i = j - 1; i >=0 and ns[i] == 2; --i);
	return (i == -1)? '-' : i + '0';
}

int solve(int i, bool exito = true)
{
	if(i == -1 or i == len)
		return i + 1;
	if (exito and ns[to_int(in[i])] < 2)
	{
		ns[to_int(in[i])]++;		
		return solve(i + 1);
	}
	else
	{
		char b = best_canditate(to_int(in[i]));
		if(!exito)
			ns[to_int(in[i])]--;
		if (b == '-')	return solve(i - 1, false);
		else
		{
			ns[to_int(b)]++;
			in[i] = b;
			return i + 1;
		}
	}
}

int main()
{
    #ifdef __test__
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif 
    #ifdef __unlinkcout__
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    #endif
  	
    string last = "99887766554433221100";
    cin >> in;
    len = in.size();

    int pivote = solve(0);

    for (int i = pivote, j = 0; i < len; j++)
    {
    	if (ns[to_int(last[j])] < 2)
    	{
    		in[i++] = last[j];
    		ns[to_int(last[j])]++;
    	}
    }    
    cout << string(in.begin() + !(in[0] - '0'), in.end()) << endl;   
    return 0;
}