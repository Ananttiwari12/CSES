#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int queries;
    cin >> queries;
    vector<int> powerOfTen(19,1);
    for(int i = 1; i < 19; i++)
        powerOfTen[i] = powerOfTen[i-1] * 10;
    while(queries--)
    {
        int index;
        cin >> index;
        int digitsSoFar = 0;
        int digitsBeforeActualBlock = 0;
        int numberOfDigits;
        for(int i = 1; i <= 18; i++)
        {
            digitsSoFar += (powerOfTen[i]-powerOfTen[i-1])*i;
            if (digitsSoFar >= index)
            {
                numberOfDigits = i;
                break;
            }
            digitsBeforeActualBlock += (powerOfTen[i]-powerOfTen[i-1])*i;
        }
        int smallestValue = powerOfTen[numberOfDigits-1];
        int largestValue = powerOfTen[numberOfDigits]-1;
        int bestValue = 0;
        int startingPositionOfBestValue;
        while (smallestValue <= largestValue)
        {
            int actualValue = (smallestValue + largestValue)/2;
            int startingPositionOfActualValue = 
                digitsBeforeActualBlock + 1 +
                (actualValue - powerOfTen[numberOfDigits-1]) * numberOfDigits;
            if (startingPositionOfActualValue <= index)
            {
                if (actualValue > bestValue)
                {
                    bestValue = actualValue;
                    startingPositionOfBestValue = startingPositionOfActualValue;
                }
                smallestValue = actualValue + 1;
            }
            else
                largestValue = actualValue - 1;
        }
        string number = to_string(bestValue);
        cout << number[index-startingPositionOfBestValue] << endl; 
    }

    






    
    return 0;
}