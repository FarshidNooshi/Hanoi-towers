// In The Name Of GOD
#include<bits/stdc++.h>

using namespace std;

struct task {
	bool typ;
	int v, fr, to;
};

int n;
stack<task> st;
vector<task> vec;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	st.push({ 0, n, 1, 3 });
	while (!st.empty()) {
		auto top = st.top();
		st.pop();
		if (top.v == 0)
			continue;
		if (top.typ == 1)
			vec.push_back(top);
		else {
			if (top.fr == 1) {
				if (top.to == 3) {
					st.push({0, top.v - 1, 1, 2 });
					st.push({ 1, top.v, 1, 3 });
					st.push({ 0, top.v - 1, 2, 3 });
				}
				else if (top.to == 2) {
					st.push({ 0, top.v - 1, 1, 3 });
					st.push({ 1, top.v, 1, 2 });
					st.push({ 0, top.v - 1, 3, 2 });
				}
			}
			else if (top.fr == 2) {
				if (top.to == 3) {
					st.push({ 0, top.v - 1, 2, 1 });
					st.push({ 1, top.v, 2, 3 });
					st.push({ 0, top.v - 1, 1, 3 });
				}
				else if (top.to == 1) {
					st.push({ 0, top.v - 1, 2, 3 });
					st.push({ 1, top.v, 2, 1 });
					st.push({ 0, top.v - 1, 3, 1 });
				}
			}
			else {
				if (top.to == 1) {// az 3 be 1
					st.push({ 0, top.v - 1, 3, 2 });
					st.push({ 1, top.v, 3, 1 });
					st.push({ 0, top.v - 1, 2, 1 });
				}
				else if (top.to == 2) { // az 3 be 2
					st.push({ 0, top.v - 1, 3, 1 });
					st.push({ 1, top.v, 3, 2 });
					st.push({ 0, top.v - 1, 1, 2 });
				}
			}
		}
	}
	while (!vec.empty()) {
		auto top = vec.back();
		vec.pop_back();
		cout << top.v << " from " << top.fr << " to " << top.to << '\n';
	}
	return false;
}