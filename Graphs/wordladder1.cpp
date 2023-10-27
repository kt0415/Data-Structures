//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>s(wordList.begin(), wordList.end());
        s.erase(startWord);    //if the start word is present in the set, please delete it
    
        q.push({startWord,1});
        while(!q.empty())
        {
            string word = q.front().first;
            int d = q.front().second;
            q.pop();
            
            if(word == targetWord)  //if the word is found in the queue, return its corresponding seq_cnt
            {
                return d;
            }
            
            for(int i=0; i<word.size(); i++)
            {
                char org = word[i]; //character we are looking to change
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(s.find(word)!=s.end())   //the modified word exists in the set
                    {
                        s.erase(word);
                        q.push({word,d+1});
                    }
                }
                word[i] = org; 
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}