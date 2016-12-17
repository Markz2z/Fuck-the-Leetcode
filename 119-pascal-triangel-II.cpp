class Solution {
public:
	int a[100][100];
	int calculate(int layer, int idx) {
		if(idx>layer || idx < 1)
			return 0;
		if(idx==1)
			return 1;
		if(a[layer][idx]!=0) {
			return a[layer][idx];
		}
		else {
			a[layer][idx] = calculate(layer-1, idx) + calculate(layer-1, idx-1);
			return calculate(layer-1, idx) + calculate(layer-1, idx-1);
		}
	}

    vector<int> getRow(int rowIndex) {
    	vector<int> result;
		for(int i=1;i<=rowIndex+1;++i) {
			result.push_back(calculate(rowIndex+1, i));
		}
		return result;
    }
};
