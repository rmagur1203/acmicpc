#include <iostream>

using namespace std;

int index[100001];
int inorder[100001];
int postorder[100001];
void preorder(int ins, int ine, int posts, int poste){
    if (ins > ine || posts > poste) return;

    int root = postorder[poste];
    cout << root << " ";
    int rooti = index[root];
    int lend = rooti - 1;
    int lsize = rooti - ins;
    int rstart = rooti + 1;

    preorder(ins, lend, posts, posts + lsize - 1);
    preorder(rstart, ine, posts + lsize, poste - 1);
}
int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> inorder[i];
        index[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> postorder[i];
    preorder(1, n, 1, n);
}