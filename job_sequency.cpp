#include<bits/stdc++.h>
using namespace std;
struct job{

	int profit;
	int deadline;
};
bool comp(job a,job b){
	if(a.profit<b.profit) 
		return false;
	return true;
}
int maxprofit(job a[],int n)
{
	int profit=0;
	sort(a,a+n,comp);
	vector <bool>slot(n,false);
	for(int i=0;i<n;i++)
	{
		
		for(int j=a[i].deadline-1;j>=0;j--)
		{
			if(!slot[j])
			{
				slot[j]=true;
				profit+=a[i].profit;
				break;
			}
			
		}
	}
	return profit;
}
int main(void)
{
	int n;
	cout<<"No of jobs: "<<endl;
	cin>>n;
	job a[n];
	for(int i=0;i<n;i++)
	{
		int pr,d;
		cin>>pr;
		cin>>d;
		a[i].profit=pr;
		a[i].deadline=d;
		
	}
	cout<<maxprofit(a,n);			
}
