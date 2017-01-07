#ifndef EDGE_H
#define EDGE_H


class Edge
{

	int Id;
	int NodeAId;
	int NodeBId;
	int Value;
    bool isVisited;
public:
	Edge(int a_id, int b_id,int value = 0):NodeAId(a_id),NodeBId(b_id),Id(-1),Value
			(value),isVisited(false){}
    int getId(){ return Id;}
    void setId(int id){ Id = id;}
    int getNodeAId(){ return NodeAId;}
    void setNodeAId(int node_aid){ NodeAId = node_aid;}
    int getNodeBId(){ return NodeBId;}
    void setNodeBId(int node_bid){ NodeBId = node_bid;}
    int getValue(){ return Value;}
    void setValue(int value){ Value = value;}
    bool getIsVisited(){ return isVisited;}
    void setIsVisited(bool is_visited){ isVisited = is_visited;}
	
};

#endif