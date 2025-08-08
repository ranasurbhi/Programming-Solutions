class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string word: wordList){
            st.insert(word);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<string,int> temp=q.front();
                string oldword=temp.first;
                string x=oldword;
                int count=temp.second;
                q.pop();
                if(x==endWord) return count;
                for(int j=0;j<x.size();j++){
                    for(char c='a';c<='z';c++){
                        x[j]=c;
                        
                        if(st.count(x)){
                            q.push({x,count+1});
                            st.erase(x);
                        }
                    }
                    x=oldword;
                }
                
            }
        }
        return 0;
    }
};