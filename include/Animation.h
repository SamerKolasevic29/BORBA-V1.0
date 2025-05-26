#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::chrono::seconds;

inline void loading(const string& text = "", int rotation = 3, int delay = 300 ){
	const string s = "-/|\\-/|\\";
 for(int x = 1; x <= rotation; x++){
		for(int i=0;i<s.length();i++){
			cout << text << " " << s[i] << flush;
		sleep_for(milliseconds(delay));
			 cout << "\r";
		}
		}
		sleep_for(seconds(1));
	}

inline void thinking(const string& text = "", int rotation = 3, int delay = 300 ){
	const string sequence[] = {"", ".", ". .", ". . ."};
	for(int x = 1; x <= rotation; x++){
		for(const string& s : sequence) {
			cout << "\r" << text << " " << s << "     " << flush; 
			sleep_for(milliseconds(delay));
		}
		
	}
}

inline void writeLine(const string s = "", int delay = 100){
	for(char c : s){
		cout << c;
    	sleep_for(milliseconds(delay));
	}
}

inline void bar(int seg = 4, int delay = 300){
 const	string segms(seg, char(178));
    cout<< "[ ";
    for(const char c : segms){
    	cout << c;
    	sleep_for(milliseconds(delay));
    	
	}
	cout << " ]";
	sleep_for(seconds(2));
}

#endif
