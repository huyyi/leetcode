// 861. 二分图的最大匹配
// https://www.acwing.com/problem/content/863/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e5+10;
int h[M], e[M], ne[M], idx;
int n1, n2, m;
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x)
{
    //遍历自己喜欢的女孩
    for(int i = h[x] ; i != -1 ;i = ne[i])
    {
        int j = e[i];
        if(!st[j])//如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[j] = true;//那x就预定这个女孩了
            //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功,更新match
            if(!match[j]||find(match[j]))
            {
                match[j] = x;
                return true;
            }

        }
    }
    //自己中意的全部都被预定了。配对失败。
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    int a, b;
    while (m --) {
        cin >> a >> b;
        add(a, b);
    }
    int cnt = 0;
    for (int i = 1; i <= n1; i ++) {
        memset(st, false, sizeof st);
        if (find(i)) cnt ++;
    }
    cout << cnt << endl;
}
