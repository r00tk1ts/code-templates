void insertEdge(gg from, gg to, gg cap, gg cost) {  //�����
    graph[from].push_back(edges.size());
    edges.push_back(Edge(from, to, cap, 0, cost));
    graph[to].push_back(edges.size());
    edges.push_back(Edge(to, from, 0, 0, -cost));
}
bool BellmanFord(gg s, gg t, gg& flow, long long& cost) {  //������㷨,sΪԴ��,tΪ���
    gg a[MAXV] = {0}, p[MAXV] = {0},
       dis[MAXV] = {0};  // a�����ʾԴ�㵽���a[i]�Ĳ���,p�����ʾ���·���ϵ�����p[i]�ı���edges�����е����
    fill(dis, dis + MAXV, INF);
    bool inQueue[MAXV] = {false};
    dis[s] = 0;
    inQueue[s] = true;
    a[s] = INF;  //���Ĳ�����Ϊ�����
    queue<gg> q;
    q.push(s);
    while (!q.empty()) {  //������ȱ������Ҵ�Դ�㵽���������·
        gg u = q.front();
        q.pop();
        inQueue[u] = false;
        for (gg i : graph[u]) {  //������xΪ���ı�
            Edge& e = edges[i];
            if (e.cap > e.flow && dis[e.to] > dis[u] + e.cost) {  //��ǰ�ߵ��յ�Ĳ���Ϊ0��������������
                dis[e.to] = dis[u] + e.cost;
                p[e.to] = i;                          //���µ�����յ�ıߵı��
                a[e.to] = min(a[u], e.cap - e.flow);  //����Դ�㵽���յ�Ĳ���
                if (!inQueue[e.to]) {
                    inQueue[e.to] = true;
                    q.push(e.to);  //ѹ�����
                }
            }
        }
    }
    if (dis[t] == INF)
        return false;
    flow += a[t];
    cost += dis[t] * 1ll * a[t];
    for (gg u = t; u != s; u = edges[p[u]].from) {  //�ӻ����ǰ��������·��������ÿ������·������
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
}
//��Ҫ��֤��ʼ������û�и�Ȩ��
pair<gg, long long> MinCostMaxFlow(gg s, gg t) {
    gg flow = 0;
    long long cost = 0;
    while (BellmanFord(s, t, flow, cost))
        ;
    return {flow, cost};
}
