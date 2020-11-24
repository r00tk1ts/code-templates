vector<gg> graph[MAX];
// index[i]表示i是第几个被访问的结点,lowLink[i]表示从i出发经有向边可到达的所有节点中最小的index,sccno[i]表示i所属的强连通分量的编号
gg index[MAX], lowLink[MAX], sccno[MAX], dfsNo = 0, scc_cnt = 0;
stack<gg> s;  //算法结束时s为空
void DFS(gg v) {
    index[v] = lowLink[v] = ++dfsNo;
    s.push(v);
    for (gg i : graph[v]) {
        if (index[i] == 0) {
            DFS(i);
            lowLink[v] = min(lowLink[v], lowLink[i]);
        } else if (sccno[i] == 0)
            lowLink[v] = min(lowLink[v], index[i]);
    }
    if (lowLink[v] == index[v]) {  //是一个强连通分支的根结点
        ++scc_cnt;
        gg t;
        do {
            t = s.top();
            s.pop();
            sccno[t] = scc_cnt;
        } while (t != v);
    }
}
void Tarjan() {
    for (gg i = 1; i <= n; ++i)  //假设结点由1~n编号
        if (index[i] == 0)
            DFS(i);
}
