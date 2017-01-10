class TrieNode {
  public:
    TrieNode() : next_(vector<TrieNode*>(26, NULL)), end_(false) { }
    vector<TrieNode*> next_;
	bool end_;
};

class Trie {
  public:
    Trie() : root_(new TrieNode()) { }

    TrieNode* get_root() {
	    return root_;
	}

	void add_word_list(vector<string> words) {
	    for (string word : words) add_word(word);
	}

    void add_word(string word) {
	    TrieNode* cur = root_;
	    for (int i = 0; i < word.size(); ++i) {
		    if (cur->next_[word[i]-'a']==NULL) {
			    cur->next_[word[i]-'a'] = new TrieNode();
			}
			cur = cur->next_[word[i]-'a'];
		}
		cur->end_ = true;
	}

  private:
    TrieNode* root_;
};

class Solution {
public:
    void find_words(int i , int j, vector<vector<char> >& board, TrieNode* cur, set<string>& result, string str) {
	    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j]==' ') return;
		if (cur->next_[board[i][j] - 'a']!=NULL) {
		    cur = cur->next_[board[i][j] - 'a'];
		    str += board[i][j];
			char tmp = board[i][j];
			board[i][j] = ' ';
			if (cur->end_) result.insert(str);
			find_words(i+1, j, board, cur, result, str);
			find_words(i-1, j, board, cur, result, str);
			find_words(i, j+1, board, cur, result, str);
			find_words(i, j-1, board, cur, result, str);
			board[i][j] = tmp;
		}
	}

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
       Trie* trie = new Trie();
	   trie->add_word_list(words);
	   set<string> set_;
	   vector<string> result;
       for (int i = 0; i < board.size(); ++i) {
	       for (int j = 0; j < board[0].size(); ++j) {
		       find_words(i, j, board, trie->get_root(), set_, "");
		   }
	   }
	   for (string str : set_) result.push_back(str);
       return result;
	}
};