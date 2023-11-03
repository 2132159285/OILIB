#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<long long>cmp_next(string val)
{
	vector<long long>next(val.length(),0);
	long long head_size=0;
	for(int i=1;i<next.size();)
	{
		//如果刚好能够和前缀拼接 
		if(val[i]==val[head_size])
		{
			head_size++;
			next[i]=head_size;
			i++;
		}
		//如果当前不能和前缀拼接 
		else
		{
			//前缀为零 
			if(head_size==0) 
				next[i]=0,i++;
			//查询前缀 
			else
				head_size=next[head_size-1];
		}
	}
	return next;
}
long long kmp_search(string a,string b)
{
	if(b.length()>a.length()) return -1;
	auto next=cmp_next(b);
	long long ai=0,bi=0;
	while(ai<a.length())
	{
		//如果刚好能够和前缀拼接 
		if(a[ai]==b[bi]) ai++,bi++;
		//如果当前不能和前缀拼接 
		else
		{
			//尝试和前缀匹配 
			if(bi>0) bi=next[bi-1];
			//第一个就没匹配 
			else ai++;	
		}
		//匹配完成 
		if(bi==b.length()) return ai-bi;
	}
	return -1;
} 

int main()
{
	string  a,b;cin>>a>>b;
	cout<<kmp_search(a,b)<<endl;
} 
