
#include <bits/stdc++.h>
using namespace std;


class Solution {
    // 1. Keep the structure inside or just above the class
    struct meeting {
        int start;
        int end;
        int meetingNumber;
    };

    // 2. MUST be static to be used in sort() without an object instance
    static bool MeetingComparator(meeting meet1, meeting meet2) {
        if (meet1.end < meet2.end) return true;
        if (meet1.end > meet2.end) return false;
        return meet1.start < meet2.start;
    }

public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<meeting> meetingSqn(n);

        for (int i = 0; i < n; i++) {
            meetingSqn[i] = {start[i], end[i], i + 1};
        }

        sort(meetingSqn.begin(), meetingSqn.end(), MeetingComparator);

        int timer = -1; // Start at -1 to allow meetings starting at 0
        int count = 0;

        for (auto& meets : meetingSqn) {
            // Check if start time is STRICTLY GREATER than previous end time
            if (meets.start > timer) {
                count++;
                timer = meets.end;
            }
        }
        return count;
    }
};



int main() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    Solution sol;
    cout << sol.maxMeetings(start, end) << endl;

    return 0;
}
