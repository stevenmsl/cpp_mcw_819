#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol819;
using namespace std;

string Solution::find(string para, vector<string> &banned)
{
  auto bm = unordered_set<string>(banned.begin(), banned.end());
  auto freq = unordered_map<string, int>();

  auto count = 0;
  string most;
  string word;
  for (auto i = 0; i < para.size(); i++)
  {
    const auto c = para[i];
    if (isalpha(c))
      word.push_back(tolower(c));
    else
    {
      /* the word has been looked at when you reach
         this non alphabetic char
         - ...a ball, the...
         - when you encounter ',' the word "ball"
           is processed to the map and word is cleared
           so when you encounter the next char which
           is ' ' the word is already empty

      */
      if (word.empty())
        continue;
      if (!bm.count(word))
      {
        freq[word]++;
        if (freq[word] >= count)
          count = freq[word], most = word;
      }
      word.clear();
    }
  }

  return most;
}