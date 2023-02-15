#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> order(26, 0);
        for (int i = 0; i < s.size(); i++)
            order[s[i] - 'a'] = i;

        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (order[s[i] - 'a'] > end)
                end = order[s[i] - 'a'];

            if (end == i)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    string test{
        "ntswuqqbidunnixxpoxxuuupotaatwdainsotwvpxpsdvdbwvbtdiptwtxnnbtqbdvnbow"
        "qitudutpsxsbbsvtipibqpvpnivottsxvoqqaqdxiviidivndvdtbvadnxboiqivpusuxa"
        "aqnqaobutdbpiosuitdnopoboivopaapadvqwwnnwvxndpxbapixaspwxxxvppoptqxits"
        "vaaawxwaxtbxuixsoxoqdtopqqivaitnpvutzchkygjjgjkcfzjzrkmyerhgkglcyffezm"
        "ehjcllmlrjghhfkfylkgyhyjfmljkzglkklykrjgrmzjyeyzrrkymccefggczrjflykclf"
        "hrjjckjlmglrmgfzlkkhffkjrkyfhegyykrzgjzcgjhkzzmzyejycfrkkekmhzjgggrmch"
        "keclljlyhjkchmhjlehhejjyccyegzrcrerfzczfelzrlfylzleefgefgmzzlggmejjjyg"
        "ehmrczmkrc"};
    Solution solution;
    solution.partitionLabels(test);
}