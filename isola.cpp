#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector< pii > output;
int arr[8][8];
int mark[8][8];
int my, otpyer;
int maxi=0,maxj=0,maxvalue=0;
int maxdepth =5;
int checkResult(int x, int y)
{
    int c=0;
    for(int i=x-1;i<=x+1 ; i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {

            if(arr[i][j]==0 && i>=0 && i<7 && j>=0 && j<7  && (i!=x|| j!=y))
            {
                c++;
            }
        }

    }

    return c;

}

int check(int x, int y,int depth)
{
    int res = checkResult(x,y);

    res = res-depth;

    return res;
}

int maxmove(int x, int y, int move , int depth)
{
    vector < pii> v;
    int maxv=0;
    arr[x][y]=0;
    for(int i=x-1;i<=x+1 ; i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            if(arr[i][j]==0 && i>=0 && i<7 &&j>=0 && j<7 && (i!=x|| j!=y)  )
            {
                arr[i][j]=move;
                int res = check(i,j,depth);
                if(depth<=maxdepth)
                    res += maxmove(i,j,move,depth+1);

                arr[i][j]=0;

                if(res>maxv)
                {
                    maxv=res;

                    if(depth==0)
                    {
                        maxi=i;
                        maxj=j;
                    }
                }

            }
        }

    }

    return maxv;

}


int main()
{

    int i,j,inpx,inpy , otpx,otpy;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            cin>>arr[i][j];
        }

    int turn ;
    cin>>turn;

    if(turn==1)
    {
        my=1;
        otpyer=2;
    }
    else
    {
        my=2;
        otpyer=1;
    }

    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            if(arr[i][j]==my)
            {
                inpx=i;
                inpy=j;
            }
            if(arr[i][j]==otpyer)
            {
                otpx=i;
                otpy=j;
            }

        }
    memset(mark,0,sizeof(mark));
    maxmove(inpx,inpy , my , 0);
    int aaa=maxi;
    int bbb=maxj;
    cout<<maxi<<" "<<maxj<<endl;
    maxi=0;maxj=0;
    maxmove(aaa,bbb,-1,0);
    cout<<maxi<<" "<<maxj<<endl;
    maxi=0; maxj=0;
    maxmove(otpx , otpy , -1 , 0 );
    cout<<maxi<<" "<<maxj<<endl;

    return 0;
}
