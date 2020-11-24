vector<gg> graph[MAX];
// index[i]��ʾi�ǵڼ��������ʵĽ��,lowLink[i]��ʾ��i����������߿ɵ�������нڵ�����С��index,sccno[i]��ʾi������ǿ��ͨ�����ı��
gg index[MAX], lowLink[MAX], sccno[MAX], dfsNo = 0, scc_cnt = 0;
stack<gg> s;  //�㷨����ʱsΪ��
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
    if (lowLink[v] == index[v]) {  //��һ��ǿ��ͨ��֧�ĸ����
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
    for (gg i = 1; i <= n; ++i)  //��������1~n���
        if (index[i] == 0)
            DFS(i);
}
