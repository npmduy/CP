#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int nodeType; //neu 0 Operator, 1: Operand
    string op;
    int value;
    int level;
    Node *left,*right;
    Node(int iNodeType, string sOp, int iValue, int iLevel, Node *pleft, Node *pright){
        nodeType = iNodeType ; //neu 0 Operator, 1: Operand
        op = sOp;
        value = iValue;
        level = iLevel;
        left = pleft;
        right = pright;
    }
};

stack <Node> OprStack, NodeStack;


int getLevel(string s){
    if(s=="(")
        return 4;
    else  if(s==")")
        return 3;
    else  if(s=="*" || s=="/" || s=="%")
        return 2;
    else  if(s=="+" || s=="-")
        return 1;
    else
        return 0;
}

/*
Day dinh cua OpsStack ra lam goc
Canh phai chi ve dinh cua NodeStack
Pop NodeStack
Canh trai chi ve dinh cua NodeStack
Pop Nodestack

*/
void CreateSubTree(){   
    Node nOpr = (Node) OprStack.top();
    //Pop dinh OprStack
    OprStack.pop();
    Node *n1 = new Node(0, "", 0, 0, NULL, NULL);
    Node *n2 = new Node(0, "", 0, 0, NULL, NULL);
    *n2 = NodeStack.top(); 
    //<con tro> 111      <vung nho dong Node  (111)> (1, "", 4, 0, NULL, NULL)
    NodeStack.pop();
    *n1 = NodeStack.top();
    NodeStack.pop();
    nOpr.left = n1;
    nOpr.right = n2;
    NodeStack.push(nOpr);
    //     *
    //   /   \
    //  3     3
    // NodeStack 
    // - copy nOpr 
    // - gan vao stack

}

int duyetInfix(Node * root) {
    int calLeft, calRight;
    if(root->left != NULL)
        calLeft = duyetInfix(root->left);
    if(root->right != NULL)
        calRight = duyetInfix(root->right);
    if(root->nodeType == 0) {
        if (root->op == "+")
            return calLeft + calRight;
        else if (root->op == "-")
            return calLeft - calRight;
        else if (root->op == "*")
            return calLeft * calRight;
        else
            return calLeft / calRight;
    }
    else
        return root->value;
}

void duyetInfix2(Node * root){
    if(root->left != NULL)
        duyetInfix2(root->left);
    if(root->nodeType == 0)
        cout<< root->op;
    else
        cout<< root->value;
    if(root->right != NULL)
        duyetInfix2(root->right);
}

int toInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        res = res*10 + (int)(s[i]-'0');
    return res; 
}

int main()
{
    freopen("CONGTHUC.INP","r",stdin);
    freopen("CONGTHUC.OUT","w",stdout);

    string s;
    while (cin>>s){
        int level = getLevel(s);


        if(level == 4){//Neu la ( => day no vao OprStack
            Node node(0,s,0,level,NULL,NULL);
            OprStack.push(node);
        }
        else if (level == 0){ // cac toan hang => Node
            int val = toInt(s); 
            Node node(1,"",val,level,NULL,NULL);
            NodeStack.push(node);
        }
        else if (level == 3){ // s ==")"  //lap lai cho den khi nao dung den (
            Node node = OprStack.top();//Lay node ngay dau OprStack de kiem tra
            while(node.op != "("){
                CreateSubTree();
                if (!OprStack.empty())
                    node = OprStack.top();  
            }
            OprStack.pop();//Day node ( ra khoi OprStack
        }
        else if (level == 2 || level == 1){
            // level = 1
            if(!OprStack.empty()){
                Node node = OprStack.top(); // node.level la node dg xet khi lui ve
                while (!OprStack.empty() && node.op !=  "(" && node.level >= level){
                    CreateSubTree();
                    //bool debug = OprStack.empty();
                    if (!OprStack.empty())
                        Node node = OprStack.top();
                }
                //OprStack.pop();
            }
            Node newOp (0,s,0,level,NULL,NULL);
            OprStack.push(newOp);
        }
    }

    while(!OprStack.empty()){
        CreateSubTree();
    }
    duyetInfix2(&NodeStack.top());
    //cout << duyetInfix(&NodeStack.top()) << endl;
    return 0;
}
    