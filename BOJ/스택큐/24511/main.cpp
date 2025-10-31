#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> ;n

  vector<int> structure_types(n);
  for(int i=0; i<n; i++){
    cin >> structure_types[i];
  }
  
  vector<int> initial_values(n);
  for(int i=0; i<n; i++){
    cin >> initial_values[i];
  }
  
  deque<int> dq;
  for(int i=0; i<n; i++){
    if(structure_types[i] == 0){
      dq.push_front(initial_values[i]);
    }
  }
  
  int m;
  cin >> m;
  
  for(int i=0; i<m; i++){
    int new_element;
    cin >> new_element;
    dq.push_back(new_element);
    cout << dq.front() << " ";
    dq.pop_front();
  }
  
  return 0;
}
