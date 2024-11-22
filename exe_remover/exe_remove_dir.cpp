#include <bits/stdc++.h>
using namespace std;
void dfs_dir(string now, int lvl = 0) {
	std::filesystem::current_path(now.c_str());
	cout << (std::filesystem::current_path()) << endl;
	system("exe_remove");
	string infile = "tmpinput" + to_string(lvl) + ".txt";
	system(("dir > " + infile).c_str());
	string s;
	ifstream fin(infile);
	while (getline(fin, s)) {
		if (s.find("<DIR>") != string::npos && s.back() != '.') {
			string t;
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] == ' ') break;
				t += s[i];
			}
			reverse(t.begin(), t.end());
			dfs_dir(now + "\\" + t, lvl + 1);
			std::filesystem::current_path(now.c_str());
		}
	}
	fin.close();
	system(("del " + infile).c_str());
}
int main() {
	dfs_dir("G:\\nh_nayeem");
	system("echo done");
	return 0;
}
