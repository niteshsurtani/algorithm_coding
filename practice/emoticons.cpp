#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;


class EmoticonsDiv2 {
public:
	int printSmiles(int smiles, vector<int> &v)
	{
		if (v[smiles] != -1)
			return v[smiles];
		
		int res = INT_MAX;
		for (int i = 1; i < smiles; i++)
			if (smiles%i == 0) {
				int curr = smiles/i + printSmiles(i,v);
				res = min(res,curr);
			}


		return v[smiles] = res;
	}
	
	int printSmiles(int smiles) {
		vector<int> v(smiles+1,-1);
		v[1] = 0;
		return printSmiles(smiles,v);
	}
};
