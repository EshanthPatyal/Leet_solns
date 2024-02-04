class Solution {
public:
        map<pair<int,int>,vector<int>> mp;
    void thres(vector<vector<int>>& v,int i,int j,int t){
        if(abs(v[i][j]-v[i+1][j]) <= t && abs(v[i][j]-v[i][j+1]) <= t &&abs(v[i][j]-v[i-1][j]) <= t &&abs(v[i][j]-v[i][j-1]) <= t){
            if(abs(v[i-1][j]-v[i-1][j+1]) <= t && abs(v[i-1][j]-v[i-1][j-1]) <= t){
                if(abs(v[i+1][j]-v[i+1][j+1]) <= t && abs(v[i+1][j]-v[i+1][j-1]) <= t){
                    if(  (abs(v[i-1][j+1]-v[i-1][j]) <= t && abs(v[i-1][j+1]-v[i][j+1]) <= t)  &&  (abs(v[i-1][j-1]-v[i-1][j]) <= t && abs(v[i-1][j-1]-v[i][j-1]) <= t) ){
                        if(  (abs(v[i+1][j+1]-v[i+1][j]) <= t && abs(v[i+1][j+1]-v[i][j+1]) <= t)  &&  (abs(v[i+1][j-1]-v[i+1][j]) <= t && abs(v[i+1][j-1]-v[i][j-1]) <= t) ){

                        int a= v[i][j]+v[i+1][j]+v[i][j+1]+v[i-1][j]+v[i][j-1]+v[i+1][j+1]+v[i-1][j-1]+v[i+1][j-1]+v[i-1][j+1];

                        mp[{i,j}].push_back(a/9);
                        mp[{i+1,j}].push_back(a/9);
                        mp[{i,j+1}].push_back(a/9);
                        mp[{i,j-1}].push_back(a/9);
                        mp[{i-1,j}].push_back(a/9);
                        mp[{i+1,j+1}].push_back(a/9);
                        mp[{i-1,j-1}].push_back(a/9);
                        mp[{i-1,j+1}].push_back(a/9);
                        mp[{i+1,j-1}].push_back(a/9);
                        return ;
                        }
                    }
                }
            }
        }
        return ;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        for(int i=1;i<image.size()-1;i++){
            for(int j=1;j<image[i].size()-1;j++){
                    thres(image,i,j,threshold);
            }
        }
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[i].size();j++){
                if(!mp[{i,j}].empty()){
                    //cout<<i<<" "<<j<<" "<<mp[{i,j}].size()<<endl;
                    int a=0;
                    for(auto it:mp[{i,j}]){
                        a+=it;
                    }
                    a=a/mp[{i,j}].size();
                    image[i][j]=a;
                }
            }
        }
        return image;
    }
};