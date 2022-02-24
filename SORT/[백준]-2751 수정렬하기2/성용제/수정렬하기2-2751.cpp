#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int N,arr[1000001];
int *arr2;

void merge(int l,int r)
{
    int mid = (l+r)/2;

    int i = l;
    int j = mid +1;
    int k = l;
    while(i<=mid && j <=r)
    {
        if(arr[i]<=arr[j]) arr2[k++] = arr[i++];
        else arr2[k++] = arr[j++];
    }

    int t = i > mid ? j : i;

    while(k<=r) arr2[k++] = arr[t++];

    for(int x = l;x<=r;x++) arr[x] = arr2[x];
}
void DIV(int l,int r)
{
    int mid;
    if(l<r){
        mid = (l+r)/2;
        DIV(l,mid);
        DIV(mid+1,r);
        merge(l,r);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    
    cin>>N;
    arr2 = new int[N];
    FOR(i,N) cin>>arr[i];

    DIV(0,N-1);

    FOR(i,N) cout<<arr[i]<<'\n';
}