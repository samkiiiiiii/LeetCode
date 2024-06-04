#pragma once

#include "_include.h"

class Solution {
public:
        string reverseWords(string s) {

                // special case: n=0 (impossible)
                int n = s.length();  
                
                // reverse: use stack to store the words
                stack<string> my_stack;
                int iter_front = 0;
                int iter_end = 0;

                // analysis: string can be separated into multiple section
                // { leading space | words | interval space | words | trailing space }
                // can classify these section into {leading/interval space + words} {trailing space}

                while (true) {

                        // {leading/interval space + word}
                        while (s[iter_end] == ' ') {
                                iter_front++;
                                iter_end++;

                                // ending while-loop: trailing space
                                if (iter_end == n) return stackToString(my_stack);
                        }

                        while (s[iter_end] != ' ') {
                                iter_end++;

                                //ending while-loop: iteration end
                                if (iter_end == n) {
                                        string tmp = s.substr(iter_front, iter_end - iter_front);
                                        my_stack.push(tmp);
                                        return stackToString(my_stack);
                                };
                        }
                        
                        if (iter_front != iter_end) {
                                string tmp = s.substr(iter_front, iter_end - iter_front);
                                my_stack.push(tmp);
                        }
                        iter_front = iter_end;
                }
        }

        string stackToString(stack<string>& my_stack) {
                string res;
                while (!my_stack.empty()) {
                        res += my_stack.top() + ' ';
                        my_stack.pop();
                }
                res.pop_back();
                return res;
        }
};