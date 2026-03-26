#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  string value;
  map<string, Node *> children;
};

void print(string prefix, Node &node) {
  for (auto value : node.children) {
    cout << prefix << value.first << endl;
    string new_prefix = prefix;
    print(new_prefix.append("--"), *value.second);
  }
}

int N;
int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  cin >> N;

  Node root;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    Node *prev = &root;
    for (int j = 0; j < k; j++) {
      string s;
      cin >> s;
      if (prev->children.find(s) != prev->children.end()) {
        prev = prev->children[s];
      } else {
        prev = prev->children[s] = new Node();
      }
    }
  }

  print("", root);
}