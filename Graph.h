#ifndef CRAPH_H
#define CRAPH_H

#include <string>
#include <Vector>
#include "Node.h"
#include "Edge.h"


using namespace std;

class Graph
{
private:
	vector<Node*> NodeVec;
	vector<Edge*> EdgeVec;
    int NodeCount;
	int EdgeCount;

	
	bool deleteNodeConnectEdge(Node *pNode); // 删除节点的出边和入边

	bool changeNodeId(Node *pNode, int new_id); //将节点id修改为指定值

    vector<Node*> getChildNodes(Node *pNode); // 返回此点未遍历的子节点的集合
    vector<Node*> getChildNdoes(vector<Node*> & NodeVec); // 遍历容器中未遍历的节点并返回其未遍历子节点的集合


    bool isIn(Node*pNode,vector<Node*> NodeVec); //判断节点是否在集合中

    bool isIn(Edge*pEdge,vector<Edge*> EdgeVec);//判断边是否在集合中

    vector<Edge*> getConnectedEdges(Node *pNode); // 获取相关联的边的集合

    Edge* getMinEdge(vector<Edge*> edge_vec); //获取未被选择的最小边


    Node* getBeginNode(); //获取入度为0的点


    void SetMinValue(Node *pNode,vector<string> &result); //设置子节点的值为最小

    void SetMaxValue(Node *pNode,vector<string> &result); //设置子节点的值为最大
public:
	
	Graph(){NodeCount = 0;EdgeCount = 0;}
	Graph(vector<Node*> &node_vec,vector<Edge*> &edge_vec); // 含参构造函数
	bool addNode(Node *pNode); //向图中添加顶点
	bool addEdge(Edge *pEdge); //向图中添加边
	bool deleteNode(Node *pNode); //将图中顶点删除
	bool deleteEdge(Edge *pEdge); //将图中边删除
    bool insert(Graph graphB); //图的合并
	void resetGraph();	//把所有顶点设为未遍历状态
	string getGraph(); //返回含有图信息的字符串

	string depthFirstTraverse(Node *pNode); //深度优先遍历
    string breadthFirstTraverse(Node *pNode); //广度优先遍历

    string primTree(Node *pNode); //普里姆生成树
    string KruskalTree(); //克鲁斯卡尔生成树

    string topsort(); //拓扑排序
    vector<Graph> connectedSubGraph(); //计算连通子图

    vector<string> Dijkstra(Node *pNode); //最短路径

    string CriticalPath(); //关键路径


    friend vector<Node*> operator +(const vector<Node*> &c1,const vector<Node*> &c2);

    friend vector<Edge*> operator +(const vector<Edge*> &c1,const vector<Edge*> &c2);

    friend int getNodeGraphIndex(Node *pNode,vector<Graph> graph_vec);
};
vector<Node*> operator +(const vector<Node*> &c1,const vector<Node*> &c2);

vector<Edge*> operator +(const vector<Edge*> &c1,const vector<Edge*> &c2);

int getNodeGraphIndex(Node *pNode,vector<Graph> graph_vec);

void deleteInVec(int index,vector<string> &string_vec);
void deleteInVec(int index,vector<Graph> &string_vec);
#endif