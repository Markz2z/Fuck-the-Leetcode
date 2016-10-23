#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	int gen(int up, int down, int left, int right, int num) {
        int min1 = up < down ? up : down;
        int min2 = left < right ? left : right;
        int min = min1 < min2 ? min1 : min2;
		return min > num ? min - num : 0;
	}

    int trapRainWater(vector<vector<int> >& heightMap) {
    	if (heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        int x = heightMap.size(), y = heightMap[0].size(), sum = 0, i, j;
        int max = x < y ? y : x;
        int left[max][max], right[max][max], up[max][max], down[max][max];
        int count[x][y];
        for (i = 1; i < x-1; ++i) {
        	left[i][0] = heightMap[i][0];
        	for (j = 1; j < y-1; ++j) {
        		left[i][j] = heightMap[i][j] > left[i][j-1] ? heightMap[i][j] : left[i][j-1];
        	}
        }
        for (i = 1; i < x-1; ++i) {
        	right[i][y-1] = heightMap[i][y-1];
        	for (j = y - 2; j > 0; --j) {
        		right[i][j] = heightMap[i][j] > right[i][j+1] ? heightMap[i][j] : right[i][j+1];
        	}
        }
        for (j = 1; j < y-1; ++j) {
        	up[0][j] = heightMap[0][j];
        	for (i = 1; i < x-1; ++i) {
        		up[i][j] = heightMap[i][j] > up[i-1][j] ? heightMap[i][j] : up[i-1][j];
        	}
        }
        for (j = 1; j < y - 1; ++j) {
        	down[x-1][j] = heightMap[x-1][j];
        	for (i = x - 2; i > 0; --i) {
        		down[i][j] = heightMap[i][j] > down[i+1][j] ? heightMap[i][j] : down[i+1][j];
        	}
        }
        for (j = 1; j < y - 1; ++j) {
        	for (i = 1; i < x - 1; ++i) {
        		count[i][j] = gen(up[i][j], down[i][j], left[i][j], right[i][j], heightMap[i][j]);
        		sum += count[i][j];
        	}
        }
        return sum;
    }
};

int main() {
	Solution s;
	vector<vector<int> > vec;
	int iarray1[]={1,4,3,1,3,2};
	vector<int> a(iarray1, iarray1 + 6);
	int iarray2[]={3,2,1,3,2,4};
	vector<int> b(iarray2, iarray2 + 6);
	int iarray3[]={1,4,3,1,3,2};
	vector<int> c(iarray3, iarray3 + 6);
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	cout << s.trapRainWater(vec) << endl;
	return 1;
}