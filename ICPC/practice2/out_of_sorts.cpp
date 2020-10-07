/*
    Problem F: Out of Sorts
        - https://open.kattis.com/contests/dgsbdo/problems/outofsorts

    Brute Force solution - test binary search on each element in O(nlogn) time
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int INF = 1e9;

vector<long> generateArray(long n, long a, long m, long c, long x_0) {
	vector<long> ret;
	long x = x_0;
	for (long i = 0; i < n; i++) {
		x = (a * x + c) % m;
		ret.push_back(x);
	}
	return ret;
}

bool binarySearch(vector<long> &list, long val) {
	long low = 0;
	long high = list.size()-1;
	while (high >= low) {
		long mid = (low+high)/2;
		if (list[mid] == val) {
			return true;
		}
		else if (list[mid] > val) {
			high = mid-1;
		}
		if (list[mid] < val) {
			low = mid+1;
		}
	}
	return false;
}

void test_case() {
	long n = 0, m = 0, a = 0, c = 0, x_0 = 0;
	scanf("%ld %ld %ld %ld %ld", &n, &m, &a, &c, &x_0);
	vector<long> out = generateArray(n, a, m, c, x_0);

	long cnt = 0;
	for (long ele : out) {
		if (binarySearch(out, ele)) {
			cnt++;
		}
	}

	printf("%ld\n", cnt);
}


int main() {
	test_case();
	return 0;
}