#pragma once

#include "_include.h"

class Solution {
public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
                /*
                ǰ��
                sum(gas) >= sum(cost)
                �������ǰ��, ���Ȼ������ĵ�
                ��ǰ����Ϊo, ����һ��ĳɱ�Ϊ
                net[i] = cost[i] - gas[i]
                Ҫ����
                gas[i] - cost[i + 1] ����
                gas[start] - sum(net[i])>= cost[start]
                */

                int n = gas.size();

                int i = 0;
                while(i < n){

                        int end = check(gas, cost, i, n);

                        // fail
                        if (end == -1) return -1;

                        // success
                        else if (i == end) return i;

                        // drop invalid interval
                        else i = end;
                }

                return -1;
        }

        int check(vector<int>& gas, vector<int>& cost, int start, int n) {

                int net_cost = 0;

                // check loop
                for (int i = 0; i < n; ++i) {

                        int pos = (start + i) % n;
                        
                        net_cost += cost[pos] - gas[pos];

                        // need varification
                        if (net_cost > 0) return pos<start? -1 : pos + 1;
                }

                return start;
        }
};