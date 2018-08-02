#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *left,*right;
};
Node *newNode(int data){
	Node *a=new Node;
	a->data=data;
	a->left=a->right=NULL;
	return a;
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int mn=0;
int aa[10000];
void printVertical(Node *root);
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(aa,0,sizeof(aa));
		int n;
		cin>>n;
		mn=0;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
					break;
					case 'R':root->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		printVertical(root);
		cout<<endl;
	}
}



void verticalsum(Node* root,int hd,map<int,int>&);
void printVertical(Node *root)
{
    map<int,int> mymap;
    verticalsum(root,0,mymap);
	for(auto itr=mymap.rbegin();itr!=mymap.rend();++itr){
		cout<<itr->second<<" ";
	}
	cout<<endl;
}

void verticalsum(Node* root,int hd,map<int,int> &mymap){
	if(root==NULL) return;
	if(mymap.find(hd)!=mymap.end()) mymap.find(hd)->second = mymap.find(hd)->second+root->data;
	else{
		mymap.insert(pair<int,int> (hd,root->data));
	}
	
	verticalsum(root->left,hd+1,mymap);
	verticalsum(root->right,hd-1,mymap);
	
}