#include<bits/stdc++.h>

class Solution {
public:
    vector<int> findAnagrams(string inputString, string anagramString) {
        vector<int> output;
        map<char, int> anagramMap;
        map<char, int> iteratorMap;
        map<char, int>::iterator it;
        int zero_count = 0;
        int anagramCount = 0;
        for (int i = 0; i < anagramString.length(); i++)
        {
            it = anagramMap.find(anagramString[i]);
            if (it != anagramMap.end())
            {
                it->second++;
            }
            else
            {
                anagramMap.insert(pair<char, int>(anagramString[i], 1));
            }
        }
        int left_index = 0;
        bool isMapAltered = false;
        iteratorMap.insert(anagramMap.begin(), anagramMap.end());
        for (int i = 0; i < inputString.length(); i++)
        {
            if (iteratorMap.find(inputString[i]) != iteratorMap.end())
            {
                isMapAltered = true;
                int charCount = iteratorMap[inputString[i]];
                if (charCount == 0)
                {
                    while(inputString[left_index] != inputString[i]) {
                        if(!iteratorMap[inputString[left_index]]) {
                            zero_count--;
                        }
                        iteratorMap[inputString[left_index]]++;
                        left_index++;
                    }
                    zero_count--;
                    left_index++;
                    charCount++;
                }
                charCount--;
                if (charCount == 0)
                {
                    zero_count++;
                }
                iteratorMap[inputString[i]] = charCount;
            }
            else
            {
                left_index = i + 1;
                if (isMapAltered)
                {
                    iteratorMap.clear();
                    iteratorMap.insert(anagramMap.begin(), anagramMap.end());
                    isMapAltered = false;
                    zero_count = 0;
                }
            }
            if (zero_count == anagramMap.size() && (i - left_index) == anagramString.length() - 1)
            {
                output.push_back(left_index);
                anagramCount++;
            }
        }
        anagramMap.clear();
        iteratorMap.clear();
            return output;
        }
};