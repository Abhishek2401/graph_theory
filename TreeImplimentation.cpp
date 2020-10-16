#include<bits/stdc++.h>
using namespace std;
#include<vector>
using namespace std;
template<typename T>
class TreeNode{ 
  public:
   T data;
   vector<TreeNode*>children;
   TreeNode(int data){
    this -> data = data;
   }

};
//take input by levelwise && using queue//
TreeNode<int>* takeinputlevelwise(){ 

    int rootdata ;
   cout << "Enter the rootdata " ;
   cin >> rootdata;
   TreeNode<int>* root = new TreeNode<int>(rootdata);
   queue<TreeNode<int>*> pending;
   pending.push(root);
   while(pending.size() != 0){
     TreeNode<int>* front = pending.front();
     pending.pop();
     cout << "Enter the number of children" << front->data << " : ";
     int numchild;
     cin >> numchild;
     for(int i =0;i<numchild;i++){
      int childData;
      cout << "Enter the data of " << i << "th child " ;
      cin >> childData ;
      TreeNode<int>* child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pending.push(child);
     }
   }
 return root;
}


//take input by recursion //
TreeNode<int>* takeinput(){ 
   int rootdata ;
   cout << "Enter the rootdata " ;
   cin >> rootdata;
   TreeNode<int>* root = new TreeNode<int>(rootdata);
   int n;
   cout << "Enter number of child of "<< rootdata << " : ";
   cin >> n;
   for(int i=0;i<n;i++){
     TreeNode<int>* child = takeinput();
     root->children.push_back(child);
   }
  return root;

}
//print by recursion //
void printtree(TreeNode<int>* root){
   if(root == NULL){
    return ;
   }
   cout << root->data << " : " ;
   for(int i=0;i<root->children.size();i++){
   cout << root->children[i]->data << " , ";
   }
   cout << endl;
  for(int i=0;i<root->children.size();i++){
     printtree(root->children[i]);
   }	
}

//print by level wise//
void printtree_level_wise(TreeNode<int>* root){	
   if(root ==NULL){
    return ;
   }
   queue<TreeNode<int>*> pending;
   pending.push(root);
   while(pending.size() != 0){
     TreeNode<int>* front = pending.front();
     pending.pop();
     cout << front->data <<":";
     for(int i=0;i<front->children.size();i++){
      if(i!=front->children.size()-1){
      cout <<  front->children[i]->data << ",";
      }else{ 
        cout <<  front->children[i]->data ;
      }
      pending.push(front->children[i]);
    }
    cout << endl;
   }    
}

//count node //
int countnode(TreeNode<int>* root){
   if( root == NULL){
   return 0;
   } 
   int count = 1;
   for(int i=0;i<root->children.size();i++){
    count += countnode(root->children[i]);
   }
  return count;
}

int main(){
  TreeNode<int>* root;
  root = takeinputlevelwise();
  printtree_level_wise(root);
 return 0;
}
