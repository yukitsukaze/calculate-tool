#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    while(1){
        cout<<"实验次数n"<<" "<<"正面概率p"<<" "<<"连续k次以上出现"<<"\n";
        int n;
        long double p;
        int k;
        cin>>n>>p>>k;
        long double poss[]={p,1-p};
/**********************************************************************************/
        vector<vector<long double>> dp1(2, vector<long double>(k - 1 + 10));
        dp1[0][0]=1.0l;
        for(int i=1;i<=n;i++){
            decltype(dp1) tem(2, vector<long double>(k - 1 + 10));
            for(int j=0;j<=1;j++){
                for(int r=0;r<=k-1;r++){
                    if(r==k-1){
                        tem[j^1][1]+= dp1[j][r] * poss[j ^ 1];
                        continue;
                    }
                    tem[j][r+1]+= dp1[j][r] * poss[j];
                    tem[j^1][1]+= dp1[j][r] * poss[j ^ 1];
                }
            }
            dp1=std::move(tem);
        }

        long double ans1=1.0l;
        for(int j=0;j<=1;j++){
            for(int r=0;r<=k-1;r++){
                ans1-=dp1[j][r];
            }
        }

        cout<<"n次实验内连续出现k次以上相同结果的概率总和为:"<<" "<<fixed<<setprecision(12)<<ans1<<" \n";

/***********************************************************************************************/

/**********************************************************************************/
        vector<vector<long double>> dp2(2, vector<long double>(k - 1 + 10));
        dp2[0][0]=1.0l;
        for(int i=1;i<=n;i++){
            decltype(dp2) tem(2, vector<long double>(k - 1 + 10));
            for(int j=0;j<=1;j++){
                for(int r=0;r<=k-1;r++){
                    if(r==k-1){
                        if(j==0){
                            tem[j^1][1]+= dp2[j][r] * poss[j ^ 1];
                        }else{
                            tem[j][1]+=dp2[j][r]*poss[j];
                            tem[j^1][1]+=dp2[j][r]*poss[j^1];
                        }

                        continue;
                    }
                    tem[j][r+1]+= dp2[j][r] * poss[j];
                    tem[j^1][1]+= dp2[j][r] * poss[j ^ 1];
                }
            }
            dp2=std::move(tem);
        }

        long double ans2=1.0l;
        for(int j=0;j<=1;j++){
            for(int r=0;r<=k-1;r++){
                ans2-=dp2[j][r];
            }
        }

        cout<<"n次实验内连续出现k次以上正面结果的概率总和为:"<<" "<<fixed<<setprecision(12)<<ans2<<" \n";
        /***********************************************************************************************/

    }

    getchar();

    getchar();


}