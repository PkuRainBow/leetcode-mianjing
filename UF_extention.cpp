#include<cstdio>  
  
const int maxn = 50000+10;  
  
int p[maxn]; //存父节点  
int r[maxn];//存与父节点的关系 0 同一类，1被父节点吃，2吃父节点  
  
void set(int n) //初始化  
{  
    for(int x = 1; x <= n; x++)  
    {  
        p[x] = x; //开始自己是自己的父亲节点  
        r[x] = 0;//开始自己就是自己的父亲，每一个点均独立  
    }  
}  
  
int find(int x) //找父亲节点  
{  
    if(x == p[x]) return x;  
  
    int t = p[x];  
    p[x] = find(p[x]);  
    r[x] = (r[x]+r[t])%3; //回溯由子节点与父节点的关系和父节点与根节点的关系找子节点与根节点的关系  
    return p[x];  
}  
  
void Union(int x, int y, int d)  
{  
    int fx = find(x);  
    int fy = find(y);  
  
    p[fy] = fx; //合并树 注意：被 x 吃，所以以 x 的根为父  
    r[fy] = (r[x]-r[y]+3+(d-1))%3; //对应更新与父节点的关系  
}  
  
int main()  
{  
    int n, m;  
    scanf("%d%d", &n, &m);  
    set(n);  
  
    int ans = 0;  
    int d, x, y;  
    while(m--)  
    {  
        scanf("%d%d%d", &d, &x, &y);  
  
        if(x > n || y > n || (d == 2 && x == y)) ans++; //如果节点编号大于最大编号，或者自己吃自己，说谎  
  
        else if(find(x) == find(y)) //如果原来有关系，也就是在同一棵树中，那么直接判断是否说谎  
        {  
            if(d == 1 && r[x] != r[y]) ans++; //如果 x 和 y 不属于同一类  
            if(d == 2 && (r[x]+1)%3 != r[y]) ans++; // 如果 x 没有吃 y (注意要对应Uinon(x, y)的情况，否则一路WA到死啊！！！)  
        }  
        else Union(x, y, d); //如果开始没有关系，则建立关系  
    }  
    printf("%d\n", ans);  
    return 0;  
}  