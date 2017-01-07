#include <vector>
//#include <iterator>
#include "Graph.h"

//#include <iostream>
using namespace std;

// 含参构造函数
Graph::Graph(vector<Node *> &node_vec, vector<Edge *> &edge_vec)
{
    NodeVec = node_vec;
    EdgeVec = edge_vec;
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        NodeVec[i]->setId(i);
    }
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        EdgeVec[i]->setId(i);
    }
    NodeCount = NodeVec.size();
    EdgeCount = EdgeVec.size();
}

//向图中添加顶点
bool Graph::addNode(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;
    }
    pNode->setId(NodeCount);
    NodeVec.push_back(pNode);
    NodeCount++;
    return true;
}

//向图中添加边
bool Graph::addEdge(Edge *pEdge)
{
    if (pEdge == NULL)
    {
        return false;
    }
    pEdge->setId(EdgeCount);
    EdgeVec.push_back(pEdge);
    EdgeCount++;
    return true;
}

//将图中顶点删除
bool Graph::deleteNode(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;
    }
    // 创建指向此节点的迭代器
    vector<Node *>::iterator Node_iter = NodeVec.begin();
    advance(Node_iter, pNode->getId());
    // 删除此节点的入边和出边
    deleteNodeConnectEdge(pNode);
    NodeVec.erase(Node_iter);
    pNode->setId(-1);
    pNode->setIsVisited(false);
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        if (NodeVec[i]->getId() != i)
        {
            changeNodeId(NodeVec[i], i);
        }

    }
    return true;
}


//将图中边删除
bool Graph::deleteEdge(Edge *pEdge)
{
    if (pEdge == NULL)
    {
        return false;
    }
    vector<Edge *>::iterator Edge_iter = EdgeVec.begin();
    advance(Edge_iter, pEdge->getId());
    EdgeVec.erase(Edge_iter);
    pEdge->setId(-1);
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        EdgeVec[i]->setId(i);
    }
    return true;
}

// 删除节点的出边和入边
bool Graph::deleteNodeConnectEdge(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;
    }
    int temp = 0;
    while (temp != EdgeVec.size())
    {
        if (EdgeVec[temp]->getNodeAId() == pNode->getId() || EdgeVec[temp]->getNodeBId() ==
                                                                pNode->getId())
        {
            deleteEdge(EdgeVec[temp]);
            temp = -1;
        }
        temp++;
    }
    return true;
}

//返回含有图信息的字符串
string Graph::getGraph()
{
    string GraphString = "Node: \n";
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        GraphString =
                GraphString + NodeVec[i]->getName() + "(" + to_string(NodeVec[i]->getValue()) +
                ")--" + to_string(NodeVec[i]->getIsVisited()) + " ";
    }
    GraphString += "\nEdge:\n";
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        GraphString = GraphString + NodeVec[EdgeVec[i]->getNodeAId()]->getName() + "-->" +
                      NodeVec[EdgeVec[i]->getNodeBId()]->getName() + "(" +
                      to_string(EdgeVec[i]->getValue()) + ")\n";
    }
    return GraphString;
}

//将节点id修改为指定值
bool Graph::changeNodeId(Node *pNode, int new_id)
{
    if (pNode == NULL)
    {
        return false;
    }
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        if (EdgeVec[i]->getNodeAId() == pNode->getId())
        {
            EdgeVec[i]->setNodeAId(new_id);
        }
        if (EdgeVec[i]->getNodeBId() == pNode->getId())
        {
            EdgeVec[i]->setNodeBId(new_id);
        }
    }
    pNode->setId(new_id);
    return true;
}
//把所有顶点设为未遍历状态
void Graph::resetGraph()
{
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        NodeVec[i]->setIsVisited(false);
    }
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        EdgeVec[i]->setIsVisited(false);
    }
}


//深度优先遍历
string Graph::depthFirstTraverse(Node *pNode)
{
    string result;
    result = result + pNode->getName() + " ";
    pNode->setIsVisited(true);
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        if(EdgeVec[i]->getNodeAId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeBId()]->getIsVisited())
        {
            result = result + depthFirstTraverse(NodeVec[EdgeVec[i]->getNodeBId()]);
        }
        else if(EdgeVec[i]->getNodeBId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeAId()]->getIsVisited())
        {
            result = result + depthFirstTraverse(NodeVec[EdgeVec[i]->getNodeAId()]);
        }
    }
    return result;
}


//广度优先遍历
string Graph::breadthFirstTraverse(Node *pNode)
{
    string result;
    vector<Node*> thisNodeVec;
    vector<Node*> nextNodeVec;

    result = result + pNode->getName() + " ";
    pNode->setIsVisited(true);

    thisNodeVec = getChildNodes(pNode); // 返回此点未遍历的子节点的集合
    while(!thisNodeVec.empty())
    {
        for(int i = 0; i < thisNodeVec.size(); ++i)
        {
            result = result + thisNodeVec[i]->getName() + " ";
        }
        nextNodeVec = getChildNdoes(thisNodeVec); // 遍历容器中未遍历的节点并返回其未遍历子节点的集合
        thisNodeVec = nextNodeVec;
        nextNodeVec.clear();
    }
    return result;
}

//普里姆生成树
string Graph::primTree(Node *pNode)
{
    Graph prim;
    vector<Edge*> thisEdgeVec;
    Node *newNode = pNode;
    pNode->setIsVisited(true);
    prim.addNode(pNode);
    while(prim.NodeVec.size() != NodeVec.size())
    {
        thisEdgeVec = thisEdgeVec + getConnectedEdges(newNode); // 获取相关联的边的集合
        Edge *minEdge = getMinEdge(thisEdgeVec); //获取未被选择的最小边
        minEdge->setIsVisited(true);
        prim.addEdge(minEdge);
        if(NodeVec[minEdge->getNodeAId()]->getIsVisited() &&
                !NodeVec[minEdge->getNodeBId()]->getIsVisited())
        {
            newNode = NodeVec[minEdge->getNodeBId()];
        }
        else
        {
            newNode = NodeVec[minEdge->getNodeAId()];
        }
        newNode->setIsVisited(true);
        prim.addNode(newNode);
    }
    return prim.getGraph();
}


//克鲁斯卡尔生成树
string Graph::KruskalTree()
{
    vector<Graph> ChildGraph;
    Edge *minEdge = getMinEdge(EdgeVec); //
    while(minEdge != NULL)
    {
        if(!NodeVec[minEdge->getNodeAId()]->getIsVisited())
        {
            if(!NodeVec[minEdge->getNodeBId()]->getIsVisited())
            {
                Graph temp;
                temp.NodeVec.push_back(NodeVec[minEdge->getNodeAId()]);
                temp.NodeVec.push_back(NodeVec[minEdge->getNodeBId()]);
                temp.EdgeVec.push_back(minEdge);
                ChildGraph.push_back(temp);
                NodeVec[minEdge->getNodeBId()]->setIsVisited(true);
                NodeVec[minEdge->getNodeAId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
            else
            {
                int GIndex = getNodeGraphIndex(NodeVec[minEdge->getNodeBId()],ChildGraph);
                ChildGraph[GIndex].NodeVec.push_back(NodeVec[minEdge->getNodeAId()]);
                ChildGraph[GIndex].EdgeVec.push_back(minEdge);
                NodeVec[minEdge->getNodeAId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
        }
        else
        {
            if(!NodeVec[minEdge->getNodeBId()]->getIsVisited())
            {
                int GIndex = getNodeGraphIndex(NodeVec[minEdge->getNodeAId()],ChildGraph);
                ChildGraph[GIndex].NodeVec.push_back(NodeVec[minEdge->getNodeBId()]);
                ChildGraph[GIndex].EdgeVec.push_back(minEdge);
                NodeVec[minEdge->getNodeBId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
            else
            {
                int GIndexA = getNodeGraphIndex(NodeVec[minEdge->getNodeAId()],ChildGraph);
                int GIndexB = getNodeGraphIndex(NodeVec[minEdge->getNodeBId()],ChildGraph);
                if(GIndexA == GIndexB)
                {
                    minEdge->setIsVisited(true);
                }
                else
                {
                    if(GIndexA > GIndexB)
                    {
                        ChildGraph[GIndexB].EdgeVec.push_back(minEdge);
                        ChildGraph[GIndexB].insert(ChildGraph[GIndexA]);
                        deleteInVec(GIndexA,ChildGraph);
                    }
                    else if(GIndexA < GIndexB)
                    {
                        ChildGraph[GIndexA].EdgeVec.push_back(minEdge);
                        ChildGraph[GIndexA].insert(ChildGraph[GIndexB]);
                        deleteInVec(GIndexB,ChildGraph);
                    }
                }
            }
        }
        minEdge = getMinEdge(EdgeVec);
    }
    return ChildGraph[0].getGraph();
}

//计算连通子图
vector<Graph> Graph::connectedSubGraph()
{
    vector<Graph> ChildGraph;
    Edge *minEdge = getMinEdge(EdgeVec); //
    while(minEdge != NULL)
    {
        if(!NodeVec[minEdge->getNodeAId()]->getIsVisited())
        {
            if(!NodeVec[minEdge->getNodeBId()]->getIsVisited())
            {
                Graph temp;
                temp.NodeVec.push_back(NodeVec[minEdge->getNodeAId()]);
                temp.NodeVec.push_back(NodeVec[minEdge->getNodeBId()]);
                temp.EdgeVec.push_back(minEdge);
                ChildGraph.push_back(temp);
                NodeVec[minEdge->getNodeBId()]->setIsVisited(true);
                NodeVec[minEdge->getNodeAId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
            else
            {
                int GIndex = getNodeGraphIndex(NodeVec[minEdge->getNodeBId()],ChildGraph);
                ChildGraph[GIndex].NodeVec.push_back(NodeVec[minEdge->getNodeAId()]);
                ChildGraph[GIndex].EdgeVec.push_back(minEdge);
                NodeVec[minEdge->getNodeAId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
        }
        else
        {
            if(!NodeVec[minEdge->getNodeBId()]->getIsVisited())
            {
                int GIndex = getNodeGraphIndex(NodeVec[minEdge->getNodeAId()],ChildGraph);
                ChildGraph[GIndex].NodeVec.push_back(NodeVec[minEdge->getNodeBId()]);
                ChildGraph[GIndex].EdgeVec.push_back(minEdge);
                NodeVec[minEdge->getNodeBId()]->setIsVisited(true);
                minEdge->setIsVisited(true);
            }
            else
            {
                int GIndexA = getNodeGraphIndex(NodeVec[minEdge->getNodeAId()],ChildGraph);
                int GIndexB = getNodeGraphIndex(NodeVec[minEdge->getNodeBId()],ChildGraph);
                if(GIndexA == GIndexB)
                {
                    minEdge->setIsVisited(true);
                }
                else
                {
                    if(GIndexA > GIndexB)
                    {
                        ChildGraph[GIndexB].EdgeVec.push_back(minEdge);
                        ChildGraph[GIndexB].insert(ChildGraph[GIndexA]);
                        deleteInVec(GIndexA,ChildGraph);
                    }
                    else if(GIndexA < GIndexB)
                    {
                        ChildGraph[GIndexA].EdgeVec.push_back(minEdge);
                        ChildGraph[GIndexA].insert(ChildGraph[GIndexB]);
                        deleteInVec(GIndexB,ChildGraph);
                    }
                }
            }
        }
        minEdge = getMinEdge(EdgeVec);
    }
    return ChildGraph;
}

//拓扑排序
string Graph::topsort()
{
    string result;
    Node *thisNode = getBeginNode(); //获取入度为0的点
    while(thisNode != NULL)
    {
        result = result + thisNode->getName() + " ";
        deleteNode(thisNode);
        thisNode = getBeginNode();
    }
    return result;

}
//最短路径
vector<string> Graph::Dijkstra(Node *pNode)
{
    vector<string> result;
    vector<Node*> thisNodeVec;
    vector<Node*> nextNodeVec;

    for(int i = 0; i < NodeVec.size(); ++i)
    {
        result.push_back(pNode->getName());
    }
    pNode->setIsVisited(true);
    SetMinValue(pNode,result); //设置子节点的值
    thisNodeVec = getChildNodes(pNode); // 返回此点未遍历的子节点的集合
    while(!thisNodeVec.empty())
    {
        for(int i = 0; i < thisNodeVec.size(); ++i)
        {
            thisNodeVec[i]->setIsVisited(true);
            SetMinValue(thisNodeVec[i],result);
        }
        nextNodeVec = getChildNdoes(thisNodeVec); // 遍历容器中未遍历的节点并返回其未遍历子节点的集合
        thisNodeVec = nextNodeVec;
        nextNodeVec.clear();
    }
    return result;
}


//关键路径
string Graph::CriticalPath()
{
    string result0;
    vector<string> result;
    Node *thisNode = getBeginNode(); //获取入度为0的点
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        result.push_back(thisNode->getName());
    }

    while(thisNode != NULL)
    {
        SetMaxValue(thisNode,result);
        result0 = result[0];
        deleteInVec(thisNode->getId(),result);
        deleteNode(thisNode);

        thisNode = getBeginNode();
    }
    return result0;
}

//设置子节点的值为最大
void Graph::SetMaxValue(Node *pNode,vector<string> &result)
{
    vector<Edge*> edge_vec = getConnectedEdges(pNode);
    for(int i = 0; i < edge_vec.size(); ++i)
    {
        if(edge_vec[i]->getNodeBId() == pNode->getId())
        {
            if(NodeVec[edge_vec[i]->getNodeAId()]->getValue() < pNode->getValue() + edge_vec[i]->getValue())
            {
                NodeVec[edge_vec[i]->getNodeAId()]->setValue(pNode->getValue() +
                        edge_vec[i]->getValue());
                result[edge_vec[i]->getNodeAId()] = result[pNode->getId()] + "-->" +
                                               NodeVec[edge_vec[i]->getNodeAId()]->getName();
            }
            else if(NodeVec[edge_vec[i]->getNodeAId()]->getValue() == pNode->getValue() +
                                                                         edge_vec[i]->getValue())
            {
                result[edge_vec[i]->getNodeAId()] += "(" + result[pNode->getId()] +
                        "-->" +
                                                    NodeVec[edge_vec[i]->getNodeAId()
                                                    ]->getName() + ")";
            }
        }
        else
        {
            if(
               NodeVec[edge_vec[i]->getNodeBId()]->getValue() < pNode->getValue() + edge_vec[i]->getValue())
            {
                NodeVec[edge_vec[i]->getNodeBId()]->setValue(pNode->getValue() +
                                                                     edge_vec[i]->getValue());
                result[edge_vec[i]->getNodeBId()] = result[pNode->getId()] + "-->" +
                                               NodeVec[edge_vec[i]->getNodeBId()]->getName();
            }
            else if(
                    NodeVec[edge_vec[i]->getNodeBId()]->getValue() == pNode->getValue()
                                                                     + edge_vec[i]->getValue())
            {
                result[edge_vec[i]->getNodeBId()] = "(" + result[pNode->getId()] + "-->" +
                                                    NodeVec[edge_vec[i]->getNodeBId()
                                                    ]->getName() + ")";
            }
        }
    }
}

//设置子节点的值为最小
void Graph::SetMinValue(Node *pNode,vector<string> &result)
{
    vector<Edge*> edge_vec = getConnectedEdges(pNode);
    for(int i = 0; i < edge_vec.size(); ++i)
    {
        if(edge_vec[i]->getNodeBId() == pNode->getId())
        {
            if(NodeVec[edge_vec[i]->getNodeAId()]->getValue() == 0||
                NodeVec[edge_vec[i]->getNodeAId()]->getValue() > pNode->getValue() + edge_vec[i]->getValue())
            {
                NodeVec[edge_vec[i]->getNodeAId()]->setValue(pNode->getValue() +
                        edge_vec[i]->getValue());
                result[edge_vec[i]->getNodeAId()] = result[pNode->getId()] + "-->" +
                        NodeVec[edge_vec[i]->getNodeAId()]->getName();
            }

        }
        else
        {
            if(NodeVec[edge_vec[i]->getNodeBId()]->getValue() == 0||
                    NodeVec[edge_vec[i]->getNodeBId()]->getValue() > pNode->getValue() + edge_vec[i]->getValue())
            {
                NodeVec[edge_vec[i]->getNodeBId()]->setValue(pNode->getValue() +
                        edge_vec[i]->getValue());
                result[edge_vec[i]->getNodeBId()] = result[pNode->getId()] + "-->" +
                                               NodeVec[edge_vec[i]->getNodeBId()]->getName();
            }
        }
    }
}

//获取入度为0的点
Node* Graph::getBeginNode()
{
    Node * resule = NULL;
    for(int i = 0; i < NodeVec.size(); ++i)
    {
        bool temp = true;
        for(int j = 0; j < EdgeVec.size(); ++j)
        {
            if(EdgeVec[j]->getNodeBId() == NodeVec[i]->getId())
            {
                temp = false;
                break;
            }
        }
        if(temp)
        {
            resule = NodeVec[i];
            break;
        }
    }
    return resule;
}

//获取未被选择的最小边
Edge* Graph::getMinEdge(vector<Edge*> edge_vec)
{
    Edge *temp = NULL;
    for(int i = 0; i < edge_vec.size(); ++i)
    {
        if(!edge_vec[i]->getIsVisited() )
        {
            if(temp == NULL || temp->getValue() > edge_vec[i]->getValue())
            {
                temp = edge_vec[i];
            }
        }
    }
    return temp;
}

// 获取相关联的边的集合
vector<Edge*> Graph::getConnectedEdges(Node *pNode)
{
    vector<Edge*> temp;
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        if(EdgeVec[i]->getNodeAId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeBId()]->getIsVisited())
        {
            temp.push_back(EdgeVec[i]);
        }
        else if(EdgeVec[i]->getNodeBId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeAId()]->getIsVisited())
        {
            temp.push_back(EdgeVec[i]);
        }
    }
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    return temp;
}





// 返回此点未遍历的子节点的集合
vector<Node*> Graph::getChildNodes(Node *pNode)
{
    vector<Node*> temp;
    for(int i = 0; i < EdgeVec.size(); ++i)
    {
        if(EdgeVec[i]->getNodeAId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeBId()]->getIsVisited())
        {
            temp.push_back(NodeVec[EdgeVec[i]->getNodeBId()]);
        }
        else if(EdgeVec[i]->getNodeBId() == pNode->getId() && !NodeVec[EdgeVec[i]->getNodeAId()]->getIsVisited())
        {
            temp.push_back(NodeVec[EdgeVec[i]->getNodeAId()]);
        }
    }
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    return temp;
}


// 遍历容器中未遍历的节点并返回其未遍历子节点的集合
vector<Node*> Graph::getChildNdoes(vector<Node*> & node_vec)
{
    vector<Node*> temp;
    for(int i = 0; i < node_vec.size(); ++i)
    {
        if(!node_vec[i]->getIsVisited() )
        {
            node_vec[i]->setIsVisited(true);
            vector<Node*> temp2 = getChildNodes(node_vec[i]);
            for(int j = 0; j < temp2.size(); ++j)
            {
                if(!isIn(temp2[j],node_vec) && !isIn(temp2[j],temp))
                {
                    temp.push_back(temp2[j]);
                }
            }
        }
    }
    return temp;
}

//判断节点是否在集合中
bool Graph::isIn(Node*pNode,vector<Node*> node_vec)
{
    bool result = false;
    for(int i = 0; i < node_vec.size(); ++i)
    {
        if(pNode->getId() == node_vec[i]->getId())
        {
            result = true;
        }
    }
    return result;
}

//判断边是否在集合中
bool Graph::isIn(Edge*pEdge,vector<Edge*> edge_vec)
{
    bool result = false;
    for(int i = 0; i < edge_vec.size(); ++i)
    {
        if(pEdge->getId( )== edge_vec[i]->getId())
        {
            result = true;
        }
    }
    return result;
}





//容器相加运算符重载
vector<Node*> operator +(const vector<Node*> &c1,const vector<Node*> &c2)
{
    vector<Node*> temp;
    temp.insert(temp.end(),c1.begin(),c1.end());
    temp.insert(temp.end(),c2.begin(),c2.end());
    return temp;
}

vector<Edge*> operator +(const vector<Edge*> &c1,const vector<Edge*> &c2)
{
    vector<Edge*> temp;
    temp.insert(temp.end(),c1.begin(),c1.end());
    temp.insert(temp.end(),c2.begin(),c2.end());
    return temp;
}

//删除容器中的元素
void deleteInVec(int index,vector<string> &string_vec)
{
    vector<string>::iterator ite = string_vec.begin();
    advance(ite,index);
    string_vec.erase(ite);
}

void deleteInVec(int index,vector<Graph> &string_vec)
{
    vector<Graph>::iterator ite = string_vec.begin();
    advance(ite,index);
    string_vec.erase(ite);
}

int getNodeGraphIndex(Node *pNode,vector<Graph> graph_vec)
{
    int result = -1;
    for(int i = 0; i < graph_vec.size(); ++i)
    {
        for(int j = 0; j < graph_vec[i].NodeVec.size();j++)
        {
            if(pNode->getId() == graph_vec[i].NodeVec[j]->getId())
            {
                result = i;
                break;
            }
        }
    }
    return result;
}

bool Graph::insert(Graph graphB)
{
    for(int i = 0; i < graphB.NodeVec.size(); ++i)
    {
        if(!isIn(graphB.NodeVec[i],NodeVec))
        {
            NodeVec.push_back(graphB.NodeVec[i]);
        }
    }
    for(int i = 0; i < graphB.EdgeVec.size(); ++i)
    {
        if(!isIn(graphB.EdgeVec[i],EdgeVec))
        {
            EdgeVec.push_back(graphB.EdgeVec[i]);
        }
    }
    return true;
}