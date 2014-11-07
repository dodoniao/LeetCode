class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> num_id, num_count;
        for(int i=0; i<numbers.size(); i++)
        {
            num_id[numbers.at(i)] = i + 1;
            num_count[numbers.at(i)]++;
        }
        vector<int> index;
        for(int i=0; i<numbers.size(); i++)
        {
            int other = target - numbers.at(i);
            if(num_count[numbers.at(i)] == 1) num_id.erase(numbers.at(i));
            if(num_id.count(other))
            {
                index.push_back(i+1);
                index.push_back(num_id[other]);
                break;
            }
        }
        return index;
    }
};
