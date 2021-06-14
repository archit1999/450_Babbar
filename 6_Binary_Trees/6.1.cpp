#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

vector<Node*> bfs(Node* root){
    queue<Node*> q;
    vector<Node*> ans;

    q.push(root);

    while(q.empty() == false){
        Node* curr = q.front();
        q.pop();

        if (curr->left != NULL)  q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);

        ans.push_back(curr);
    }
    return ans;
}

int main(){

}