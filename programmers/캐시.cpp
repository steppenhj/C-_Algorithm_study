#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
*   기본적으로 내가 쓰는 문법과 많이 다른 스타일로 가지고 왔다.
*    코테 통과를 위해서는 아래의 문법과 익숙해질 필요가 있다고 생각한다.
*  
*     for(string city : cities)와
*    auto it = find(cacheList.begin(), cacheList.end(), city);
*     이 둘은 꼭 가지고 가자.
**/

string toUpperCase(string str){
    for(char &c : str) c = toupper(c);
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    vector<string> cacheList;
    
    for(string city : cities){
        city = toUpperCase(city);
        
        auto it = find(cacheList.begin(), cacheList.end(), city);
        
        if(it != cacheList.end()){
            answer += 1;
            cacheList.erase(it); //이게 핵심일 수도 있음.
          //찾아도 일단 삭제하고
          // 다시 추가해줌
          // 그게 LRU의 알고리즘이니
        }
        else{
            answer += 5;
            if(cacheList.size() >= cacheSize){
                cacheList.erase(cacheList.begin());
            }
        }
        cacheList.push_back(city);
        
    }
    
    
    
    return answer;
}
