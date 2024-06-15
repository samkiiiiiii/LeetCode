#pragma once

#include "_include.h"

// 这题周赛第二道出现过, 并且是比较标准的滑动指针题目
// 第一遍做的时候列了6种分类情况, 最后合并为3种
// 之后熟读题解

class Solution {
public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
                sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
                        return a[0] < b[0];
                });
                vector<vector<int>> res;
                vector<int> tmp(2);
                tmp[0] = intervals[0][0];
                int pointer = intervals[0][1];

                int m = intervals.size();

                for (int i = 0; i < m; ++i) {
                        
                        //中断点
                        if (pointer < intervals[i][0]) {
                                tmp[1] = pointer;
                                res.push_back(tmp);
                                tmp[0] = intervals[i][0];
                                pointer = intervals[i][1] > pointer ? intervals[i][1] : pointer;
                        }

                        else {
                                pointer = intervals[i][1] > pointer ? intervals[i][1] : pointer;
                        }

                        if (i == m - 1) {
                                tmp[1] = pointer;
                                res.push_back(tmp);
                        }
                }

                return res;
        }

};