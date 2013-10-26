struct Node{
    int data;
    Node* left;
    Node* right;
};


class iterator {
    Node* current;
public:
    iterator() : current(nullptr){}

    void goNext(){ 
        if(current){
            if(current->right!=nullptr)
                current=current->right;
        }
    }

    void goPrev(){ 
        if(current){
            if(current->left!=nullptr)
                current=current->left; 
        }
    }

    int getVal(){
        return current->data;
    }

    int getDistance(iterator& src){
        unsigned int distanceA=0, distanceB=0;
        Node* a=this->current;
        Node* b=src.current;
        while(a!=nullptr){
            a=a->right;
            distanceA++;
        }
        while(b!=nullptr){
            b=b->right;
            distanceB++;
        }
        if(distanceA>distanceB)
            return distanceA-distanceB;
        else
            return distanceB-distanceA;
    }

    void setCurrent(Node* dest){
        current=dest;
    }
    friend class doublyLinkedList;
};


class doublyLinkedList {
    unsigned int size;
    Node* farLeft;
    Node* farRight;
public:
    doublyLinkedList() : farLeft(nullptr), farRight(nullptr), size(0){}
    
    void pushfarLeft(int newData){
        Node* a=new Node;
        a->data=newData;
        a->left=nullptr;
        if(!farLeft){
            farLeft=farRight=a;
            farLeft->right=nullptr;
        }
        else{
            a->right=farLeft;
            farLeft->left=a;
            farLeft=a;
        }
        size++;
    }

    void pushfarRight(int newData){
        Node* a=new Node;
        a->data=newData;
        a->right=nullptr;
        if(!farRight){
            farRight=farLeft=a;
            farRight->left=nullptr;
        }
        else{
            a->left=farRight;
            farRight->right=a;
            farRight=a;
        }
        size++;
    }

    void popfarLeft(){
        if(farLeft){
            size--;
            if(farLeft==farRight){
                delete farLeft;
                farRight=farLeft=nullptr;
            }
            else{
                farLeft=farLeft->right;
                delete farLeft->left;
            }
        }
    }

    void popfarRight(){
        if(farRight){
            size--;
            if(farRight==farLeft){
                delete farRight;
                farLeft=farRight=nullptr;
            }
            else{
                farRight=farRight->left;
                delete farRight->right;
            }
        }
    }

    ~doublyLinkedList(){
        while(!isEmpty())
            popfarLeft();
    }

    int getfarLeft(){ return farLeft->data; }
    int getfarRight(){ return farRight->data; }
    unsigned int getSize() { return size; }
    bool isEmpty() {return !size;}

    //returns an iterator pointing to the farLeft Node. Returns nullptr if farLeft does not exist
    iterator iteratorPointfarLeft(){  
        if(farLeft){
            iterator a;
            a.setCurrent(farLeft);
            return a;
        }
    }

    //returns an iterator pointing to the farRight Node. Returns nullptr if farRight does not exist
    iterator iteratorPointfarRight(){  
        if(farRight){
            iterator a;
            a.setCurrent(farRight);
            return a;
        }
    }
    //deletes the node iterator was pointing at, and moves it left, if possible. if not, goes right
    void popIteratorNode(iterator& src){ 
        if(src.current){
            size--;
            if(farLeft==farRight){
                popfarLeft();
                src.current=nullptr;
            }
            else if(src.current==farLeft){
                src.current=src.current->right;
                popfarLeft();
            }
            else if(src.current==farRight){
                src.current=src.current->left;
                popfarRight();
            }
            else{
                Node* a=src.current;
                iterator b;
                b.current=src.current;
                src.goPrev();
                b.goNext();
                src.current->right=b.current;
                b.current->left=src.current;
                delete a;
            }            
        }
    }
    //pushes a node to where the iterator is pointing. eg, pointing to '2' creates a node to the left...the new '2'
    //iterator points to the new node
    void pushIteratorNode(iterator& src, int newData){
        if(src.current==farLeft){
            pushfarLeft(newData);
            src.current=src.current->left;
        }
        else if(src.current==farRight){
            Node* a=new Node;
            a->data=newData;
            Node* leftside=src.current->left;
            leftside->right=a;
            a->left=leftside;
            src.current->left=a;
            a->right=src.current;
            farRight=src.current;
            src.current=src.current->left;
        }
        else{
            Node* a=new Node;
            a->data=newData;
            Node* leftside=src.current->left;
            leftside->right=a;
            a->left=leftside;
            src.current->left=a;
            a->right=src.current;
            src.current=src.current->left;
        }
        size++;
    }
};

