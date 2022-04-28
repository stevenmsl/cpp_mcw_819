#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol819;

/*
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.
*/

tuple<string, vector<string>, string>
testFixture1()
{
  auto para = "Bob hit a ball, the hit BALL flew far after it was hit.";
  auto banned = vector<string>{"hit"};
  return make_tuple(para, banned, "ball");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<2>(f) << endl;
  Solution sol;
  cout << sol.find(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  return 0;
}