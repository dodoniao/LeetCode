class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        
        const int SIZE = 256;
        int visit[SIZE];
        for(int index=0; index<SIZE; index++) visit[index] = -1;
        visit[s.at(0)] = 0;
        
        int len_cur = 1, len_max = 1;
        int last_start = 0;
        
        for(int index=1; index<s.size(); index++)
        {
            if(visit[s.at(index)] == -1) len_cur++;
            else
            {
                if(last_start <= visit[s.at(index)])
                {
                    len_cur = index - visit[s.at(index)];
                    last_start = visit[s.at(index)] + 1;
                }
                else len_cur++;
            }
            visit[s.at(index)] = index;
            if(len_cur > len_max) len_max = len_cur;
        }
        
        return len_max;
    }
};
