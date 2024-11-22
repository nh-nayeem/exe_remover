#include <bits/stdc++.h>
using namespace std;
int main() {
	system("dir > input_exe.txt");
	string s;
	ifstream fin("input_exe.txt");
	while (getline(fin, s)) {
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s.substr(i, 4) == ".exe") {
				string t;
				for (int j = i + 3; j >= 0; j--) {
					if (s[j] == ' ') break;
					t += s[j];
				}
				reverse(t.begin(), t.end());
				if (t != "exe_remove.exe" && t != "exe_remove_dir.exe") {
					t = "del " + t;
					system(("echo deleting " + t).c_str());
					system(t.c_str());
					system("echo done");
				} else {
					system(("echo skiped " + t).c_str());
				}
			}
		}
	}
	fin.close();
	system("del input_exe.txt");
	system("echo end");
	return 0;
}