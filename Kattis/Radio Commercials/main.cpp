#include <iostream>

using namespace std;
int maximumExtraprofit(int i, int commercials[], int maxProfit[]);
int maxOfThree(int a, int b, int c);
int main()
{
    int breakNumber, price, maxpro=0;
    cin >> breakNumber >> price;
    int commercials[breakNumber], maxProfit[breakNumber]={0};

    for(int i=0;i<breakNumber;i++){
        cin >> commercials[i];
        commercials[i] = commercials[i]-price;
    }

    maxpro = maximumExtraprofit(breakNumber-1, commercials, maxProfit);
    for (int j=0;j<breakNumber;j++){
        if (maxProfit[j]>maxpro){
            maxpro = maxProfit[j];}
    }

    cout << maxpro;
    return 0;
}

int maximumExtraprofit(int i, int commercials[], int maxProfit[]){
    if (i==0){
        return maxProfit[i] = commercials[i];
    }
    else if (maxProfit[i-1]!=0){
           //cout<< "max at i is " << i << "  " << maxOfThree(maxProfit[i-1]+commercials[i], commercials[i], maxProfit[i-1])<<endl;
            return maxProfit[i] = max(maxProfit[i-1]+commercials[i], commercials[i]);
    }
    else{
        int tempProfit;
        tempProfit = maximumExtraprofit(i-1, commercials, maxProfit);
        maxProfit[i] = max(tempProfit+commercials[i], commercials[i]);
        //<<maxProfit[i] << " " << tempProfit << " " << commercials[i] << " " <<  tempProfit+commercials[i]<<endl;
        //cout<< "max at i is " << i << "  " << max(maxProfit[i-1]+commercials[i], commercials[i])<<endl;
        return maxProfit[i];

    }
}

int maxOfThree(int a, int b, int c){
       int ret = max(a,b);
       ret = max(ret, c);
       return ret;

}

