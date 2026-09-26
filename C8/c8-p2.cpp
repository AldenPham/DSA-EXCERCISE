#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <vector>


using namespace std;

void check(list<string>& res, unordered_map<string, int>& freq, string hashtag, int k) {
    for (auto pos = res.begin(); pos != res.end(); ++pos) {
        if (*pos == hashtag) {
            res.erase(pos);
            break;
        }
    }

    auto pos = res.begin();

    while (pos != res.end()) {
        if (freq[hashtag] > freq[*pos]) {
            break;
        }

        if (freq[hashtag] == freq[*pos] &&
            hashtag < *pos) {
            break;
        }

        ++pos;
    }

    res.insert(pos, hashtag);

    if (res.size() > k) {
        res.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> freq;
    list<string> res;

    for (int i = 0; i < N; i++) {
        string hashtag;
        cin >> hashtag;

        freq[hashtag]++;          
        check(res, freq, hashtag, K);
    }

    for (string x : res) {
        cout << x << " " << freq[x] << "\n";
    }
}