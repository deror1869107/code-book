#include <string>
string str2 = str.substr(begin, length);
size_t pos = str.find("pattern", pos = 0);
size_t pos = str.find('c', pos = 0);
size_t pos = str.find_first_of("aeiou", pos = 0);
// find_last_of, find_first_not_of, find_last_not_of
// not found: npos = -1

#include <set>

set<int> s;
s.insert(10);
s.erase(10);
if(s.find(10)!=s.end()) puts("found!");

#include <map>

map<int, int> m;
map<int, vector<int> > m2; // space!!
map<int, int>::iterator it;
m[key] = val;
for(/*auto*/ it = m.begin(); mit != m.end(); ++mit)
	cout << (*mit).first << ' ' << mit->second << endl;

#include <algroithm>

fill_n (v.begin(), n, val);

int pos = *lower_bound (v.begin(), v.end(), val);
// first element (iterator) >= val.
// upper_bound: > val

int pos = find(v.begin(), v.end(), val);
// linear search; returns v.end as element not found

bool found = binary_search(v.begin(), v.end(), val);
// binary search; container should be sorted

#include <tuple>

tuple<int,char> foo(10, 'x');
auto bar = make_tuple("test", 3.1, 14, 'y');

std::get<2>(bar) = 100;	// access element

int myint; char mychar;

tie (myint, mychar) = foo;	// unpack elements
tie(ignore, ignore, myint, mychar) = bar;	// unpack (with ignore)

mychar = std::get<3>(bar);

get<0>(foo) = std::get<2>(bar);
get<1>(foo) = mychar;

cout << "foo contains: ";
cout << std::get<0>(foo) << ' ';
cout << std::get<1>(foo) << endl;

#include <functional>	// multiplies
#include <numeric>      // partial_sum, adjacent_difference

int myop (int x, int y) {return x+y+1;}

int val[] = {1,2,3,4,5};
int result[5];

std::partial_sum (val, val+5, result);
std::cout << "using default partial_sum: ";
for (int i=0; i<5; i++) std::cout << result[i] << ' ';
std::cout << '\n';

std::partial_sum (val, val+5, result, std::multiplies<int>());
std::cout << "using functional operation multiplies: ";
for (int i=0; i<5; i++) std::cout << result[i] << ' ';
std::cout << '\n';

std::partial_sum (val, val+5, result, myop);
std::cout << "using custom function: ";
for (int i=0; i<5; i++) std::cout << result[i] << ' ';
std::cout << '\n';

int val[] = {1,2,3,5,9,11,12};

int result[7];
std::adjacent_difference (val, val+7, result);

#inlcude <limits>

const int INF = numeric_limits<int>::max();