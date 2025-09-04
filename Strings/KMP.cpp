vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> pi = prefix_function(pattern);
    vector<int> positions;

    int j = 0; 
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            positions.push_back(i - m + 1); 
            j = pi[j - 1];
        }
    }

    return positions;
}