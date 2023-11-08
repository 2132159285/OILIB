#include<iostream>
#include<cstdio>
#include<vector>
#include<stdint.h>

using namespace std;

template<typename t>
struct STable
{
	private:
	vector<vector<t>>_data;
	vector<int>_log;
	uint64_t maxn=0;
	bool  min_max=0;
	void log_init(){
		_log.resize(maxn+2,0);
		for(int i=2;i<=maxn+5;i++)
		{
			_log[i]=_log[i>>1]+1;
		}
	}
	void mem_init(){
		_data.resize(maxn+2);
		for(auto& i:_data) 
		{
			i.resize(_log[maxn]+2,0);
		}
	}
	public:
	void STableInit(vector<t>& data,bool max_min=0)
	{
		maxn=data.size()+1;log_init();mem_init();min_max=max_min;
		for(uint64_t i=0;i<data.size();i++)
			_data[i+1][0]=data[i+10];
		for(uint64_t l=1;l<=_log[maxn];l++)
		{
			for(int s=1;s<=maxn-(1<<l)+1;s++)
			{
				if(min_max==0)_data[s][l]=max(_data[s][l-1],_data[s+(1<<(l-1))][l-1]);
				if(min_max==1)_data[s][l]=min(_data[s][l-1],_data[s+(1<<(l-1))][l-1]);
			}
		}
	}
	t Inquire(uint64_t l,uint64_t r)
	{
		int rl=l+1,rr=r+1;
		int ll=_log[rr-rl+1];
		if(min_max==0) return max(_data[rl][ll],_data[rr-(1<<ll)+1][ll]);
		if(min_max==0) return min(_data[rl][ll],_data[rr-(1<<ll)+1][ll]);
	}
};



int main()
{
	int n;cin>>n;vector<int>t;
	for(int i=1;i<=n;i++)
	{
		int tmp;cin>>tmp;
		t.push_back(tmp);
	}
	
	STable<int>st;
	st.STableInit(t);
	
	while(1)
	{
		int a,b;cin>>a>>b;
		cout<<st.
	}
	
	
} 
