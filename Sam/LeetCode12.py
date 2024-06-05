class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        thousand_place = num // 1000
        hundred_place = (num % 1000) // 100
        tens_place = (num % 100) // 10
        unit_place = num % 10

        output =""
        # Thousands place
        if thousand_place >= 1:
            output += "M" * thousand_place

        # Hundreds place
        if hundred_place == 9:
            output += "CM"
        elif hundred_place >= 5:
            output += "D" + "C" * (hundred_place - 5)
        elif hundred_place == 4:
            output += "CD"
        else:
            output += "C" * hundred_place

        # Tens place
        if tens_place == 9:
            output += "XC"
        elif tens_place >= 5:
            output += "L" + "X" * (tens_place - 5)
        elif tens_place == 4:
            output += "XL"
        else:
            output += "X" * tens_place

        # Units place
        if unit_place == 9:
            output += "IX"
        elif unit_place >= 5:
            output += "V" + "I" * (unit_place - 5)
        elif unit_place == 4:
            output += "IV"
        else:
            output += "I" * unit_place

        return output
