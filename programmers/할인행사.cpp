#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> want_map;
    for(int i=0; i<want.size(); i++){
        want_map[want[i]] = number[i];
    }
    
    for(int i=0; i<=discount.size()-10; i++){
        map<string, int> want_ten;
        
        for(int j=i; j<i+10; j++){
            want_ten[discount[j]]++;
        }
        
        if(want_ten == want_map){
            answer++;
        }

      // 여기 젤 중요한 건
      // map자료구조는 == 을 사용해서 같음 판정이 가능한 것
    }
    
    return answer;
}
