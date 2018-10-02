#include <iostream>
#include <queue>

using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
};

node* newNode(int key){
	
	node* newNode = new node();
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

void levelorder(node* root){
	
	if(root==NULL){
		cout<<"empty tree";
		return;
	}
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		node* current = q.front();
		if(current->left!=NULL){
			q.push(current->left);
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
		cout<<current->data<<" ";
		q.pop();
	}
	cout<<endl;
}

void chktraversal(int* in, int m1, int n1, int* pre, int m2, int n2, int* post, int m3, int n3,int& flag);
int search(int* in,int m1,int n1,int val);
int main(){
	
	int in[] = {4 ,8, 2, 5, 1, 6, 3,7};
	int pre[] = {1 ,2 ,4 ,8 ,5 ,3 ,6 ,7};
	int post[] = {8 ,4, 5, 2, 6,7, 3,1};
	int flag = 0;
	chktraversal(in,0,7,pre,0,7,post,0,7,flag);
	if(flag==1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
	
}

void chktraversal(int* in, int m1, int n1, int* pre, int m2, int n2, int* post, int m3, int n3,int& flag){
	// cout<<"m1 "<<m1<<" n1 "<<n1<<"    m2 "<<m2<<" n2 "<<n2<<"   m3 "<<m3<<" n3 "<<n3<<endl;   
	if(n1<m1) return;
	
	if(pre[m2] != post[n3]){
		// cout<<"chk "<<endl;
		flag=1;
		return;
	} 
	else{
		int index = search(in,m1,n1,pre[m2]);
		// cout<<"index "<<index<<endl;  
		int count=0;
		for(int i=m1;i<=n1;i++){
			if(in[i] == in[index]) break;
			count++;
		}
		// cout<<"count "<<count<<endl;
		chktraversal(in,m1,index-1,pre,m2+1,m2+count,post,m3,m3+count-1,flag);
		chktraversal(in,index+1,n1,pre,m2+count+1,n2,post,m3+count,n3-1,flag);
		
	}
}

int search(int* in,int m1,int n1,int val){
	// cout<<"m1 "<<m1<<" n1 "<<n1<<" val "<<val<<endl;
	for(int i=m1;i<=n1;i++){
		if(in[i]==val) return i;
	}
	return -1;
}