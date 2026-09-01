class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string node=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(node==endWord) return dis;
            for(int i=0;i<node.size();i++){
                char start=node[i];
                for(char j='a';j<='z';j++){
                    node[i]=j;
                    if(st.find(node)!=st.end()){
                        st.erase(node);
                        q.push({node,dis+1});
                    }
                }
                node[i]=start;
            }
        }
        return 0;
    }
};