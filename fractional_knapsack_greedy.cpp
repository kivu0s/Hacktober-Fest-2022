#include<bits/stdc++.h>
using namespace std;
struct item{
	int price,weight;
};
bool comp(item a,item b){
	if(a.price/a.weight<b.price/b.weight) return false;
	return true;
}
void merge(item a[],int l,int m,int r){
	item a1[m-l+1];
	item a2[r-m];
	int k=0;
	for(int i=0;i<=m-l;i++)
		a1[i]=a[i+l];//left sub array
	//k=0;
	//show(a1,)
	for(int i=0;i<r-m;i++)
		a2[i]=a[i+m+1];//right sub array
	int j=0,o=0;//j=first index of left, o=first index of right	`
	k=l;//first index of main array
//	show(a2,0,m-l);
	while(j<m-l+1 && o<r-m){
		if(a1[j].price/a1[j].weight>=a2[o].price/a2[o].weight)//checks  eles of left n right array
			a[k]=a2[o++];//the smaller one is inserted in main array
		else
			a[k]=a1[j++];
		k++;
	}
	while(j<=m-l){//when no eles left in right array then eles of left arr inserted in main arr
		a[k]=a1[j];
		k++;
		j++;
	}
		
	while(o<r-m){//when no eles left in left array then eles of right arr inserted in main arr
		a[k]=a2[o];
		k++;
		o++;
	}
		
//	show(a,l,r+1);	
}
void merge_sort(item a[],int l,int n){
	//int r=n-1;
	if(l>=n)
		return;
	int m=l+(n-l)/2;
	merge_sort(a,l,m);
	merge_sort(a,m+1,n);
	merge(a,l,m,n);
}
double m_profit(item a[],int n,int c)
{
	double profit=0.0;
	merge_sort(a,0,n-1);
	int i=0;
	while(c>0)
	{
	//	cout<<a[i].weight<<" "<<a[i].price<<endl;
		if(c>=a[i].weight)
		{
			profit+= a[i].price;
			c-=a[i].weight;
		}
		else
		{
			profit+=c*((double)a[i].price/a[i].weight);
			c=0;
			break;
		}
		i++;
	}
	return profit;
}

int main(void)
{
	int n_item,c;
	cout<<"No of items: "<<endl;
	cin>>n_item;
	cout<<"Capacity:"<<endl;
	cin>>c;
	item a[n_item];
	for(int i=0;i<n_item;i++)
	{
		int p,w;
		cout<<"Price and weight"<<endl;
		cin>>p>>w;
		a[i].price=p;
		a[i].weight=w;
		
	}
	cout<<m_profit(a,n_item,c);	
		
}

/*No of items:
7
Capacity:
15
Price and weight
10 2
Price and weight
5 3
Price and weight
15 5
Price and weight
7 7
Price and weight
6 1
Price and weight
18 4
Price and weight
3 1
27*/
