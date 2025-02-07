#include <bits/stdc++.h>
using namespace std;
// #define int unsigned int

  bool sort_func(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.second==b.second)
    {
        return(a.first<b.first);
    }
    else
    return (a.second > b.second);
}
class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs

    void solve_task1()
    {
        // solve task1 and save the answer in ans1
    set<unsigned int>s;
    for (int i = 0; i < n; i++)
        {
            s.insert(v[i]);
        }

    for (auto i : s )
    {
        ans1.push_back(i);
    }
    }



    void solve_task2()
    {
        // solve task2 and save the answer in ans2
        vector<pair<unsigned int,unsigned int>>t;
        for (int i = 0; i < n-1; i=i+2)
        {
            int x=v[i];
            int y=v[i+1];
            t.push_back({x,y});
        }
        sort(t.begin(), t.end(), sort_func);
        for (int i = 0; i <t.size() ; i++)
        {
            ans2.push_back(t[i].first);
        }

    }
    void solve_task3()
    {
        // solve task3 and save the answer in ans3
        vector<pair<unsigned int,unsigned int>>t;
        for (int i = 0; i < n-1; i=i+2)
        {
            int x=v[i];
            int y=v[i+1];
            t.push_back({x,y});
        }
        queue<unsigned int> q;
        for (int i = 0; i < t.size(); i++)
        {
            if(t[i].first%2 !=0)
            {
                q.push(t[i].second);
            }
            else
            {
                q.push(t[i].second);
                q.pop();
            }
        }

        while(!q.empty())
        {
            int x=q.front();
            ans3.push_back(x);
            q.pop();
        }
    }

    public:
    // create a constructor to take input
        Solution(size_t length , vector<unsigned int> vect)
    {
        n = length;
        v = vect;
        solve_task1();
        solve_task2();
        solve_task3();
    }

    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        vector<unsigned int> binFile ;
        int length = 0;
        ifstream binaryFile;
        binaryFile.open("../../" + path, ios::in | ios::binary) ;
        binaryFile.seekg(0, ios::end) ;
        length = (int)binaryFile.tellg();
        binaryFile.seekg(0, ios::beg) ;
        while (binaryFile.tellg() < length){
            unsigned int x;
            binaryFile.read((char*)&x, sizeof(unsigned int)) ;
            binFile.push_back(x);
        }
        binaryFile.close();

        // and return the answer
        if (ans1 == binFile){
            binFile.clear() ;
            return ("TASK1");
        }
        else if (ans2 == binFile && v.size()%2 == 0){
            binFile.clear() ;
            return ("TASK2");
        }
        else if (ans3 == binFile && v.size()%2 == 0){
            binFile.clear() ;
            return ("TASK3");
        }
        else{
            binFile.clear() ;
            return ("NOTFOUND");
        }
    }
};



// int main(){
//     vector<unsigned int>a{5,7,6,5,2,1,4,0,1,3};
//     string paths[]={
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
    // Intialize your solution object here

    // Make a for loop to go through paths array and call FINDMATCH function

    // return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code
#include "../../include/test2_cases.h"
