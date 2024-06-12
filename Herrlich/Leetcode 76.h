#pragma once

#include "_include.h"

class Solution {
public:
        string minWindow(string s, string t) {
                vector<int> vec_map(128, 0);

                //
                cout << "origin string: " << s << endl;
                cout << "pattern string: " << t << endl;
                cout << "character vector has been built" << endl;
                cout << "--------------------------------" << endl;
                //

                for (auto c : t) vec_map[c]++;

                //
                cout << "|";
                for (int i = 0; i < 128; ++i) {
                        if (vec_map[i] != 0) {
                                cout << char(i) << " set to " << vec_map[i] << "|";
                        }
                }
                cout << endl;
                cout << "--------------------------------" << endl;
                //

                int counter = t.size();
                int begin = 0;
                int end = 0;
                int d = INT_MAX;
                int head = 0;

                while (end < s.size()) {

                        // char_map might be set < 0

                        if (vec_map[s[end++]]-- > 0) {

                                //
                                cout << "End: " << (char)s[end - 1] << " has been found at pos " << end - 1 << endl;
                                cout << "--------------------------------" << endl;
                                //


                                counter--; 

                        }

                        // use counter to control begin & head iterator

                        while (counter == 0) { //valid

                                //
                                cout << "all characters are used, valid" << endl;
                                //

                                // record distance and adjust begin
                                if (end - begin < d)  d = end - (head = begin);

                                // change the char_map, only character affecting counter matters, but all characters are added
                                if (vec_map[s[begin++]]++ == 0) {

                                        counter++;  //make it invalid

                                        //
                                        cout << "Begin: "<<(char)s[begin - 1] << " met at pos " << begin - 1 << ", count added" << endl;
                                        cout << "--------------------------------" << endl;
                                        //

                                }
                        }
                }
                return d == INT_MAX ? "" : s.substr(head, d);
        }
};