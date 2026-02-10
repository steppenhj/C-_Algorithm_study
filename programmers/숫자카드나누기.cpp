#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
// 공약수 -> gcd로 최대 공약수 함수. 이해하고 외우자

bool check(vector<int>& target, int div){
    for(int num : target){
        if(num % div == 0){
            return false;
        }
    }
    return true;
}
// 이 함수 하나로 나누어 떨어지면 false, 안 나누어지면 true 처리 가능하

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0];
    for(int i=1; i<arrayA.size(); i++){
        gcdA = gcd(gcdA, arrayA[i]);
    }
    
    int gcdB = arrayB[0];
    for(int i=1; i<arrayB.size(); i++){
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    if(check(arrayB, gcdA)){
        answer = max(answer, gcdA);
    }
    
    if(check(arrayA, gcdB)){
        answer = max(answer, gcdB);
    }
    
    return answer;
}
