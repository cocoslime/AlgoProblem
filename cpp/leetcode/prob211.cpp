//
// Created by Dongmin on 2022/01/28.
//

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <numeric>

using namespace std;
class Word {
public:
    vector<Word*> next;
    bool isLast;
    Word(bool _isLast) : isLast(_isLast) {
        next.assign(27, nullptr);
    }
};

class WordDictionary {
public:
    Word* root;
    WordDictionary() {
        root = new Word(false);
    }

    void addWord(string word) {
        Word* current = root;

        for (int i = 0; i < word.size() ; i++){
            char c = word[i];
            int cIdx = c - 'a';

            if (current->next[cIdx]){
            }
            else{
                current->next[cIdx] = new Word(i == word.size() - 1);
            }
            current = current->next[cIdx];
        }
    }

    bool search(string word) {
        queue<Word*> wordQueue;
        wordQueue.push(root);

        for (int i = 0; i < word.size() ; i++) {
            if (wordQueue.empty())
                return false;

            queue<Word*> nextQueue;

            char c = word[i];

            while (!wordQueue.empty()) {
                Word* target = wordQueue.front();
                wordQueue.pop();

                if (c == '.'){
                    for (auto ne : target->next){
                        if (ne)
                            nextQueue.push(ne);
                    }
                } else{
                    int cIdx = c - 'a';
                    if (target->next[cIdx])
                        nextQueue.push(target->next[cIdx]);
                }
            }

            while (!nextQueue.empty()) {
                wordQueue.push(nextQueue.front());
                nextQueue.pop();
            }
        }

        while (!wordQueue.empty()) {
            Word* target = wordQueue.front();
            wordQueue.pop();

            if (target->isLast)
                return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    WordDictionary* obj = new WordDictionary();
    obj->addWord("abc");
    bool param_2 = obj->search("a");
    cout << param_2 << endl;
    return 0;
}