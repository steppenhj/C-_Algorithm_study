#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    
    for(int i=2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    set<int> unique_nums;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        string temp = "";
        for(int i=0; i<numbers.size(); i++){
            temp += numbers[i];
            unique_nums.insert(stoi(temp));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    // 다른 것보다 이 next_permutationㅇㅣ 지린다. 이게 숫자를 섞어주는 거라고 한다. 처음본다.
  //dfs안 쓰고 이걸 쓰면 되고
  // do while 오랜만ㅇ ㅔ 쓰는 것 같다.
  
    for(int num : unique_nums){
        if(isPrime(num)) answer++;
    }
    
    return answer;
}
