#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class checksort{
	private:
	
		queue<int> q2;
		stack<int> s;
		
	public:
	
		bool chkElement(queue<int> &q1){
			int simElement = 1;
			
			while(!q1.empty()){
				if(q1.front() == simElement){
					// cout<<"chk1"<<endl;
					q2.push(q1.front());
					q1.pop();
					simElement++;
				}
				else if(!s.empty() && s.top() == simElement){
					// cout<<"chk2"<<endl;
					q2.push(s.top());
					s.pop();
					simElement++;
				}
				else{
					// cout<<"chk4"<<endl;
					while(!q1.empty() && q1.front()!=simElement){
						// cout<<"chk3"<<endl;
						int x = q1.front();
						if(s.empty() || x<s.top()){
							s.push(x);
						}
						else if(x>s.top()){
							return false;
						}	
						q1.pop();
					}
				}
			}
			
			while(!s.empty()){
				q2.push(s.top());
				s.pop();
			}
			
			// while(!q2.empty()){
				// cout<<q2.front()<<" ";
				// q2.pop();
			// }
			// cout<<endl;
			
			return true;
		}
};



int main(){
	queue<int> q1;
	
	q1.push(6);
	q1.push(5);
	q1.push(4);
	q1.push(1);
	q1.push(3);
	q1.push(2);
	
	checksort* obj = new checksort();
	if(obj->chkElement(q1)) cout<<"YES";
	else cout<<"NO";
	
	return 0;
}