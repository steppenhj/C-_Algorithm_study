#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int x_cnt[10] = {0};
    int y_cnt[10] = {0};
  //범위가 3백만이라서 o(n^2)은 안 된다.
  // map보다 일차원 배열 사용하는 게 더 빠르다고 한다
  // 이렇게 각 숫자의 개수를 세아려서 더해주고 min 써서 더 작은 쪽이 공통 개수임.
    
    for(char c : X){
        x_cnt[c - '0']++;
    }
    
    for(char c : Y){
        y_cnt[c - '0']++;
    }
    
    for(int i=9; i>=0; i--){
        int common_cnt = min(x_cnt[i], y_cnt[i]);
        
        for(int j=0; j<common_cnt; j++){
            answer += to_string(i);
        }
    }
    
    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    
    return answer;
}
