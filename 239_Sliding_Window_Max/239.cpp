class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // this solution fails when we have such test case:
        // nums = {100000,99999,99998,99997,...,1}, k = 10000
        if(nums.empty()) return vector<int>();
        vector<int> ret(nums.size()-k+1,INT_MIN);
        int max = INT_MIN; int maxidx = 0;
        for(int i = 0; i < k; i++){
            if(nums[i] > max){
                max = nums[i];
                maxidx = i;
            }
        }
        for(int i = 0; i < nums.size()-k+1; i++){
            if(i <= maxidx){
                if(nums[i+k-1] > max){
                    max = nums[i+k-1];
                    maxidx = i;
                    ret[i] = max;
                }else ret[i] = max;
            }else{
                max = nums[i]; maxidx = i;
                for(int j = i; j < i+k; j++){
                    if(nums[j] > max){
                        max = nums[j];
                        maxidx = j;
                    }
                }
                ret[i] = max;
            }
        }
        return ret;
    }
};
/* a better solution using monotonic queue
class Monoqueue
{
    deque<pair<int, int>> m_deque;
    public:
        void push(int val)
        {
            int count = 0;
            while(!m_deque.empty() && m_deque.back().first < val)
            {
                count += m_deque.back().second + 1;
                m_deque.pop_back();
            }
            m_deque.push_back(make_pair(val, count));
        };
        int max()
        {
            return m_deque.front().first;
        }
        void pop ()
        {
            if (m_deque.front().second > 0)
            {
                m_deque.front().second --;
                return;
            }
            m_deque.pop_front();
        }
};

class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        if (nums.empty())
            return results;
        Monoqueue mq;
        size_t i = 0;
        for (;i < k; ++i) //push first K ints;
        {
            mq.push(nums[i]);
        }
        for (; i < nums.size(); ++i)
        {
            results.push_back(mq.max()); // report the current max in queue;
            mq.pop();                    // pop first element in queue;
            mq.push(nums[i]);            // push a new element to queue;
        }
        results.push_back(mq.max());
        return results;
    }
};
*/