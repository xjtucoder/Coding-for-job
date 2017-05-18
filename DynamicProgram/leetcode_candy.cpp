/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * 
 * Each child must have at least one candy.
 * 
 * Children with a higher rating get more candies than their neighbors.
 * 
 * What is the minimum candies you must give?
 * 
 * */
class Solution {
public:
    int candy(vector<int> &ratings) {
        //题意：N个孩子站成一排，每个孩子分配一个分值。给这些孩子派发糖果，满足如下要求：
        //每个孩子至少一个
        //分值更高的孩子比他的相邻位的孩子获得更多的糖果
        //求至少分发多少糖果？
        int len=ratings.size();
        if(len==1) return 1;
         
        int sum=0;
        vector<int> v(len,1);//初始将每个孩子的糖果数都设为1
         
        //从左向右扫描，保证一个方向上分数更大的糖果更多
        for(int i=1;i<len;i++){
            if(ratings[i] > ratings[i-1])
                v[i]=v[i-1]+1;
        }
        //从右向左扫描，保证另一个方向上分数更大的糖果更多
        for(int i=len-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1])
                v[i]=v[i+1]+1;
        }
         
        for(int i=0;i<len;i++){
            sum+=v[i];
        }
        return sum;
    }
};
