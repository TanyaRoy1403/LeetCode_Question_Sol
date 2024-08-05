#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;
/*You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19*/

/*----------------------------------removeSubString function---------------------------------------*/

string removeSubString(string &InputString,string &targetPair){
    stack<char>st;
    for(auto &it:InputString){
        if(it==targetPair[1]&& !st.empty()&&st.top()==targetPair[0]){
            st.pop();   //! target pair found then pop out them
        }
        else{
            st.push(it);  //! it(currentChar) agr top ke sath mil kar target pair nhi bnaya to sidha usko push kr do
        }
    }
    //*itna krne ke baad v stack empty nhi h to  reemaining char ko pop kro stack se or reverse kr do(taki string same mile jaise input me diya h)

    string finalRemainingString="";
    while(!st.empty()){
        finalRemainingString+=st.top();
        st.pop();
    }
    reverse(finalRemainingString.begin(),finalRemainingString.end());
    return finalRemainingString;
}

int max_score(string s,int x,int y){

/*------------------------------------------------//^Greedy with stack------------------------------------------------------*/
        int total_score=0; 
        string higherPrio=x>y?"ab":"ba"; //! agr x>y high-->ab or agr x>y nhi hua to high-->ba
        string lowerPrio=higherPrio=="ab"?"ba":"ab";   //! agr high-->ab hua to lower-->ba ,nhi to agr high-->ba hua to lower-->ab

        //*first pass-->remove higherPriority wala pair i.e jiska score jada hoga x>y ya y>x
        string afterFirtpass=removeSubString(s,higherPrio);

        //&count of higherprio pair
        int pairCount=(s.length()-afterFirtpass.length())/2;

        //~calculate total score after first pass
        total_score+=pairCount*max(x,y); // kyu av maine higherpri wala ka score nikal h

        //*second pass bache hue string me(string after first pass removes) me se loweraprio wala pair nikaleyge

        string afterSecPass=removeSubString(afterFirtpass,lowerPrio);

        //& count pair of lowerPrio
         pairCount=(afterFirtpass.length()-afterSecPass.length())/2;

        //~ count total score after secPass
        total_score+=pairCount*min(x,y);
    return total_score;
/*----//*TimeComplexity:O(n)
----//*SpaceComplexity:O(n)-----------------------------------------------------------------------------------------------------------*/



/*--------------------------------//^Greedy without stack----counting-----------------------------------------------------------------*/

//we keep track of number of a and b aCount ,bCount  as soon foound pair dec there count
      int aCount=0;
      int bCount=0;
      int total_max_score=0;

        //*lets assume that ab is higestScoring pair all time
        //* if it is not so then we just swap b/w x and y
    if(x<y){
        //swap
        int temp=x;
        x=y;
        y=temp;
        // Reverse the string to maintain logic
        reverse(s.begin(), s.end());
    }
    for(auto &currChar:s){
        if(currChar=='a'){
            aCount++;
        }
        else if(currChar=='b'){
                if(aCount>0){
                    // Can form "ab", remove it and add points
                    --aCount;
                    total_max_score+=x;  //^kyu ki hmne manan h x>y
                }else{
                    bCount++;
                }
        }
        else{
            //na hi a mila or na hi b then cal score for ba pair
            total_max_score+=min(bCount,aCount)*y;

            //^reset the count of a and b(koi alg char milne pe a or b ko chor ke taki hm phele mile a ya b ko chor de)
            aCount=bCount=0;
        }
    }
    //itna krne pe v agr koi ba pair h jata h to

    total_max_score+=min(bCount,aCount)*y;
    return total_max_score;
}

int main(){
    string s="cdbcbbaaabab";
    int x=4;
    int y=5;
    cout<<max_score(s,x,y);
}