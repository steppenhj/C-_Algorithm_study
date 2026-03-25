#include <string>
#include <vector>

using namespace std;

vector<string> dictionary;
string vowels = "AEIOU";

// 이 dfs 함수가 핵심이다
// dfs(A) -> dfs(AA) -> .. -> dfs(AAAAA) -> 
// returen 되어 dfs(AAAAE) -> ...

void dfs(string current_word){
    if(current_word.length() > 5) return; //이게 젤 중요하고 처음 본 패턴
    
    if(current_word != ""){
        dictionary.push_back(current_word);
    }
    
    for(int i=0; i<5; i++){
        dfs(current_word + vowels[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs("");
    
    for(int i=0; i<dictionary.size(); i++){
        if(dictionary[i] == word){
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}
