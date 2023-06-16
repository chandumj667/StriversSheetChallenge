/*
    Job Sequencing Problem
    Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.


    Example 1:
    Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
    Output: 2 60
    Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
    Profit = 40 + 20 = 60

    Example 2:
    Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
    Output: 2 127
    Explanation: The  first and third job both having a deadline 2 give the highest profit.
    Profit = 100 + 27 = 127


*/


#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int dead;
    int profit;
};

bool comp(job a, job b){
    return (a.profit > b.profit);
}

void print(vector<int>arr){
    cout << "Job sequence order is : " << endl;
    for(auto i: arr){
        if(i!=-1){
            cout << i << " ";
        }
    }
}

pair<int, int> solve(vector<int> dead, vector<int> profit, int n){
    job jobs[n];
    for (int i = 0; i < n; i++){
        jobs[i].id = i+1;
        jobs[i].dead = dead[i];
        jobs[i].profit = profit[i];
    }
    sort(jobs, jobs + n, comp);
    // getting the maximum deadline as we sorted base on profit we dont know the maximum deadline which we have in the given input
    int maxi = jobs[0].dead;
    for (int i = 1; i < n; i++){
        maxi = max(maxi, jobs[i].dead);
    }
    vector<int>arr(maxi+1, -1);
    
    int cnt_jobs = 0;
    int max_profit = 0;

    for (int i = 0; i < n; i++){
        for (int j = jobs[i].dead; j >0; j--){
            if(arr[j] == -1){
                arr[j] = jobs[i].id;
                //Because we take the id in the struct and that is the original id for the original job sequence given by user 
                cnt_jobs++;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }
    print(arr);
    cout << endl;
    return {cnt_jobs, max_profit};
}

int main(){
    int n;
    cout<<"Enter the number of the jobs : ";
    cin >> n;
    vector<int> dead(n);
    vector<int> profit(n);
    cout << "Enter " << n << " deadlines :" << endl;
    for (int i = 0; i < n; i++){
        cin >> dead[i];
    }
    cout << "Enter " << n << " profits :" << endl;
    for (int i = 0; i < n; i++){
        cin >> profit[i];
    }
    pair<int, int> pr = solve(dead, profit, n);
    cout << "Number of jobs : " << pr.first << "\nans maximum profit is: " << pr.second;
    return 0;
}