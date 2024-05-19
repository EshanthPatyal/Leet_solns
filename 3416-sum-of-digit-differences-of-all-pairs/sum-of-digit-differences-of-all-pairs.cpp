class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long sum=0;
        bool flag=true;
        while(flag){
            vector<int> v(10,0);
            for(int i=0;i<nums.size();i++){
                v[nums[i]%10]++;
                //cout<<nums[i]%10<<endl;
            }
            for(int i=0;i<10;i++){
                for(int j=i+1;j<10;j++){
                    long long a=0;
                    a=v[j]*v[i];
                    sum+=a;
                    //cout<<i<<" "<<j<<" "<<a<<endl;

                }
            }
            if(nums[0]<10){
                flag=false;
            }

            for(int i=0;i<nums.size();i++){
                nums[i]/=10;
            }

        }
        return sum;
    }
};