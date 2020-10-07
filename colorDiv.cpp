/* 
    优先队列进行颜色分类（力扣每日一题75）
    Garker-gan
    2020-10-07
 */

//借用优先队列
class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int>myPriorityQueue;
        for(int i = 0;i < nums.size();i++)
        {
            myPriorityQueue.push(nums[i]);
        }
        for(int i = nums.size()-1;i >= 0;i--)
        {
            nums[i] = myPriorityQueue.top();
            myPriorityQueue.pop();
        }
    }
};