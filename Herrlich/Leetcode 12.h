class Solution {
public:
        unordered_map<int, string> RomanTable = {
            {0, ""}, {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"},
            {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
            {10, "X"}, {20, "XX"},{30, "XXX"},{40, "XL"},
            {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
            {100, "C"}, {200, "CC"}, {300,"CCC"}, {400, "CD"}, {500, "D"},
            {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {1000, "M"},
            {2000, "MM"}, {3000, "MMM"}
        };

        string intToRoman(int num) {
                string res = "";
                int bit = 0;
                while (num) {
                        res = RomanTable[num%10 * quickPow(10, bit)] + res;
                        num /= 10;
                        bit++;
                }
                return res;
        }
	
	int quickPow(int num, int pow){
		int res = 1;
		while(pow > 0){
			if (pow & 1) res = res * num;
			num = num * num;
			pow >>= 1;
		}
		return res;		
	}
};
