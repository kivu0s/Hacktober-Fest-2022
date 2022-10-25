#include<iostream>
#include<stdio.h>
using namespace std;

void insertionSort(int a[], int n)
{
    int i, t, j;
    for (i = 0; i < n-1; i++)
    {
        t = a[i+1];
        j = i;
        while (j>= 0 && a[j] > t)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
        int k;
	    cout<<"\nAfter "<< i+1<<" pass the array is: "<<endl;
	    for(k=0;k<n;k++)
	    {
		   cout<<a[k]<<" ";
	    }
    }
}
void display(int a[],int n)
{
 cout<<"\nThe sorted array is:"<<endl;	
 for(int i=0;i<n;i++)
 {
    cout<<a[i]<<endl;
 }
}
int main()
{
    int i,n,a[50];
    cout<<"Size of array:"<<" ";
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
    insertionSort(a, n);
    display(a, n);
    return 0;
}
